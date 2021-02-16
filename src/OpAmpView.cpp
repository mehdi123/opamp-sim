// OpAmpView.cpp : implementation of the COpAmpView class
//

#include "stdafx.h"
#include "OpAmp.h"

#include "OpAmpDoc.h"
#include "OpAmpView.h"
#include "NewOpAmp.h"
#include "SaveOpAmp.h"
#include "LoadOpAmp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpAmpView

IMPLEMENT_DYNCREATE(COpAmpView, CFormView)

BEGIN_MESSAGE_MAP(COpAmpView, CFormView)
	//{{AFX_MSG_MAP(COpAmpView)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_BN_CLICKED(SET, OnSET)
	ON_CBN_SELCHANGE(COMBO, OnSelchangeReses)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpAmpView construction/destruction

COpAmpView::COpAmpView()
	: CFormView(COpAmpView::IDD)
{
	//{{AFX_DATA_INIT(COpAmpView)
	m_gain = _T("");
	m_val = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_bAmpAvailable=FALSE;
	m_ampli = new CAmplifier;
	m_db.Open();
}

COpAmpView::~COpAmpView()
{
	if(m_ampli)
		delete m_ampli;
	if(m_db.IsOpen())
		m_db.Close();
}

void COpAmpView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpAmpView)
	DDX_Control(pDX, COMBO, m_reses);
	DDX_Text(pDX, GAIN, m_gain);
	DDX_Text(pDX, VAL, m_val);
	//}}AFX_DATA_MAP
}

BOOL COpAmpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void COpAmpView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// COpAmpView printing

BOOL COpAmpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COpAmpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COpAmpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void COpAmpView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// COpAmpView diagnostics

#ifdef _DEBUG
void COpAmpView::AssertValid() const
{
	CFormView::AssertValid();
}

void COpAmpView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

COpAmpDoc* COpAmpView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpAmpDoc)));
	return (COpAmpDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpAmpView message handlers

void COpAmpView::OnFileNew() 
{
	CNewOpAmp dlg;
	if(dlg.DoModal()!=IDOK)
		return;
	m_newvals.gain=dlg.m_gain;
	m_newvals.inpr=dlg.m_inpr;
	m_newvals.max=dlg.m_max;
	m_newvals.min=dlg.m_min;
	m_newvals.outr=dlg.m_outr;
	m_newvals.rev=dlg.m_rev;
	m_newvals.type=dlg.m_type.Compare("Inverter")==0;
	CreateAmplifier();
}

void COpAmpView::CreateAmplifier()
{
	COpAmp *op;
	int n_opamp=0;
	float r1=m_newvals.min;
	m_ampli->m_min=m_newvals.min;
	m_ampli->m_max=m_newvals.max;
	if(m_newvals.type)
		r1=m_newvals.inpr;
	m_ampli->RemoveAll();
	while(m_ampli->GetGain()<m_newvals.gain)
	{
		op=new COpAmp(r1, m_newvals.max, m_newvals.type);
		m_ampli->AddOpAmp(*op);
		r1=m_newvals.min;
		n_opamp++;
	}
	if(m_newvals.type==1 && m_newvals.rev && n_opamp%2==0)
	{
		op=new COpAmp(m_newvals.min, m_newvals.min, 1);
		m_ampli->AddOpAmp(*op);
		n_opamp++;
	}
	m_bAmpAvailable=TRUE;
	m_ampli->type=m_newvals.type;
	int cx=n_opamp*BMXNON;
	SetScrollSizes(MM_TEXT, CSize(cx, 600));
	ResetReses();
	Invalidate();
	UpdateWindow();
	DrawAmplifier();
	SetGain();
}

void COpAmpView::DrawAmplifier()
{
	if(!m_bAmpAvailable)
		return;
	COpAmp *op1;
	CDC *pDC=GetDC();
    CDC dcMemory;
	CBitmap bitmap;
	CSize size;
	CPoint pt;


	bitmap.LoadBitmap(IDB_SOURCE);
	size.cx = 47;
	size.cy = BMY;
    dcMemory.CreateCompatibleDC(pDC);
    dcMemory.SelectObject(&bitmap);
	pt=GetScrollPosition();
	pt.x=53-pt.x;
	pt.y=100-pt.y;
    pDC->BitBlt(pt.x, pt.y, size.cx,\
		 size.cy, &dcMemory, 0, 0, SRCCOPY);
	
	for(int i=0; i<m_ampli->GetCount(); i++)
	{
		op1=m_ampli->GetOpAmp(i);
		DrawOpAmp(i);
	}
	UpdateWindow();
	ReleaseDC(pDC);
}

void COpAmpView::OnDraw(CDC* pDC) 
{
	DrawAmplifier();
}

void COpAmpView::DrawOpAmp(int index)
{
	CDC *pDC=GetDC();
	CBitmap bitmap;
    CDC dcMemory;
	CSize size;
	CPoint pt;
	size.cy = BMY;
	COpAmp *op;

	if(m_ampli->type)
	{
		bitmap.LoadBitmap(IDB_INVOPAMP);
		size.cx = BMXINV;
	}
	else
	{
		bitmap.LoadBitmap(IDB_NONINVOPAMP);
		size.cx = BMXNON;
	}
    dcMemory.CreateCompatibleDC(pDC);
    dcMemory.SelectObject(&bitmap);
	pt=GetScrollPosition();
	pt.x=100-pt.x;
	pt.y=100-pt.y;
    pDC->BitBlt(pt.x+index*size.cx, pt.y, size.cx,\
		 size.cy, &dcMemory, 0, 0, SRCCOPY);

	op=m_ampli->GetOpAmp(index);
	CString s;
	s.Format("R%d=%g", index*2+1, op->r1);
	pDC->TextOut(pt.x+index*size.cx, pt.y, s);
	s.Format("R%d=%g", index*2+2, op->r2);
	pDC->TextOut(pt.x+index*size.cx, pt.y+30, s);
	
	UpdateWindow();
	
	ReleaseDC(pDC);
}

void COpAmpView::OnSET() 
{
	UpdateData();
	int sel = m_reses.GetCurSel();
	COpAmp * op = m_ampli->GetOpAmp(sel/2);
	double r = atof(m_val);
	if(sel % 2)
		op->r2 = r;
	else
		op->r1 = r;
	SetGain();
	DrawOpAmp(sel/2);
	UpdateWindow();

}

void COpAmpView::SetGain()
{
	m_gain.Format("Gain=%g", m_ampli->GetGain());
	UpdateData(FALSE);
}

void COpAmpView::OnSelchangeReses()
{
	TRACE("1\n");
	int sel = m_reses.GetCurSel();
	TRACE("2\n");
	if(sel == CB_ERR)
		return;
	TRACE("3\n");
	COpAmp * op = m_ampli->GetOpAmp(sel/2);
	TRACE("4\n");
	double r = sel % 2 ? op->r2 : op->r1;
	TRACE("5\n");
	m_val.Format("%g", r);
	TRACE("6\n");
	UpdateData(FALSE);
	TRACE("7\n");
}

void COpAmpView::OnFileSave() 
{
	if(!m_bAmpAvailable)
		return;
	CSaveOpAmp dlg;
	if(dlg.DoModal()!=IDOK)
		return;
	m_db.AddNew();
	m_db.m_desc=dlg.m_desc;
	m_db.m_name=dlg.m_name;
	m_db.m_gain=m_ampli->GetGain();
	m_db.m_Ri=(m_ampli->GetOpAmp(0))->r1;
	m_db.m_Ro=0;
	m_db.m_amount=m_ampli->GetCount();
	m_db.m_min=m_ampli->m_min;
	m_db.m_max=m_ampli->m_max;
	CString temp;
	m_db.m_resistors="";
	COpAmp *amp;
	for(int i=0; i<m_ampli->GetCount();i++){
		amp=m_ampli->GetOpAmp(i);
		temp.Format("%g;%g;%d;", amp->r1, amp->r2, amp->type);
		m_db.m_resistors+=temp;
	}///:~
	m_db.Update();
}

void COpAmpView::OnFileOpen() 
{
	CLoadOpAmp dlg(&m_db);
	int index=dlg.DoModal();
	if(index==-1)
		return;
	CString s;
	s.Format("Index=%d", index);
	m_db.FindFirst(LPCTSTR(s));
	COpAmp *amp;
	m_ampli->RemoveAll();
	int base = 0;
	for(int i=0; i<m_db.m_amount;i++)
	{
		CString s1, s2, s3;
		FindString(';',s1, &base);
		FindString(';',s2, &base);
		FindString(';',s3, &base);
		amp=new COpAmp(atof(s1), atof(s2), atof(s3));
		m_ampli->AddOpAmp(*amp);
		m_ampli->type=atof(s3);
	}
	int cx=m_ampli->GetCount()*BMXNON;
	SetScrollSizes(MM_TEXT, CSize(cx, 600));
	ResetReses();
	m_bAmpAvailable=TRUE;
	Invalidate();
	UpdateWindow();
	DrawAmplifier();
	SetGain();
}

void COpAmpView::ResetReses()
{
	m_reses.ResetContent();
	CString str;
	for(int i = 0 ; i < m_ampli->GetCount(); i++)
	{
		str.Format("R%d", 2*i+1);
		m_reses.AddString(str);
		str.Format("R%d", 2*i+2);
		m_reses.AddString(str);
	}
}

void COpAmpView::FindString(TCHAR ch, CString &s, int *index)
{
	int i=*index;
	if(*index>m_db.m_resistors.GetLength()){
		(s = "");
		return;
	}
	while(m_db.m_resistors.GetAt(i)!=ch)
		s+=m_db.m_resistors.GetAt(i++);
	*index=i+1;
}
