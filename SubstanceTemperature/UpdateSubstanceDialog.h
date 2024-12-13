#pragma once
#include "afxdialogex.h"


/*
	Dialog class invoked when user wants to update a substance
*/
class CUpdateSubstanceDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateSubstanceDialog)

public:
	CUpdateSubstanceDialog(CWnd* pParent = nullptr);
	virtual ~CUpdateSubstanceDialog();

	enum { IDD = IDD_UPDATE_SUBSTANCE_DIALOG };

	// Temperature value provided by user
	float m_measuredTemperature;

protected:

	// Method for data exchange between Dialog and View
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
};
