#if !defined(AFX_NEWOPAMP_H__18FE6D8A_87F7_4D90_9B66_BC638AD95B36__INCLUDED_)
#define AFX_NEWOPAMP_H__18FE6D8A_87F7_4D90_9B66_BC638AD95B36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewOpAmp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewOpAmp dialog

class CNewOpAmp : public CDialog
{
// Construction
public:
	CNewOpAmp(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewOpAmp)
	enum { IDD = IDD_NEW };
	CButton	m_revctrl;
	double	m_gain;
	BOOL	m_rev;
	CString	m_type;
	float	m_inpr;
	float	m_max;
	float	m_min;
	float	m_outr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewOpAmp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewOpAmp)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTYPE();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWOPAMP_H__18FE6D8A_87F7_4D90_9B66_BC638AD95B36__INCLUDED_)
