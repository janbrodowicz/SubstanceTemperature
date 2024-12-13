#pragma once

#include "SubstancesResource.h"
#include "SubstanceNamesContainer.h"
#include "InstrumentsContainer.h"



class CSubstanceTemperatureView : public CView
{
protected:
	DECLARE_DYNCREATE(CSubstanceTemperatureView)

protected:
	// Static texts
	CStatic m_instrumentID_text;
	CStatic m_substanceName_text;
	CStatic m_nominalTemp_text;
	CStatic m_meassuredTemp_text;

	// Input fields
	CEdit m_instrumentID_input;
	CEdit m_substanceName_input;
	CEdit m_nominalTemp_input;
	CEdit m_meassuredTemp_input;

	// DropDowns
	CComboBox m_instrumentID_dropDown;
	CComboBox m_substanceName_dropDown;
	CComboBox m_substanceForList_dropDown;

	// Lists
	CListCtrl m_listSubstances;

	// Buttons
	CButton m_buttonAdd;
	CButton m_buttonRemove;
	CButton m_buttonUpdate;

	// Plot area
	CRect m_plotRect;

	// List of instruments and their Substances
	InstrumentsContainer m_instruments;

	// List of substances names for List DropDown
	SubstanceNamesContainer m_substancesNames;

public:
	// Dynamic app behaviour
	virtual void OnDraw(CDC* pDC);

	// Initial app view
	virtual void OnInitialUpdate();
	
protected:
	// Changing background color
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	// Making Add button react to Enter key
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	// Callbacks
	afx_msg void OnAddSubstance();
	afx_msg void OnCbnSelchangeSubstanceCombo();
	afx_msg void OnCbnSelchangeSubstanceListCombo();
	afx_msg void OnCbnSelchangeInstrumentIdCombo();
	afx_msg void OnUpdateSubstance();
	afx_msg void OnRemoveSubstance();

	// Refresh table
	void RefreshSubstanceTable();

	// Refresh substance for table dropdown
	void RefreshSubstanceListCombo();

	// Refresh instrument ids dropdown
	void RefreshInstrumentIdCombo();

	// Get instrumant id and substance name from table (on select)
	bool GetSubstanceListElement(int& instrumentId, CString& selectedSubstanceName);

	DECLARE_MESSAGE_MAP()
};

