// LoadOpAmp.cpp : implementation file
//

#include "stdafx.h"
#include "OpAmp.h"
#include "LoadOpAmp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoadOpAmp dialog


CLoadOpAmp::CLoadOpAmp(CDb *db, CWnd* pParent /*=NULL*/)
	: CDialog(CLoadOpAmp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoadOpAmp)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_db = db;
}


void CLoadOpAmp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoadOpAmp)
	DDX_Control(pDX, LIST, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoadOpAmp, CDialog)
	//{{AFX_MSG_MAP(CLoadOpAmp)
	ON_BN_CLICKED(IDOK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoadOpAmp message handlers

BOOL CLoadOpAmp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_list.InsertColumn(0, "OpAmp Name");
	m_list.InsertColumn(1, "Description");
	m_list.SetColumnWidth(0, 100);
	m_list.SetColumnWidth(1, 200);
	if(!m_db->IsEOF())
		m_db->MoveFirst();
	while(!m_db->IsEOF()){
		m_list.InsertItem(0, m_db->m_name);
		m_list.SetItemText(0, 1, m_db->m_desc);
		m_list.SetItemData(0, m_db->m_index);
		m_db->MoveNext();
	}
	return TRUE;
}


void CLoadOpAmp::OnOk() 
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if(!pos)
	{
		EndDialog(-1);
		return;
	}
	int nItem = m_list.GetNextSelectedItem(pos);
	EndDialog(m_list.GetItemData(nItem));
}

void CLoadOpAmp::OnCancel() 
{
	EndDialog(-1);
}
