#pragma once

#include "DrawImages.h"
#include "ConstValues.h"
// FrameShadowDlg �Ի���

class FrameShadowDlg : public CDialog
{
	DECLARE_DYNAMIC(FrameShadowDlg)

public:
	FrameShadowDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FrameShadowDlg();

// �Ի�������
	enum { IDD = IDD_FRAMESHADOWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DrawImages Drawimage;
	Bitmap*bgimgsrc;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnMove(int x, int y);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
