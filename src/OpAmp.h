// OpAmp.h : main header file for the OPAMP application
//

#if !defined(AFX_OPAMP_H__EC71E544_12E1_40F3_942C_0920737DBE90__INCLUDED_)
#define AFX_OPAMP_H__EC71E544_12E1_40F3_942C_0920737DBE90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COpAmpApp:
// See OpAmp.cpp for the implementation of this class
//

class COpAmpApp : public CWinApp
{
public:
	COpAmpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpAmpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COpAmpApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPAMP_H__EC71E544_12E1_40F3_942C_0920737DBE90__INCLUDED_)
