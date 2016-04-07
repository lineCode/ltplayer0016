// LTPlayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LTPlayer.h"
#include "LTPlayerDlg.h"
#include "Wininet.h"
//
//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif


// CLTPlayerDlg �Ի���

UINT  startshowad(LPVOID pParam);
typedef void (*GETMYPROC)();

CLTPlayerDlg::CLTPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLTPlayerDlg::IDD, pParent)
{
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		int skinid =_wtoi(MusicUtils::GetConfigXml(CString("skin"),L"1"));
		CString css;
		css.Format(_T("res\\nbg%d.png"),skinid);
		Drawimage.LoadResImage(css.GetBuffer(),L"BG",bgimgsrc);
		setbgsrc=0;

}
ControlPanelDlg *m_ControlPanelDlg;
CLTPlayerDlg::~CLTPlayerDlg()
{
	{
		if (m_ControlPanelDlg->controlevent->volumstatus)
			SetIniValue(_T("mute"),_T("2"));
		else
			SetIniValue(_T("mute"),_T("1"));
	}

	{
		if (m_ControlPanelDlg->islooplist)
			SetIniValue(_T("loop"),_T("2"));
		else
			SetIniValue(_T("loop"),_T("1"));
	}
	{
		wchar_t a[100];
		wchar_t b[100];
		_itow_s (m_ControlPanelDlg->volumeslider->Gsliderinfo.i2_srcwidth,a,100,10);
		_itow_s(m_ControlPanelDlg->volumeslider->Gsliderinfo.i3_x,b,100,10);
		SetIniValue(_T("volume"),a);
		//SetIniValue(_T("volume"),b);
	}
	USES_CONVERSION;

	SetIniValue(_T("lastplayfile"),A2W(m_ControlPanelDlg->currentfilename));

}
void CLTPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLTPlayerDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_NCHITTEST()
	ON_WM_CREATE()
	ON_WM_MOVE()
	ON_MESSAGE(WM_ONSETBGALPHA_MESSAGE,OnSetBgAlpha)
	ON_MESSAGE(WM_ONSETBGIMG_MESSAGE,OnSetBgImg)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CLTPlayerDlg ��Ϣ�������

BOOL CLTPlayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
this->SetWindowText(_T("��������-�����۾�������"));
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	ModifyStyleEx(0,WS_EX_LAYERED);
	Drawimage.DrawMainBg(m_hWnd,MAINBG_WIDTH,MAINBG_HEIGHT,bgimgsrc,_wtoi(MusicUtils::GetConfigXml(CString("transparent"),L"255")));
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLTPlayerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLTPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


LRESULT CLTPlayerDlg::OnNcHitTest(CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    SendMessage (WM_NCLBUTTONDOWN, HTCAPTION, 0);
	return CDialog::OnNcHitTest(point);
}

int CLTPlayerDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rect;
	rect.top=100;
	rect.left=100;
	rect.right=rect.left+MAINBG_WIDTH;
	rect.bottom=rect.top+MAINBG_HEIGHT;

	m_FrameShadowDlg=new FrameShadowDlg;
	m_FrameShadowDlg->Create(IDD_FRAMESHADOWDLG,this);
	
	

	m_ControlPanelDlg = new ControlPanelDlg;
	m_ControlPanelDlg->Create(IDD_CONTROLPANEL,m_FrameShadowDlg);
	
	m_FrameShadowDlg->MoveWindow(rect);
	m_ControlPanelDlg->MoveWindow(rect);
	MoveWindow(rect);
	m_FrameShadowDlg->ShowWindow(SW_SHOW);
	m_ControlPanelDlg->ShowWindow(SW_SHOW);
	if (theApp.startfilename!="")
	{
		m_ControlPanelDlg->OpenFileAndPlayer(theApp.startfilename);
	}
	else
	{
		m_ControlPanelDlg->LoadMusicList();
	}
	m_ControlPanelDlg->LoadRadioList();
	//BOOL bConnected = InternetCheckConnection(_T("http://www.google.com"), FLAG_ICC_FORCE_CONNECTION, 0);
	//if (bConnected)
	//{
	//	AfxBeginThread(startshowad,NULL);
	//}
	if (_wtoi(MusicUtils::GetConfigXml(L"autoplay",L"0")))
	{
		m_ControlPanelDlg->AutoPlay();
	}
	::SetProp(m_ControlPanelDlg->m_hWnd,CString(ISSTARTAPP),(HANDLE)1);
	return 0;
}

//UINT  startshowad(LPVOID pParam)
//{
//	Sleep(20000);
//	HINSTANCE hinstLib; 
//	GETMYPROC ProcAdd; 
//	hinstLib = LoadLibrary(TEXT("LT_OCX.dll")); 
//	ProcAdd = (GETMYPROC) GetProcAddress(hinstLib, "ShowAd"); 
//	ProcAdd();
//	FreeLibrary(hinstLib);
//	AfxEndThread(0);
//	return 1;
//}

void CLTPlayerDlg::OnMove(int x, int y)
{
	CDialog::OnMove(x, y);
	CRect rect;
	rect.top=y;
	rect.left=x;
	rect.right=rect.left+MAINBG_WIDTH;
	rect.bottom=rect.top+MAINBG_HEIGHT;
	m_ControlPanelDlg->MoveWindow(&rect);
	m_FrameShadowDlg->MoveWindow(&rect);
	// TODO: �ڴ˴������Ϣ����������
}
void CLTPlayerDlg::SetIniValue(LPCTSTR key ,LPCTSTR str)
{
	SetIniValue(key,str,"SetPlayerConfigValue");
}

void CLTPlayerDlg::SetIniValue(LPCTSTR key ,LPCTSTR str,LPCSTR funname)
{
	MusicUtils::WriteConfigXml(key,str,funname);
}
LRESULT CLTPlayerDlg::OnSetBgAlpha(WPARAM wParam, LPARAM lParam)
{
	//BOOL bConnected = InternetCheckConnection(_T("http://www.google.com"), FLAG_ICC_FORCE_CONNECTION, 0);
	//if (bConnected)
	//{
	//	AfxBeginThread(startshowad,NULL);
	//}
	if (setbgsrc==0){
		Drawimage.DrawMainBg(m_hWnd,MAINBG_WIDTH,MAINBG_HEIGHT,bgimgsrc,lParam);}
		else{
			Drawimage.DrawMainBg(m_hWnd,MAINBG_WIDTH,MAINBG_HEIGHT,setbgsrc,lParam);}
	return 1;
}

LRESULT CLTPlayerDlg::OnSetBgImg(WPARAM wParam, LPARAM lParam)
{
	if (setbgsrc!=NULL)
	{
		delete setbgsrc;
	}
	CString cs;
	Bitmap*bgimgsrcT;
	cs.Format(_T("res\\nbg%d.png"),wParam);
	Drawimage.LoadResImage(cs.GetBuffer(),L"BG",bgimgsrcT);
	int i=1;

	while (i<=15 && i*17<=lParam)
	{
		Sleep(100);
		Drawimage.DrawMainBg(m_hWnd,MAINBG_WIDTH,MAINBG_HEIGHT,bgimgsrcT,i*17);
		i++;
	}
	//setbgsrc=new Bitmap(bgimgsrcT->GetWidth(),bgimgsrcT->GetHeight());
	setbgsrc=bgimgsrcT->Clone(0,0,bgimgsrcT->GetWidth(),bgimgsrcT->GetHeight(),PixelFormat32bppARGB);
	delete bgimgsrcT;
	return 1;
}

BOOL CLTPlayerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

	return MusicUtils::ArrestKeyDown(pMsg);
}

void CLTPlayerDlg::OnDropFiles(HDROP hDropInfo)
{

	m_ControlPanelDlg->OnDropFiles(hDropInfo);

}
