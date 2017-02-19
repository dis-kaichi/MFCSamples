#pragma once

#include "UserDialogInterface.h"


// CEditDialog �_�C�A���O

class CEditDialog : public CDialog, public UserDialogInterface
{
	DECLARE_DYNAMIC(CEditDialog)

public:
	CEditDialog(CWnd* pParent = NULL);   // �W���R���X�g���N�^�[
	virtual ~CEditDialog();
    virtual void Open();

    void InitEditSamples();

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
    virtual void OnOK();
    virtual BOOL PreTranslateMessage(MSG *pMsg);
    virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
    CEdit **m_edits;
    int m_num_of_edits;
    int m_edit_id;
    int m_index;
    int m_current_edit_id;
    bool m_is_shift_pressed;

    // 
    void CreateAutoHScroll();
    void CreateAutoVScroll();
    void CreateCenter();
    void CreateLeft();
    void CreateLowerCase();
    void CreateMultiLine();
    void CreateNoHideSel();
    void CreateNumber();
    void CreateOEMConvert();
    void CreatePassword();
    void CreateReadoOnly();
    void CreateRight();
    void CreateUpperCase();
    void CreateWantReturn();
    //
    void InitDialog();
    UINT GetNextEditId();
    UINT GetPreviousEditId();
    bool IsShiftPressed();
    void InitFocus();

};
