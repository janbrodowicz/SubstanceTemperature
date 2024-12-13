#include "pch.h"
#include "SubstanceTemperature.h"
#include "SubstanceTemperatureDoc.h"
#include "SubstanceTemperatureView.h"
#include "UpdateSubstanceDialog.h"

#include <algorithm>

#include "ValidationCheck.h"



IMPLEMENT_DYNCREATE(CSubstanceTemperatureView, CView)

BEGIN_MESSAGE_MAP(CSubstanceTemperatureView, CView)
    ON_CBN_SELCHANGE(IDD_MEASSURED_TEMP_DROPDOWN, &CSubstanceTemperatureView::OnCbnSelchangeSubstanceCombo)
    ON_CBN_SELCHANGE(IDD_SUBSTANCE_LIST_DROPDOWN, &CSubstanceTemperatureView::OnCbnSelchangeSubstanceListCombo)
    ON_CBN_SELCHANGE(IDD_INTRUMENT_ID_DROPDOWN, &CSubstanceTemperatureView::OnCbnSelchangeInstrumentIdCombo)
    ON_BN_CLICKED(IDD_ADD_BUTTON, &CSubstanceTemperatureView::OnAddSubstance)
    ON_BN_CLICKED(IDD_REMOVE_BUTTON, &CSubstanceTemperatureView::OnRemoveSubstance)
    ON_BN_CLICKED(IDD_UPDATE_BUTTON, &CSubstanceTemperatureView::OnUpdateSubstance)
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


void CSubstanceTemperatureView::OnDraw(CDC* pDC)
{
    pDC->Rectangle(m_plotRect);

    // Get data to plot
    std::vector<float> tempVector;
    std::vector<int> idVector;

    CString selectedSubstanceName;

    int selectedIndex = m_substanceForList_dropDown.GetCurSel();
    if (selectedIndex != CB_ERR)
    {   
        m_substanceForList_dropDown.GetLBText(selectedIndex, selectedSubstanceName);

        for (auto& instrument : m_instruments)
        {
            Substance* foundSubstance = instrument.findSubstance(std::string(CStringA(selectedSubstanceName)));
            if (foundSubstance != nullptr)
            {
                idVector.push_back(instrument.getId());
                tempVector.push_back(foundSubstance->getMeasuredTemp());
            }
        }
    }

    if (tempVector.size() > 1)
    {
        int width = m_plotRect.Width() - 20;
        int height = m_plotRect.Height() - 20;
        int startX = m_plotRect.left + 10;
        int startY = m_plotRect.top + 10;

        double maxTemperature = *std::max_element(tempVector.begin(), tempVector.end());
        double minTemperature = *std::min_element(tempVector.begin(), tempVector.end());

        double scaleX = (double)width / (tempVector.size() - 1);
        double scaleY = (double)height / (maxTemperature - minTemperature);

        /*CPen pen(PS_SOLID, 2, RGB(0, 0, 255));
        CPen* pOldPen = pDC->SelectObject(&pen);*/

        CPen penDot(PS_SOLID, 1, RGB(255, 0, 0));
        CBrush brushDot(RGB(255, 0, 0));
        CPen* pOldPen = pDC->SelectObject(&penDot);
        CBrush* pOldBrush = pDC->SelectObject(&brushDot);

        const int dotRadius = 4;

        for (size_t i = 0; i < tempVector.size(); ++i)
        {
            /*int x1 = startX + (i - 1) * scaleX;
            int y1 = startY + (maxTemperature - tempVector[i - 1]) * scaleY;
            int x2 = startX + i * scaleX;
            int y2 = startY + (maxTemperature - tempVector[i]) * scaleY;

            pDC->MoveTo(x1, y1);
            pDC->LineTo(x2, y2);*/

            int x = startX + i * scaleX;
            int y = startY + (maxTemperature - tempVector[i]) * scaleY;

            pDC->Ellipse(x - dotRadius, y - dotRadius, x + dotRadius, y + dotRadius);
        }

        pDC->SelectObject(pOldPen);
        pDC->SelectObject(pOldBrush);
    }
}

void CSubstanceTemperatureView::OnInitialUpdate()
{
    CView::OnInitialUpdate();

    // Static Text Fields
    m_instrumentID_text.Create(_T("Instrument ID"), WS_CHILD | WS_VISIBLE,
        CRect(10, 10, 120, 40), this, IDD_INTRUMENT_ID_TEXT);

    m_substanceName_text.Create(_T("Substance\nname"), WS_CHILD | WS_VISIBLE,
        CRect(10, 50, 120, 100), this, IDD_SUBSTANCE_NAME_TEXT);

    m_nominalTemp_text.Create(_T("Nominal temp."), WS_CHILD | WS_VISIBLE,
        CRect(10, 110, 120, 160), this, IDD_NOMINAL_TEMP_TEXT);

    m_meassuredTemp_text.Create(_T("Meassured temp."), WS_CHILD | WS_VISIBLE,
        CRect(10, 170, 120, 220), this, IDD_MEASSURED_TEMP_TEXT);

    // Input (CEdit) fields
    m_instrumentID_input.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
        CRect(150, 10, 300, 40), this, IDD_INTRUMENT_ID_INPUT);

    m_substanceName_input.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
        CRect(150, 50, 300, 100), this, IDD_SUBSTANCE_NAME_INPUT);

    m_nominalTemp_input.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
        CRect(150, 110, 300, 160), this, IDD_NOMINAL_TEMP_INPUT);

    m_meassuredTemp_input.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
        CRect(150, 170, 300, 220), this, IDD_MEASSURED_TEMP_INPUT);

    // Dropdowns 
    m_instrumentID_dropDown.Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
        CRect(330, 10, 480, 40), this, IDD_INTRUMENT_ID_DROPDOWN);

    m_substanceName_dropDown.Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
        CRect(330, 50, 480, 100), this, IDD_MEASSURED_TEMP_DROPDOWN);

    m_substanceForList_dropDown.Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
        CRect(330, 305, 480, 325), this, IDD_SUBSTANCE_LIST_DROPDOWN);

    for (const auto& substance : PredefinedSubstances)
    {
        m_substanceName_dropDown.AddString(CString(substance.getName().c_str()));
    }

    // Buttons
    m_buttonAdd.Create(_T("Add"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        CRect(330, 170, 480, 220), this, IDD_ADD_BUTTON);

    m_buttonUpdate.Create(_T("Update"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        CRect(10, 300, 120, 330), this, IDD_UPDATE_BUTTON);

    m_buttonRemove.Create(_T("Remove"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        CRect(130, 300, 240, 330), this, IDD_REMOVE_BUTTON);

    // List
    m_listSubstances.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | LBS_NOTIFY | LVS_SINGLESEL,
        CRect(10, 340, 480, 650), this, IDD_SUBSTANCES_LIST);

    m_listSubstances.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    m_listSubstances.InsertColumn(0, _T("Instrument ID"), LVCFMT_LEFT, 235);
    m_listSubstances.InsertColumn(1, _T("Measured Temp."), LVCFMT_LEFT, 235);

    // Plot area
    m_plotRect.SetRect(550, 50, 1380, 500);
}

BOOL CSubstanceTemperatureView::OnEraseBkgnd(CDC* pDC)
{
    CRect rect;
    GetClientRect(&rect);

    CBrush brush(RGB(192, 192, 192));
    pDC->FillRect(&rect, &brush);

    return TRUE;
}


void CSubstanceTemperatureView::OnAddSubstance() 
{
    bool isValid = true;

    // Checking if ID is correct
    CString intrumentIdText;
    m_instrumentID_input.GetWindowText(intrumentIdText);

    int instrumentId;
    isValid = ValidationCheck(intrumentIdText).isIdCorrect(instrumentId);

    if (!isValid)
    {
        AfxMessageBox(_T("Id is either empty or not correct!"));
        return;
    }

    // Checking if substance name is correct
    CString substanceName;
    m_substanceName_input.GetWindowText(substanceName);

    isValid = ValidationCheck(substanceName).isSubstanceNameCorrect();

    if (!isValid)
    {
        AfxMessageBox(_T("Substance name is not provided!"));
        return;
    }

    // checking if nominal temp. is correct
    CString nominalTempText;
    m_nominalTemp_input.GetWindowText(nominalTempText);

    float nominalTemp;
    isValid = ValidationCheck(nominalTempText).isTemperatureCorrect(nominalTemp);

    if (!isValid)
    {
        AfxMessageBox(_T("Nominal temperature is not correct!"));
        return;
    }

    // Checking if measured temp. is correct
    CString measuredTempText;
    m_meassuredTemp_input.GetWindowText(measuredTempText);

    float measuredTemp;
    isValid = ValidationCheck(measuredTempText).isTemperatureCorrect(measuredTemp);

    if (!isValid)
    {
        AfxMessageBox(_T("Measured temperature is not correct!"));
        return;
    }

    // Create the new Substance object
    Substance newSubstance(std::string(CStringA(substanceName)), nominalTemp, measuredTemp);

    // Updating m_substancesNames vector and populating dropdown
    bool exists = m_substancesNames.nameExists(substanceName);

    if (!exists)
    {
        m_substancesNames.addSubstanceName(substanceName);

        RefreshSubstanceListCombo();
    }
    

    // Finding instrument by provided id
    Instrument* instrument = m_instruments.getInstrumentByID(instrumentId);
    
    // Updating substance or creating new instrument
    if (instrument != nullptr) 
    {
        Substance* existingSubstance = instrument->findSubstance(std::string(CStringA(substanceName)));
        if (existingSubstance != nullptr)
        {
            CString message;
            message.Format(_T("Substance already defined for id %d. Do you want to override the measured temperature?"), instrumentId);
            int res = AfxMessageBox(message, MB_YESNO | MB_ICONQUESTION);

            if (res == IDYES)
            {
                existingSubstance->setMeasuredTemp(measuredTemp);
            }
        }
        else
        {
            instrument->addSubstance(newSubstance);
        }
    }
    else
    {
        Instrument newIntrument(instrumentId);
        newIntrument.addSubstance(newSubstance);
        m_instruments.addInstrument(newIntrument);

        RefreshInstrumentIdCombo();
    }

    RefreshSubstanceTable();

    InvalidateRect(m_plotRect, FALSE);

    UpdateWindow();
}

void CSubstanceTemperatureView::RefreshSubstanceTable() 
{
    m_listSubstances.DeleteAllItems();

    int selectedIndex = m_substanceForList_dropDown.GetCurSel();
    if (selectedIndex != CB_ERR)
    {
        CString selectedSubstanceName;
        m_substanceForList_dropDown.GetLBText(selectedIndex, selectedSubstanceName);

        for (auto& instrument : m_instruments)
        {
            Substance* foundSubstance = instrument.findSubstance(std::string(CStringA(selectedSubstanceName)));
            if (foundSubstance != nullptr)
            {
                if (std::string(CStringA(selectedSubstanceName)) == foundSubstance->getName())
                {
                    int rowIndex = m_listSubstances.GetItemCount();
                    m_listSubstances.InsertItem(rowIndex, std::to_wstring(instrument.getId()).c_str());
                    m_listSubstances.SetItemText(rowIndex, 1, std::to_wstring(foundSubstance->getMeasuredTemp()).c_str());
                }
            }
        }
    }
}

void CSubstanceTemperatureView::RefreshSubstanceListCombo()
{
    int selectedIndex = m_substanceForList_dropDown.GetCurSel();

    CString selectedItemText;
    if (selectedIndex != CB_ERR)
    {
        m_substanceForList_dropDown.GetLBText(selectedIndex, selectedItemText);
    }

    m_substanceForList_dropDown.ResetContent();

    for (const auto& substance : m_substancesNames)
    {
        if (m_substanceForList_dropDown.FindStringExact(-1, CString(substance.c_str())) == LB_ERR)
        {
            m_substanceForList_dropDown.AddString(CString(substance.c_str()));
        }

    }

    if (selectedIndex != CB_ERR)
    {
        int newIndex = m_substanceForList_dropDown.FindStringExact(-1, selectedItemText);
        if (newIndex != CB_ERR)
        {
            m_substanceForList_dropDown.SetCurSel(newIndex);
        }
    }
}

void CSubstanceTemperatureView::RefreshInstrumentIdCombo()
{
    int selectedIndex = m_instrumentID_dropDown.GetCurSel();

    CString selectedItemText;
    if (selectedIndex != CB_ERR)
    {
        m_instrumentID_dropDown.GetLBText(selectedIndex, selectedItemText);
    }

    m_instrumentID_dropDown.ResetContent();

    for (const auto& instrument : m_instruments)
    {
        int instrumentId = instrument.getId();
        CString instrumentIdText(std::to_string(instrumentId).c_str());
        if (m_instrumentID_dropDown.FindStringExact(-1, instrumentIdText) == LB_ERR)
        {
            m_instrumentID_dropDown.AddString(instrumentIdText);
        }

    }

    if (selectedIndex != CB_ERR)
    {
        int newIndex = m_instrumentID_dropDown.FindStringExact(-1, selectedItemText);
        if (newIndex != CB_ERR)
        {
            m_instrumentID_dropDown.SetCurSel(newIndex);
        }
    }
}

void CSubstanceTemperatureView::OnCbnSelchangeSubstanceCombo()
{
    int selectedIndex = m_substanceName_dropDown.GetCurSel();
    if (selectedIndex != CB_ERR)
    {
        CString selectedSubstanceName;
        m_substanceName_dropDown.GetLBText(selectedIndex, selectedSubstanceName);

        for (const auto& substance : PredefinedSubstances)
        {
            if (selectedSubstanceName == CString(substance.getName().c_str()))
            {
                m_substanceName_input.SetWindowText(CString(substance.getName().c_str()));

                CString tempStr;
                tempStr.Format(_T("%.2f"), substance.getNominalTemp());
                m_nominalTemp_input.SetWindowText(tempStr);

                break;
            }
        }
    }
}

void CSubstanceTemperatureView::OnCbnSelchangeSubstanceListCombo()
{
    RefreshSubstanceTable();

    InvalidateRect(m_plotRect, FALSE);

    UpdateWindow();
}

void CSubstanceTemperatureView::OnCbnSelchangeInstrumentIdCombo()
{
    int selectedIndex = m_instrumentID_dropDown.GetCurSel();
    if (selectedIndex != CB_ERR)
    {
        CString selectedInstrumentId;
        m_instrumentID_dropDown.GetLBText(selectedIndex, selectedInstrumentId);

        for (const auto& instrument : m_instruments)
        {
            CString tempStr;
            tempStr.Format(_T("%d"), instrument.getId());

            if (selectedInstrumentId == tempStr)
            {
                m_instrumentID_input.SetWindowText(tempStr);
                break;
            }
        }
    }
}

void CSubstanceTemperatureView::OnUpdateSubstance()
{
    CUpdateSubstanceDialog dlg;

    int instrumentId;
    CString selectedSubstanceName;

    bool elPicked = GetSubstanceListElement(instrumentId, selectedSubstanceName);

    if (!elPicked)
    {
        AfxMessageBox(_T("No list element was selected!"));
        return;
    }

    if (dlg.DoModal() == IDOK)
    {
        // Get the updated values from the dialog
        float measuredTemperature = dlg.m_measuredTemperature;

        std::string substanceNameStr = std::string(CStringA(selectedSubstanceName));

        Instrument* foundInstrument = m_instruments.getInstrumentByID(instrumentId);

        Substance* foundSubstance = foundInstrument->findSubstance(substanceNameStr);

        foundSubstance->setMeasuredTemp(measuredTemperature);
    }

    RefreshSubstanceListCombo();
    
    RefreshSubstanceTable();

    InvalidateRect(m_plotRect, FALSE);

    UpdateWindow();
}

void CSubstanceTemperatureView::OnRemoveSubstance()
{
    int instrumentId;
    CString selectedSubstanceName;

    bool elPicked = GetSubstanceListElement(instrumentId, selectedSubstanceName);

    if (!elPicked)
    {
        AfxMessageBox(_T("No list element was selected!"));
        return;
    }

    int res = AfxMessageBox(_T("Do you want to delete this measurement?"), MB_YESNO | MB_ICONQUESTION);

    if (res == IDNO)
    {
        return;
    }

    std::string substanceNameStr = std::string(CStringA(selectedSubstanceName));

    Instrument* foundInstrument = m_instruments.getInstrumentByID(instrumentId);

    foundInstrument->removeSubstance(substanceNameStr);

    Substance* foundSubstance = nullptr;

    m_instruments.removeInstrumentsWihoutSubstance();

    for (auto& instrument : m_instruments)
    {
        foundSubstance = instrument.findSubstance(substanceNameStr);

        if (foundSubstance != nullptr)
        {
            break;
        }
    }

    if (foundSubstance == nullptr)
    {
        m_substancesNames.removeSubstanceName(selectedSubstanceName);
    }

    RefreshSubstanceTable();

    RefreshSubstanceListCombo();

    RefreshInstrumentIdCombo();

    InvalidateRect(m_plotRect, FALSE);

    UpdateWindow();
}

bool CSubstanceTemperatureView::GetSubstanceListElement(int& instrumentId, CString& selectedSubstanceName)
{
    POSITION listIdx = m_listSubstances.GetFirstSelectedItemPosition();

    if (listIdx == NULL)
    {
        return false;
    }

    int selectedListItem = m_listSubstances.GetNextSelectedItem(listIdx);
    int selectedSubstanceDropdown = m_substanceForList_dropDown.GetCurSel();

    CString instrumentIdText = m_listSubstances.GetItemText(selectedListItem, 0);

    m_substanceForList_dropDown.GetLBText(selectedSubstanceDropdown, selectedSubstanceName);

    instrumentId = _ttoi(instrumentIdText);

    return true;
}

BOOL CSubstanceTemperatureView::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
    {
        CWnd* pButton = GetDlgItem(IDD_ADD_BUTTON);
        if (pButton)
        {
            pButton->SetFocus();
            pButton->SendMessage(BM_CLICK);
            return TRUE;
        }
    }

    return CView::PreTranslateMessage(pMsg);
}