// LT_OCX.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "LT_OCX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CLT_OCXApp

BEGIN_MESSAGE_MAP(CLT_OCXApp, CWinApp)
END_MESSAGE_MAP()


// CLT_OCXApp ����

CLT_OCXApp::CLT_OCXApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

CLT_OCXApp::~CLT_OCXApp()
{
	int i=0;
}
// Ψһ��һ�� CLT_OCXApp ����

CLT_OCXApp theApp;


// CLT_OCXApp ��ʼ��

BOOL CLT_OCXApp::InitInstance()
{
	CWinApp::InitInstance();
	
	CoInitialize(0);

	return TRUE;
}

void CLT_OCXApp::ShowAd()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CoInitialize(0);
	AdHtml *ad=new AdHtml;
	ad->Create(IDD_DIALOG1);
	int   cx=GetSystemMetrics(SM_CXSCREEN); 
	int   cy=GetSystemMetrics(SM_CYSCREEN); 
	RECT trect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &trect, 0);
	CRect   rectWindow; 
	ad->GetWindowRect(&rectWindow); 
	int   w=rectWindow.Width(); 
	int   h=rectWindow.Height(); 
    rectWindow.left=cx-w; 
	rectWindow.top=cy-h; 
	rectWindow.right=cx; 
	rectWindow.bottom=trect.bottom; 
	ad->MoveWindow(rectWindow,TRUE);
	ad->ShowWindow(SW_SHOW);

	MSG msg; 
	BOOL bRet=TRUE;

	while(GetMessage( &msg, NULL, 0, 0 ))
	{ 
		if (!ad->IsWindowVisible())
		{
			ad->DestroyWindow();
			delete ad;
			break;
		}
		else
		{
			TranslateMessage(&msg); 
			DispatchMessage(&msg); 
		}
	}
}