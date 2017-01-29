#pragma once

#include "ResourceForBitmap.h"


// CButtonDialog ダイアログ

class CButtonDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CButtonDialog)

public:
	CButtonDialog(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CButtonDialog();
    //
    void InitButtonSamples();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUTTONDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
    virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
    int m_numOfButtons;
    CButton **m_buttons;
    void CreateGroupBox(CRect &rect, int &buttonId, int &lineNo, int &index);
};
