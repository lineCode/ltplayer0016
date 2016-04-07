// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LT_XMLCTRL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LT_XMLCTRL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�

typedef struct tagFileListInfo
{
	CString filename;
	CString filepath;
	int filewidth;
	int fileheight;
	RECT rect;
	int allinindex;
	int mousehovered;
	int mousedbclick;
}FileListInfo,UIFileListInfo;

typedef struct tagUiBgSkinInfo
{
	CString id;
	INT maskcolor;
	CString fname;
}UiSkinInfo ;

#ifdef LT_XMLCTRL_EXPORTS
#define LT_XMLCTRL_API __declspec(dllexport)
#else
#define LT_XMLCTRL_API __declspec(dllimport)
#endif

// �����Ǵ� LT_XMLCtrl.dll ������
class LT_XMLCTRL_API CLT_XMLCtrl {
public:
	CLT_XMLCtrl(void);
	// TODO: �ڴ�������ķ�����
};

extern LT_XMLCTRL_API int nLT_XMLCtrl;

LT_XMLCTRL_API int fnLT_XMLCtrl(void);
extern "C" LT_XMLCTRL_API void PlayList(int i,CArray<FileListInfo,FileListInfo&>*);
void LoadPlayList(CArray<FileListInfo,FileListInfo&>*);
void SavePlayList(CArray<FileListInfo,FileListInfo&>*);
void LoadSkinList(CArray<UiSkinInfo,UiSkinInfo&> *sklist);
void SaveSkinList(CArray<UiSkinInfo,UiSkinInfo&> *sklist);
void CreateFile(CString filename);
CString GetMusicName(CString mfullname);
CString GetSubString(CString str,int index);
void SpliteCString(CString str,CArray<CString,CString&> &arrays,CString spstr);
extern "C" LT_XMLCTRL_API CString GetPlayerConfigValue(CString);
extern "C" LT_XMLCTRL_API void SetPlayerConfigValue(CString,CString);
extern "C" LT_XMLCTRL_API void RadioList(CArray<FileListInfo,FileListInfo&>*);
extern "C" LT_XMLCTRL_API void SkinList(int type,CArray<UiSkinInfo,UiSkinInfo&>*);
extern "C" LT_XMLCTRL_API void SaveNewSkin(CString,char*);
extern "C" LT_XMLCTRL_API UiSkinInfo GetSkinInfo(CString);
char *cctryWideCharToAnsi(wchar_t *pWideChar);
wchar_t * AnsiToWideChar(char* aaa);
