// LTPlayer.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "LTPlayer.h"
#include "LTPlayerDlg.h"
#include "ControlPanelDlg.h"
#include "CWMPPlayer4.h"
#include "CWMPSettings.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

ULONG_PTR m_gdiplusToken;
// CLTPlayerApp

BEGIN_MESSAGE_MAP(CLTPlayerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLTPlayerApp ����

CLTPlayerApp::CLTPlayerApp():DlgHigh(526),DlgWidth(303)
{
	//AfxMessageBox(_T("aaaaaaaaa"));// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CLTPlayerApp ����

CLTPlayerApp theApp;


// CLTPlayerApp ��ʼ��

BOOL CLTPlayerApp::InitInstance()
{	
	
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	startfilename = cmdInfo.m_strFileName;

	OSVERSIONINFO osvi;
	BOOL bIsWindowsXPorLater;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osvi);
	if (osvi.dwMajorVersion<5)
	{
		MessageBox(NULL,_T("����ʹ�ò���ϵͳ�汾����"),_T("��ʾ"),MB_OK);
		return FALSE;	
	}
	myglobalhandle=::CreateMutex(NULL,FALSE,_T(ISSTARTAPP));
	{
		if(GetLastError()==ERROR_ALREADY_EXISTS)	
		{
			//SendMessage(WM_STARTRUNOPENFILE_MESSAGE)
			HWND   hWnd  = FindWindow(NULL,_T("��������������")); 
			if (GetProp(hWnd,CString(ISSTARTAPP))==(HANDLE)1)
			{
				COPYDATASTRUCT cpd;                     // ��COPYDATASTRUCT���ָ�ֵ
				cpd.dwData = 0;
				cpd.cbData = (startfilename.GetLength()+1)*sizeof(CString);
				cpd.lpData =(void*)startfilename.GetBuffer(cpd.cbData);
				SendMessage(hWnd,WM_COPYDATA,NULL,(LPARAM)&cpd);
			}
			return FALSE;	
		}
	}

	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));



	ControlPanelDlg dlg;
	m_pMainWnd = &dlg;

#ifdef _OPENCONSOLE
	if (!AllocConsole())
	{}
#endif


	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

int CLTPlayerApp::ExitInstance() 
{
	//	deallocate console
#ifdef _OPENCONSOLE
	if (!FreeConsole())
	{}
#endif
	CloseHandle(myglobalhandle);

	return CWinApp::ExitInstance();
}
