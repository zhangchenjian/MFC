// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "saleSystem.h"
#include "UserDlg.h"
#include "InfoFile.h"


// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(CUserDlg::IDD)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newPwd(_T(""))
	, m_surePwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT4, m_name);
	DDX_Text(pDX, IDC_EDIT5, m_newPwd);
	DDX_Text(pDX, IDC_EDIT6, m_surePwd);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUserDlg 诊断

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg 消息处理程序


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类

	//初始化
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	m_user = TEXT("销售员");
	m_name = name;
	UpdateData(FALSE);	//将变量同步到控件
}


void CUserDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//修改密码
	UpdateData(TRUE);	//拿到最新的值
	if (m_newPwd.IsEmpty() || m_surePwd.IsEmpty())
	{
		MessageBox(TEXT("输入的内容不能为空"));
		return;
	}
	//新密码与确定密码要一直
	if (m_newPwd!=m_surePwd)
	{
		MessageBox(TEXT("新密码与确定密码不一致"));
		return;
	}
	//新密码与原密码不能一样
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	if (pwd == m_newPwd)
	{
		MessageBox(TEXT("新密码与久密码不能一致"));
		return;
	}
	//CString 转 char*
	CStringA tmp;
	CStringA tmp2;
	tmp = name;
	tmp2 = m_newPwd;
	file.WritePwd(tmp.GetBuffer(), tmp2.GetBuffer());
	MessageBox(TEXT("修改成功"));
	//清空内容
	m_newPwd.Empty();
	m_surePwd.Empty();
	UpdateData(FALSE);	//同步到控件
}


void CUserDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	//取消
	m_newPwd.Empty();
	m_surePwd.Empty();
	UpdateData(FALSE);
}
