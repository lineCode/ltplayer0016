#pragma once

#ifdef _WIN32_WCE
#error "Windows CE ��֧�� CDHtmlDialog��"
#endif 

// AdHtml �Ի���

class AdHtml : public CDHtmlDialog
{
	DECLARE_DYNCREATE(AdHtml)

public:
	AdHtml(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AdHtml();
// ��д
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);
	STDMETHOD(ShowContextMenu)(
		DWORD dwID,
		POINT * ppt,
		IUnknown * pcmdtReserved,
		IDispatch * pdispReserved 
		)
	{
		return S_OK;
	}
// �Ի�������
	enum { IDD = IDD_DIALOG1, IDH = IDR_HTML_ADHTML };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
	virtual void PostNcDestroy();
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
};
