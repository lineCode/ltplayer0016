// LT_OCX.h : LT_OCX DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "AdHtml.h"

// CLT_OCXApp
// �йش���ʵ�ֵ���Ϣ������� LT_OCX.cpp
//

class CLT_OCXApp : public CWinApp
{
public:
	
	CLT_OCXApp();
	~CLT_OCXApp();
	void ShowAd();
	
// ��д
public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};
