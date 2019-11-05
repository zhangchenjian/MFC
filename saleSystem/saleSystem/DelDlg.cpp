// DelDlg.cpp : 实现文件
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


// CDelDlg 诊断

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


// CDelDlg 消息处理程序


void CDelDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类

	//读取文件，获取商品名 给组合框添加字符串
	CInfoFile file;
	file.ReadDocline();	//读取商品信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end();it++)
	{
		m_combo.AddString(CString(it->name.c_str()));
	}

	//将第一个商品设置为选中项
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
}


void CDelDlg::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码

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
			m_price = it->price;
			// 同步到控件
			UpdateData(FALSE);
		}
	}
}


void CDelDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	//获取控件内容
	UpdateData(TRUE);
	if (m_num<=0)
	{
		MessageBox(TEXT("删除数量大于0"));
		return;
	}
	
	//获取当前选中项
	int index = m_combo.GetCurSel();
	CString name;
	m_combo.GetLBText(index, name);

	CString str;
	str.Format(TEXT("删除商品：%s \r\n 单价：%d \r\n 个数：%d"), name, m_price, m_num);
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
	// TODO:  在此添加控件通知处理程序代码
	m_num = 0;
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
}
