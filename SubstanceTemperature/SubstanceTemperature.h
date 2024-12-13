#pragma once

#include "resource.h"


class CSubstanceTemperatureApp : public CWinApp
{
	public:
		virtual BOOL InitInstance();

		DECLARE_MESSAGE_MAP()
};

extern CSubstanceTemperatureApp theApp;
