
// saleSystem.h : saleSystem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CsaleSystemApp:
// �йش����ʵ�֣������ saleSystem.cpp
//

class CsaleSystemApp : public CWinApp
{
public:
	CsaleSystemApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CsaleSystemApp theApp;
