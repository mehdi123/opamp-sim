// OpAmpView.h : interface of the COpAmpView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPAMPVIEW_H__A79873C7_526A_402D_8326_95AA9327D19F__INCLUDED_)
#define AFX_OPAMPVIEW_H__A79873C7_526A_402D_8326_95AA9327D19F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DataClasses.h"
#include "Db.h"	// Added by ClassView

class COpAmpView : public CFormView
{
protected: // create from serialization only
	COpAmpView();
	DECLARE_DYNCREATE(COpAmpView)

public:
	//{{AFX_DATA(COpAmpView)
	enum { IDD = IDD_OPAMP_FORM };
	CComboBox	m_reses;
	CString	m_gain;
	CString	m_val;
	//}}AFX_DATA

// Attributes
public:
	COpAmpDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpAmpView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	void FindString(TCHAR ch,CString &s ,int *index);
	void ResetReses();
	CDb m_db;
	void SetGain();
	void DrawOpAmp(int index);
	CAmplifier* m_ampli;
	CNewValues m_newvals;
	void CreateAmplifier();
	BOOL m_bAmpAvailable;
	void DrawAmplifier();
	virtual ~COpAmpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpAmpView)
	afx_msg void OnFileNew();
	afx_msg void OnSET();
	afx_msg void OnSelchangeReses();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OpAmpView.cpp
inline COpAmpDoc* COpAmpView::GetDocument()
   { return (COpAmpDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPAMPVIEW_H__A79873C7_526A_402D_8326_95AA9327D19F__INCLUDED_)
