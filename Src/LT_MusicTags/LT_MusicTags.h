// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LT_MUSICTAGS_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LT_MUSICTAGS_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef LT_MUSICTAGS_EXPORTS
#define LT_MUSICTAGS_API __declspec(dllexport)
#else
#define LT_MUSICTAGS_API __declspec(dllimport)
#endif

// �����Ǵ� LT_MusicTags.dll ������
class LT_MUSICTAGS_API CLT_MusicTags {
public:
	CLT_MusicTags(void);
	// TODO: �ڴ�������ķ�����
};

extern LT_MUSICTAGS_API int nLT_MusicTags;

LT_MUSICTAGS_API int fnLT_MusicTags(void);

extern "C" LT_MUSICTAGS_API bool GetMusicTilteAndArtist(DWORD,CString*,CString*);