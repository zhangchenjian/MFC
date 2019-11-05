// AddDlg.cpp : 实现文件
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


// CAddDlg 诊断

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


// CAddDlg 消息处理程序


void CAddDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类

	//初始化下拉框
	CInfoFile file;
	//把商品读到file 对象
	file.ReadDocline();

	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		//遍历商品容器 把容器名称放到下拉框中

		//it->name 是 string    addstring(cstring)
		//string -> cstring

		m_combo.AddString(CString(it->name.c_str()));
	}
	//默认选中第一个商品
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo2();
}


void CAddDlg::OnCbnSelchangeCombo2()
{
	// TODO:  在此添加控件通知处理程序代码

	//切换商品触发的事件

	//拿到当前商品名称
	int index = m_combo.GetCurSel();
	//根据索引获取具体内容
	CString name;
	m_combo.GetLBText(index, name);
	//根据商品名称获取该商品的价格和 库存 并且显示到控件中
	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if ((CString)it->name.c_str() == name)
		{
			m_price1 = it->price;
			//m_left = it->num;
			// 同步到控件
			UpdateData(FALSE);
		}
	}
}


void CAddDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	//添加商品按钮实现
	//拿到最新的数据
	UpdateData(TRUE);
	if (m_num1<=0)
	{
		MessageBox(TEXT("添加的数量要大于0"));
		return;
	}
	//获取到要添加的商品名称
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
			// 同步到控件
			UpdateData(FALSE);
			MessageBox(TEXT("添加成功"));
		}
	}

	//同步到文件
	file.WriteDocline();
	
}


void CAddDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_num1 = 0;
	UpdateData(FALSE);

	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo2();
}


void CAddDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码

	//添加新商品
	//验证数据的有效性
	//拿到最新的数据
	UpdateData(TRUE);
	if (m_name2.IsEmpty() || m_num2 <= 0 || m_price2 <= 0)
	{
		MessageBox(TEXT("输入信息有误"));
		return;
	}

	CInfoFile file;
	file.ReadDocline();

	file.Addline(m_name2, m_num2, m_price2);
	file.WriteDocline();
	
	MessageBox(TEXT("新商品添加成功"));

	//同步到左部的下拉框中
	m_combo.InsertString(0, m_name2);
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo2();

	//清空添加的新数据
	m_name2.Empty();
	m_num2 = 0;
	m_price2 = 0;
	UpdateData(FALSE);	// 同步到控件
}


void CAddDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	//取消添加新商品按钮事件
	//清空添加的新数据
	m_name2.Empty();
	m_num2 = 0;
	m_price2 = 0;
	UpdateData(FALSE);	// 同步到控件
}
