#pragma once
#include "ButtonDialog.h"

// CDriverButton �_�C�A���O

class CDriverButton : public CMFCButton
{
	DECLARE_DYNAMIC(CDriverButton)

public:                               
	CDriverButton(CWnd* pParent = NULL);   // �W���R���X�g���N�^�[
	virtual ~CDriverButton();

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSAMPLES_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:
};
