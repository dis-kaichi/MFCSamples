
// MFCSamplesDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once


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
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g


// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
