
// saleSystemView.cpp : CsaleSystemView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "saleSystem.h"
#endif

#include "saleSystemDoc.h"
#include "saleSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsaleSystemView

IMPLEMENT_DYNCREATE(CsaleSystemView, CView)

BEGIN_MESSAGE_MAP(CsaleSystemView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CsaleSystemView ����/����

CsaleSystemView::CsaleSystemView()
{
	// TODO:  �ڴ˴���ӹ������

}

CsaleSystemView::~CsaleSystemView()
{
}

BOOL CsaleSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CsaleSystemView ����

void CsaleSystemView::OnDraw(CDC* /*pDC*/)
{
	CsaleSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CsaleSystemView ��ӡ

BOOL CsaleSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CsaleSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CsaleSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CsaleSystemView ���

#ifdef _DEBUG
void CsaleSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CsaleSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsaleSystemDoc* CsaleSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsaleSystemDoc)));
	return (CsaleSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CsaleSystemView ��Ϣ�������
