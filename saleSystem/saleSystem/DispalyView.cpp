// DispalyView.cpp : 实现文件
//

#include "stdafx.h"
#include "saleSystem.h"
#include "DispalyView.h"


// CDispalyView

IMPLEMENT_DYNCREATE(CDispalyView, CFormView)

CDispalyView::CDispalyView()
	: CFormView(CDispalyView::IDD)
{

}

CDispalyView::~CDispalyView()
{
}

void CDispalyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDispalyView, CFormView)
END_MESSAGE_MAP()


// CDispalyView 诊断

#ifdef _DEBUG
void CDispalyView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDispalyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDispalyView 消息处理程序
