// AboutMe.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LTPlayer.h"
#include "AboutMe.h"
#include "Resource.h"
// AboutMe �Ի���

IMPLEMENT_DYNAMIC(AboutMe, CPropertyPage)

AboutMe::AboutMe()
	: CPropertyPage(AboutMe::IDD)
{

}

AboutMe::~AboutMe()
{
}

void AboutMe::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);

}


BEGIN_MESSAGE_MAP(AboutMe, CPropertyPage)

	ON_NOTIFY(NM_CLICK, IDC_SYSLINK2, &AboutMe::OnNMClickSyslink2)
END_MESSAGE_MAP()


BOOL AboutMe::OnInitDialog()
{
	CDialog::OnInitDialog();
	::SetWindowPos(this->m_hWnd,   NULL,   0,   0, 
		300,   350, 
		SWP_NOMOVE   |   SWP_NOZORDER   |   SWP_NOACTIVATE); 
	SetDlgItemText(IDC_STATICweb,_T("mail:ltplayer@yeah.net   QQ:909298863"));	
	return TRUE;  
}
// AboutMe ��Ϣ�������

void AboutMe::OnNMClickSyslink2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PNMLINK pNMLink = (PNMLINK) pNMHDR;   
	ShellExecute(NULL,L"open",L"http://www.ltplayer.com",NULL,NULL,SW_SHOW);
	*pResult = 0;
}
