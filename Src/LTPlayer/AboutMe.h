#pragma once

// AboutMe �Ի���

class AboutMe : public CPropertyPage
{
	DECLARE_DYNAMIC(AboutMe)

public:
	AboutMe();   // ��׼���캯��
	virtual ~AboutMe();
// �Ի�������
	enum { IDD = IDD_ABOUTSOFT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	
public:
	afx_msg void OnNMClickSyslink2(NMHDR *pNMHDR, LRESULT *pResult);
};
