// SaveOpAmp.cpp : implementation file
//

#include "stdafx.h"
#include "OpAmp.h"
#include "SaveOpAmp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSaveOpAmp dialog


CSaveOpAmp::CSaveOpAmp(CWnd* pParent /*=NULL*/)
	: CDialog(CSaveOpAmp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSaveOpAmp)
	m_desc = _T("");
	m_name = _T("");
	//}}AFX_DATA_INIT
}


void CSaveOpAmp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSaveOpAmp)
	DDX_Text(pDX, DESC, m_desc);
	DDX_Text(pDX, NAME, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSaveOpAmp, CDialog)
	//{{AFX_MSG_MAP(CSaveOpAmp)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSaveOpAmp message handlers
