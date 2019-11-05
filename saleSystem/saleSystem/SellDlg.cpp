// SellDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "saleSystem.h"
#include "SellDlg.h"
#include "InfoFile.h"


// CSellDlg

IMPLEMENT_DYNCREATE(CSellDlg, CFormView)

CSellDlg::CSellDlg()
	: CFormView(CSellDlg::IDD)
	, m_price(0)
	, m_left(0)
	, m_num(0)
	, m_sellInfo(_T(""))
{

}

CSellDlg::~CSellDlg()
{
}

void CSellDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT5, m_left);
	DDX_Text(pDX, IDC_EDIT6, m_num);
	DDX_Text(pDX, IDC_EDIT2, m_sellInfo);
}

BEGIN_MESSAGE_MAP(CSellDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSellDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CSellDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSellDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSellDlg ���

#ifdef _DEBUG
void CSellDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSellDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSellDlg ��Ϣ�������


void CSellDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

	//��ʼ����Ϣ��������

	//��ʼ��������
	CInfoFile file;
	//����Ʒ����file ����
	file.ReadDocline();

	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		//������Ʒ���� ���������Ʒŵ���������
		
		//it->name �� string    addstring(cstring)
		//string -> cstring
		
		m_combo.AddString(CString(it->name.c_str()));
	}
	//Ĭ��ѡ�е�һ����Ʒ
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
}


void CSellDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�л���Ʒ�������¼�

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
		if ((CString)it->name.c_str()==name)
		{
			m_price = it->price;
			m_left = it->num;
			// ͬ�����ؼ�
			UpdateData(FALSE);
		}
	}
}


void CSellDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//����Ĺ���
	if (m_num<=0)
	{
		MessageBox(TEXT("��������Ҫ����0"));
		return;
	}
	//������������ܴ��ڿ��
	if (m_num>m_left)
	{
		MessageBox(TEXT("�����������ܴ��ڿ��"));
		return;
	}
	//����
	//��ȡ������Ҫ�������Ʒ����
	int index = m_combo.GetCurSel();
	CString name;
	m_combo.GetLBText(index, name);

	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end();it++)
	{
		if ((CString)it->name.c_str() == name)
		{
			//m_price = it->price;
			//m_left = it->num;
			it->num -= m_num;
			m_left = it->num;	//�ؼ��ϵı���
			//�����û�����Ĺ�����Ϣ
			CString str;
			str.Format(_T("��Ʒ��%s \r\n ���ۣ�%d \r\n ������%d \r\n �ܼۣ�%d"),
				name, m_price, m_num, m_price*m_num);
			m_sellInfo = str;
			UpdateData(FALSE);
			MessageBox(TEXT("����ɹ�"));
		}
	}

	//�����µ�����д���ļ���
	file.WriteDocline();

	//�������
	m_num = 0;
	m_sellInfo.Empty();
	UpdateData(FALSE);
}


void CSellDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//ȡ����ť
	m_num = 0;
	UpdateData(FALSE);
	//Ĭ��ѡ�е�һ��
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
}
