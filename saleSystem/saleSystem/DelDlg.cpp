// DelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "saleSystem.h"
#include "DelDlg.h"
#include "InfoFile.h"


// CDelDlg

IMPLEMENT_DYNCREATE(CDelDlg, CFormView)

CDelDlg::CDelDlg()
	: CFormView(CDelDlg::IDD)
	, m_price(0)
	, m_num(0)
{

}

CDelDlg::~CDelDlg()
{
}

void CDelDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT5, m_num);
}

BEGIN_MESSAGE_MAP(CDelDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDelDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CDelDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDelDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDelDlg ���

#ifdef _DEBUG
void CDelDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDelDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDelDlg ��Ϣ�������


void CDelDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

	//��ȡ�ļ�����ȡ��Ʒ�� ����Ͽ�����ַ���
	CInfoFile file;
	file.ReadDocline();	//��ȡ��Ʒ��Ϣ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end();it++)
	{
		m_combo.AddString(CString(it->name.c_str()));
	}

	//����һ����Ʒ����Ϊѡ����
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
}


void CDelDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//�õ���ǰ��Ʒ����
	int index = m_combo.GetCurSel();
	//����������ȡ��������
	CString name;
	m_combo.GetLBText(index, name);
	//������Ʒ���ƻ�ȡ����Ʒ�ļ۸�� ��� ������ʾ���ؼ���
	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if ((CString)it->name.c_str() == name)
		{
			m_price = it->price;
			// ͬ�����ؼ�
			UpdateData(FALSE);
		}
	}
}


void CDelDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//��ȡ�ؼ�����
	UpdateData(TRUE);
	if (m_num<=0)
	{
		MessageBox(TEXT("ɾ����������0"));
		return;
	}
	
	//��ȡ��ǰѡ����
	int index = m_combo.GetCurSel();
	CString name;
	m_combo.GetLBText(index, name);

	CString str;
	str.Format(TEXT("ɾ����Ʒ��%s \r\n ���ۣ�%d \r\n ������%d"), name, m_price, m_num);
	MessageBox(str);

	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end();it++)
	{
		if ((CString)it->name.c_str() == name)
		{
			it->num -= m_num;
		}
	}
	file.WriteDocline();
	m_num = 0;
	UpdateData(FALSE);
}


void CDelDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_num = 0;
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
}
