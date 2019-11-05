// SelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "saleSystem.h"
#include "SelectView.h"
#include "MainFrm.h"


// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView ���

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView ��Ϣ�������


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	
	//��ʼ������ͼ
	//��ȡ���ؼ�
	m_treeCtrl = &GetTreeCtrl();

	//1.׼��ͼƬ���

	HICON icon = AfxGetApp()->LoadIconW(IDI_ICON_RE);

	m_imageList.Create(30, 30, ILC_COLOR32, 1, 1);
	m_imageList.Add(icon);

	m_treeCtrl->SetImageList(&m_imageList, TVSIL_NORMAL);

	//2.��ӽڵ�
	m_treeCtrl->InsertItem(TEXT("������Ϣ"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("���۹���"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("������"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("������"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("���ɾ��"), 0, 0, NULL);

	// TODO:  �ڴ����ר�ô����/����û���
}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	//��ȡ��ǰѡ����
	HTREEITEM item = m_treeCtrl->GetSelectedItem();
	//ͨ��ѡ�е��� ��ȡ������е�����
	CString str = m_treeCtrl->GetItemText(item);
	//MessageBox(str);

	if (str==TEXT("������Ϣ"))
	{
		//��Ҫ�������Ͷ�ļ� #include "MainFrm.h"
		//CWnd::PostMessage ��һ����Ϣ���봰�ڵ���Ϣ����
		//AfxGetMainWnd(),��ܴ��ڶ����ָ��
		//AfxGetMainWnd()->GetSafeHwnd(),��ȡ���ش��ڵľ����CWnd::GetSafeHwnd
		//NM_A �����Զ�����Ϣ
		//(WPARAM)NM_A ָ���˸��ӵ���Ϣ��Ϣ
		//��LPARAM��0 ָ���˸��ӵ���Ϣ��Ϣ���˲�������û������
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (str == TEXT("���۹���"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (str == TEXT("������"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (str == TEXT("������"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	else if (str == TEXT("���ɾ��"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
}
