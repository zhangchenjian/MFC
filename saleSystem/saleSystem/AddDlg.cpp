// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "saleSystem.h"
#include "AddDlg.h"
#include "InfoFile.h"


// CAddDlg

IMPLEMENT_DYNCREATE(CAddDlg, CFormView)

CAddDlg::CAddDlg()
	: CFormView(CAddDlg::IDD)
	, m_price1(0)
	, m_num1(0)
	, m_name2(_T(""))
	, m_price2(0)
	, m_num2(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_combo);
	DDX_Text(pDX, IDC_EDIT2, m_price1);
	DDX_Text(pDX, IDC_EDIT3, m_num1);
	DDX_Text(pDX, IDC_EDIT5, m_name2);
	DDX_Text(pDX, IDC_EDIT7, m_price2);
	DDX_Text(pDX, IDC_EDIT8, m_num2);
}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CAddDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAddDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CAddDlg ���

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDlg ��Ϣ�������


void CAddDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

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
	OnCbnSelchangeCombo2();
}


void CAddDlg::OnCbnSelchangeCombo2()
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
		if ((CString)it->name.c_str() == name)
		{
			m_price1 = it->price;
			//m_left = it->num;
			// ͬ�����ؼ�
			UpdateData(FALSE);
		}
	}
}


void CAddDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//�����Ʒ��ťʵ��
	//�õ����µ�����
	UpdateData(TRUE);
	if (m_num1<=0)
	{
		MessageBox(TEXT("��ӵ�����Ҫ����0"));
		return;
	}
	//��ȡ��Ҫ��ӵ���Ʒ����
	int index = m_combo.GetCurSel();
	CString name;
	m_combo.GetLBText(index, name);

	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if ((CString)it->name.c_str() == name)
		{
			it->num += m_num1;
			m_num1 = 0;
			// ͬ�����ؼ�
			UpdateData(FALSE);
			MessageBox(TEXT("��ӳɹ�"));
		}
	}

	//ͬ�����ļ�
	file.WriteDocline();
	
}


void CAddDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_num1 = 0;
	UpdateData(FALSE);

	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo2();
}


void CAddDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//�������Ʒ
	//��֤���ݵ���Ч��
	//�õ����µ�����
	UpdateData(TRUE);
	if (m_name2.IsEmpty() || m_num2 <= 0 || m_price2 <= 0)
	{
		MessageBox(TEXT("������Ϣ����"));
		return;
	}

	CInfoFile file;
	file.ReadDocline();

	file.Addline(m_name2, m_num2, m_price2);
	file.WriteDocline();
	
	MessageBox(TEXT("����Ʒ��ӳɹ�"));

	//ͬ�����󲿵���������
	m_combo.InsertString(0, m_name2);
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo2();

	//�����ӵ�������
	m_name2.Empty();
	m_num2 = 0;
	m_price2 = 0;
	UpdateData(FALSE);	// ͬ�����ؼ�
}


void CAddDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//ȡ���������Ʒ��ť�¼�
	//�����ӵ�������
	m_name2.Empty();
	m_num2 = 0;
	m_price2 = 0;
	UpdateData(FALSE);	// ͬ�����ؼ�
}
