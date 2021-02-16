#if !defined(AFX_SAVEOPAMP_H__FB603AEC_F847_4357_B712_9E4216795408__INCLUDED_)
#define AFX_SAVEOPAMP_H__FB603AEC_F847_4357_B712_9E4216795408__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SaveOpAmp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSaveOpAmp dialog

class CSaveOpAmp : public CDialog
{
// Construction
public:
	CSaveOpAmp(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSaveOpAmp)
	enum { IDD = IDD_SAVE };
	CString	m_desc;
	CString	m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaveOpAmp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSaveOpAmp)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVEOPAMP_H__FB603AEC_F847_4357_B712_9E4216795408__INCLUDED_)
