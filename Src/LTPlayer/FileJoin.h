#pragma once


// FileJoin �Ի���

class FileJoin : public CPropertyPage
{
	DECLARE_DYNAMIC(FileJoin)

public:
	FileJoin();
	virtual ~FileJoin();

// �Ի�������
	enum { IDD = IDD_FILEJOIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void OnOK();
	BOOL RegisterFileRelation( const CString& strExtension,  
		const CString& strApplicationName,
		const CString& strRunKey,
		const CString& strDefaultIcon,  
		const CString& strDescription );
	DECLARE_MESSAGE_MAP()
};
