// AdHtml.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LT_OCX.h"
#include "AdHtml.h"


// AdHtml �Ի���

IMPLEMENT_DYNCREATE(AdHtml, CDHtmlDialog)

AdHtml::AdHtml(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(AdHtml::IDD, AdHtml::IDH, pParent)
{

}

AdHtml::~AdHtml()
{
	DestroyWindow();
}

void AdHtml::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}

BOOL AdHtml::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();
	//ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW);
	SetWindowLong(this-> GetSafeHwnd(),GWL_EXSTYLE, WS_EX_TOOLWINDOW|WS_EX_STATICEDGE); 
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

BEGIN_MESSAGE_MAP(AdHtml, CDHtmlDialog)

	ON_WM_CREATE()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(AdHtml)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)

END_DHTML_EVENT_MAP()



// AdHtml ��Ϣ�������

HRESULT AdHtml::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT AdHtml::OnButtonCancel(IHTMLElement* /*pElement*/)
{

		OnCancel();
	return S_OK;
}

void AdHtml::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���
	//DestroyWindow();
	//PostThreadMessage()

	//CDHtmlDialog::PostNcDestroy();

}

int AdHtml::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDHtmlDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}

void AdHtml::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDHtmlDialog::OnClose();
}
