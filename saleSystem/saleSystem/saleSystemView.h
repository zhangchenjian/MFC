
// saleSystemView.h : CsaleSystemView ��Ľӿ�
//

#pragma once


class CsaleSystemView : public CView
{
protected: // �������л�����
	CsaleSystemView();
	DECLARE_DYNCREATE(CsaleSystemView)

// ����
public:
	CsaleSystemDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CsaleSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // saleSystemView.cpp �еĵ��԰汾
inline CsaleSystemDoc* CsaleSystemView::GetDocument() const
   { return reinterpret_cast<CsaleSystemDoc*>(m_pDocument); }
#endif
