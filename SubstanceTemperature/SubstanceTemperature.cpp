
#include "pch.h"
#include "SubstanceTemperature.h"
#include "MainFrm.h"

#include "SubstanceTemperatureDoc.h"
#include "SubstanceTemperatureView.h"


BEGIN_MESSAGE_MAP(CSubstanceTemperatureApp, CWinApp)
END_MESSAGE_MAP()

CSubstanceTemperatureApp theApp;

BOOL CSubstanceTemperatureApp::InitInstance()
{
	CWinApp::InitInstance();
	
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CSubstanceTemperatureDoc),
		RUNTIME_CLASS(CMainFrame),
		RUNTIME_CLASS(CSubstanceTemperatureView));

	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}



