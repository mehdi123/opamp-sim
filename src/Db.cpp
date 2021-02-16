// Db.cpp : implementation file
//

#include "stdafx.h"
#include "Db.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDb

IMPLEMENT_DYNAMIC(CDb, CDaoRecordset)

CDb::CDb(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDb)
	m_index = 0;
	m_name = _T("");
	m_desc = _T("");
	m_Ri = 0.0;
	m_Ro = 0.0;
	m_gain = 0.0;
	m_amount = 0;
	m_resistors = _T("");
	m_min = 0.0;
	m_max = 0.0;
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
}


CString CDb::GetDefaultDBName()
{
	return _T("X:\\OpAmp.mdb");
}

CString CDb::GetDefaultSQL()
{
	return _T("[OpAmp]");
}

void CDb::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDb)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	DFX_Long(pFX, _T("[index]"), m_index);
	DFX_Text(pFX, _T("[name]"), m_name);
	DFX_Text(pFX, _T("[desc]"), m_desc);
	DFX_Double(pFX, _T("[Ri]"), m_Ri);
	DFX_Double(pFX, _T("[Ro]"), m_Ro);
	DFX_Double(pFX, _T("[Gain]"), m_gain);
	DFX_Short(pFX, _T("[amount]"), m_amount);
	DFX_Text(pFX, _T("[resistors]"), m_resistors);
	DFX_Double(pFX, _T("[min]"), m_min);
	DFX_Double(pFX, _T("[max]"), m_max);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDb diagnostics

#ifdef _DEBUG
void CDb::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void CDb::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG
