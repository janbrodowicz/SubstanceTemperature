// CUpdateSubstanceDialog.cpp: plik implementacji
//

#include "pch.h"
#include "SubstanceTemperature.h"
#include "afxdialogex.h"
#include "UpdateSubstanceDialog.h"


// Okno dialogowe CUpdateSubstanceDialog

IMPLEMENT_DYNAMIC(CUpdateSubstanceDialog, CDialogEx)

CUpdateSubstanceDialog::CUpdateSubstanceDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UPDATE_SUBSTANCE_DIALOG, pParent),
	m_measuredTemperature(0.0)
{

}

CUpdateSubstanceDialog::~CUpdateSubstanceDialog()
{
}

void CUpdateSubstanceDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MEASURED_TEMPERATURE, m_measuredTemperature);
}


BEGIN_MESSAGE_MAP(CUpdateSubstanceDialog, CDialogEx)
END_MESSAGE_MAP()


// Procedury obsługi komunikatów CUpdateSubstanceDialog
