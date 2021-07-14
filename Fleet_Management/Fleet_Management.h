
// Fleet_Management.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFleetManagementApp:
// See Fleet_Management.cpp for the implementation of this class
//

class CFleetManagementApp : public CWinApp
{
public:
	CFleetManagementApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFleetManagementApp theApp;
