#if !defined(AFX_DB_H__A9BB7DBA_9491_4274_BB95_74A1EBD9C2F7__INCLUDED_)
#define AFX_DB_H__A9BB7DBA_9491_4274_BB95_74A1EBD9C2F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Db.h : header file
//
#include <afxdao.h>
/////////////////////////////////////////////////////////////////////////////
// CDb DAO recordset

class CDb : public CDaoRecordset
{
public:
	CDb(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDb)

// Field/Param Data
	//{{AFX_FIELD(CDb, CDaoRecordset)
	long	m_index;
	CString	m_name;
	CString	m_desc;
	double	m_Ri;
	double	m_Ro;
	double	m_gain;
	short	m_amount;
	CString	m_resistors;
	double	m_min;
	double	m_max;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDb)
	public:
	virtual CString GetDefaultDBName();		// Default database name
	virtual CString GetDefaultSQL();		// Default SQL for Recordset
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DB_H__A9BB7DBA_9491_4274_BB95_74A1EBD9C2F7__INCLUDED_)
