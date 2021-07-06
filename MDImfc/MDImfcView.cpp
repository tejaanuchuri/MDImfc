
// MDImfcView.cpp : implementation of the CMDImfcView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MDImfc.h"
#endif

#include "MDImfcDoc.h"
#include "MDImfcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDImfcView

IMPLEMENT_DYNCREATE(CMDImfcView, CView)

BEGIN_MESSAGE_MAP(CMDImfcView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMDImfcView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMDImfcView construction/destruction

CMDImfcView::CMDImfcView() noexcept
{
	// TODO: add construction code here

}

CMDImfcView::~CMDImfcView()
{
}

BOOL CMDImfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMDImfcView drawing

void CMDImfcView::OnDraw(CDC* /*pDC*/)
{
	CMDImfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMDImfcView printing


void CMDImfcView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMDImfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMDImfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMDImfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMDImfcView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMDImfcView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMDImfcView diagnostics

#ifdef _DEBUG
void CMDImfcView::AssertValid() const
{
	CView::AssertValid();
}

void CMDImfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDImfcDoc* CMDImfcView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDImfcDoc)));
	return (CMDImfcDoc*)m_pDocument;
}
#endif //_DEBUG


// CMDImfcView message handlers
