// LTPlayer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#define ISSTARTAPP "BA77185C-A5D5-406c-86FC-0974C8BA9337"
#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLTPlayerApp:
// �йش����ʵ�֣������ LTPlayer.cpp
//

class CLTPlayerApp : public CWinApp
{
public:
	CLTPlayerApp();
	HANDLE  myglobalhandle;
		CString startfilename;
// ��д
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
// ʵ��
	INT DlgWidth;	
	INT DlgHigh;
	DECLARE_MESSAGE_MAP()
};

extern CLTPlayerApp theApp;