#pragma once
#include "afxdialogex.h"


// Okno dialogowe CUpdateSubstanceDialog

class CUpdateSubstanceDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateSubstanceDialog)

public:
	CUpdateSubstanceDialog(CWnd* pParent = nullptr);   // konstruktor standardowy
	virtual ~CUpdateSubstanceDialog();

	enum { IDD = IDD_UPDATE_SUBSTANCE_DIALOG };

	float m_measuredTemperature;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // obsługa DDX/DDV

	DECLARE_MESSAGE_MAP()
};
