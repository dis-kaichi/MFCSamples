#pragma once
#include "ButtonDialog.h"

// CDriverButton ダイアログ

class CDriverButton : public CMFCButton
{
	DECLARE_DYNAMIC(CDriverButton)

public:                               
	CDriverButton(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CDriverButton();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSAMPLES_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:
};
