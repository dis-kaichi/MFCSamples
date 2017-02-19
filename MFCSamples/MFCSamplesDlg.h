
// MFCSamplesDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once
#include "afxbutton.h"
#include "ButtonManager.h"

// CMFCSamplesDlg �_�C�A���O
class CMFCSamplesDlg : public CDialogEx
{
// �R���X�g���N�V����
public:
	CMFCSamplesDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^�[

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSAMPLES_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL PreTranslateMessage(MSG *pMsg);
    virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

    HICON m_hIcon;
    void OnLButtonClicked(UINT nID);

private:
    CButtonManager m_button_manager;
    CButton m_button_for_button;
    CButton m_button_for_edit;
    bool m_alt_key_pressed;

    bool IsAltKeyPressed();
};
