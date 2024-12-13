#pragma once

class CMainFrame : public CFrameWnd
{
	
protected:

	DECLARE_DYNCREATE(CMainFrame)

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = nullptr, CCreateContext* pContext = nullptr);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void OnUpdateFrameTitle(BOOL bAddToTitle) override;

	DECLARE_MESSAGE_MAP()
};


