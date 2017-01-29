#pragma once

#include "ResourceForBitmap.h"


// CButtonDialog �_�C�A���O

class CButtonDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CButtonDialog)

public:
	CButtonDialog(CWnd* pParent = NULL);   // �W���R���X�g���N�^�[
	virtual ~CButtonDialog();
    //
    void InitButtonSamples();

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUTTONDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
    virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
    int m_numOfButtons;
    CButton **m_buttons;
    void CreateGroupBox(CRect &rect, int &buttonId, int &lineNo, int &index);
};
