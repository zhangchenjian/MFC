#pragma once
#include "afxcmn.h"



// CInfoDlg ������ͼ

class CInfoDlg : public CFormView
{
	DECLARE_DYNCREATE(CInfoDlg)

protected:
	CInfoDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CInfoDlg();

public:
	enum { IDD = DIALOG_INFO };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
public:
	virtual void OnInitialUpdate();
};


