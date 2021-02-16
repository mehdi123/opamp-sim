#if !defined(AFX_LOADOPAMP_H__6B41669E_344A_455A_B66D_8A7BA68493ED__INCLUDED_)
#define AFX_LOADOPAMP_H__6B41669E_344A_455A_B66D_8A7BA68493ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoadOpAmp.h : header file
//
#include "Db.h"
/////////////////////////////////////////////////////////////////////////////
// CLoadOpAmp dialog

class CLoadOpAmp : public CDialog
{
// Construction
public:
	CDb* m_db;
	CLoadOpAmp(CDb *db, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoadOpAmp)
	enum { IDD = IDD_LOAD };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoadOpAmp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoadOpAmp)
	virtual BOOL OnInitDialog();
	afx_msg void OnOk();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOADOPAMP_H__6B41669E_344A_455A_B66D_8A7BA68493ED__INCLUDED_)
