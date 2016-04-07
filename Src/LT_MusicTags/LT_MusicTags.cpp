// LT_MusicTags.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "LT_MusicTags.h"
#include "tags.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;
const char* const g_fmt = "%IFV2(%ITRM(%TITL),%ITRM(%TITL),no-Atitle)|%IFV2(%ITRM(%ARTI),%ITRM(%ARTI),no-Aartist)";
using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
	}

	return nRetCode;
}
extern "C" LT_MUSICTAGS_API bool GetMusicTilteAndArtist(DWORD handle,CString* title,CString* artist)
{
	if(!handle)
	{
		return true;
	}
	char* str =(char*) TAGS_Read(handle, g_fmt);
	if(*str)
	{
		int index=0;
		CArray<CString,CString&> arrays;
		CString tag=CString(str);
		CString resToken=tag.Tokenize(_T("|"),index);
		while (resToken != _T(""))
		{
			arrays.Add(resToken);
			resToken=tag.Tokenize(_T("|"),index);
		}
		*title=arrays.GetAt(0);
		*artist=arrays.GetAt(1);
		if (*title==_T("no-Atitle"))
		{
			return false;
		}
		else
		{
			if (*artist==_T("no-Aartist"))
			{
				*artist=_T("");
			}
		}
	}else
	{
		//delete str;
		return false;
	}
	//delete str;
	return true;
}
