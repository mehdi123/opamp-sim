// NewOpAmp.cpp : implementation file
//

#include "stdafx.h"
#include "OpAmp.h"
#include "NewOpAmp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewOpAmp dialog


CNewOpAmp::CNewOpAmp(CWnd* pParent /*=NULL*/)
	: CDialog(CNewOpAmp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewOpAmp)
	m_gain = 0.0;
	m_rev = FALSE;
	m_type = _T("");
	m_inpr = 0.0f;
	m_max = 0.0f;
	m_min = 0.0f;
	m_outr = 0.0f;
	//}}AFX_DATA_INIT
}


void CNewOpAmp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewOpAmp)
	DDX_Control(pDX, REVERSE, m_revctrl);
	DDX_Text(pDX, GAIN, m_gain);
	DDX_Check(pDX, REVERSE, m_rev);
	DDX_CBString(pDX, TYPE, m_type);
	DDX_Text(pDX, INPUTR, m_inpr);
	DDV_MinMaxFloat(pDX, m_inpr, 1.f, 1.e+038f);
	DDX_Text(pDX, MAX, m_max);
	DDV_MinMaxFloat(pDX, m_max, 1.f, 1.e+038f);
	DDX_Text(pDX, MIN, m_min);
	DDV_MinMaxFloat(pDX, m_min, 1.f, 1.e+038f);
	DDX_Text(pDX, OUTPUTR, m_outr);
	DDV_MinMaxFloat(pDX, m_outr, 1.f, 1.e+038f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewOpAmp, CDialog)
	//{{AFX_MSG_MAP(CNewOpAmp)
	ON_CBN_SELCHANGE(TYPE, OnSelchangeTYPE)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewOpAmp message handlers

void CNewOpAmp::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_min>=m_max)
	{
		MessageBox("min must be less than max");
		return;
	}
	if(m_inpr>m_max)
	{
		MessageBox("Input resistant must be less than or equal to max");
		return;
	}
	CDialog::OnOK();
}

BOOL CNewOpAmp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization 
	m_inpr = 1000000.0;
	m_gain = 100000.0;
	m_outr = 10.0;
	m_max = 1000000.0;
	m_min = 10.0;
	m_rev = true;
	m_type = "Inverter";
	UpdateData(FALSE);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNewOpAmp::OnSelchangeTYPE() 
{
	UpdateData();
	if(m_type.Compare("Inverter"))
		m_revctrl.EnableWindow(FALSE);
	else
		m_revctrl.EnableWindow(TRUE);
}
