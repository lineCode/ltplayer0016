// LTPlayerDlg.h : ͷ�ļ�
//

#pragma once
#include "DrawImages.h"
#include "ConstValues.h"
#include "ControlPanelDlg.h"
#include "FrameShadowDlg.h"

// CLTPlayerDlg �Ի���
class CLTPlayerDlg : public CDialog
{
// ����
public:
	CLTPlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CLTPlayerDlg();
// �Ի�������
	enum { IDD = IDD_LTPLAYER_DIALOG };
	/*ControlPanelDlg *m_ControlPanelDlg;*/
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	ControlPanelDlg *m_ControlPanelDlg;
	FrameShadowDlg *m_FrameShadowDlg;
	DrawImages Drawimage;
	Bitmap*bgimgsrc;
	Bitmap*setbgsrc;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMove(int x, int y);
	void SetIniValue(LPCTSTR key ,LPCTSTR str);
	void SetIniValue(LPCTSTR key ,LPCTSTR str,LPCSTR funname);
	afx_msg LRESULT OnSetBgAlpha(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetBgImg(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnDropFiles(HDROP hDropInfo);
};