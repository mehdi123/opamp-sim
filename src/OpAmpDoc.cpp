// OpAmpDoc.cpp : implementation of the COpAmpDoc class
//

#include "stdafx.h"
#include "OpAmp.h"

#include "OpAmpDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpAmpDoc

IMPLEMENT_DYNCREATE(COpAmpDoc, CDocument)

BEGIN_MESSAGE_MAP(COpAmpDoc, CDocument)
	//{{AFX_MSG_MAP(COpAmpDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpAmpDoc construction/destruction

COpAmpDoc::COpAmpDoc()
{
	// TODO: add one-time construction code here

}

COpAmpDoc::~COpAmpDoc()
{
}
/*
BOOL COpAmpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}
*/


/////////////////////////////////////////////////////////////////////////////
// COpAmpDoc serialization
/*
void COpAmpDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}
*/
/////////////////////////////////////////////////////////////////////////////
// COpAmpDoc diagnostics

#ifdef _DEBUG
void COpAmpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpAmpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpAmpDoc commands
