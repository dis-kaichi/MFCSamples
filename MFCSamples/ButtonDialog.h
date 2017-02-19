#pragma once

#include "ResourceForBitmap.h"
#include "UserDialogInterface.h"

// CButtonDialog ダイアログ

class CButtonDialog : public CDialogEx, public UserDialogInterface
{
	DECLARE_DYNAMIC(CButtonDialog)

public:
	CButtonDialog(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CButtonDialog();
    virtual void Open();
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
    int m_num_of_buttons;
    CButton **m_buttons;
    CBitmapButton *m_bitmap_button;
    CButton m_notify_button;
    int m_button_id;
    int m_index;

    // Button Styles
    void Create3StateButton();
    void CreateAuto3StateButton();
    void CreateAutoCheckBox();
    void CreateAutoRadioButton();
    void CreateCheckBox();
    void CreateCommandLink();
    void CreateDefCommandLink();
    void CreateDefPushButton();
    void CreateDefSplitButton();
    void CreateGroupBox();
    void CreateOwnerDrawButton();
    void CreatePushButton();
    void CreateRadioButton();
    void CreateSplitButton();

    // Option Button / Check Box Only Styles
    void CreateCheckBoxLeftText();
    void CreateCheckBoxRightButton();
    void CreateCheckBoxPushLike();

    // Text Styles
    void CreateLeftAlign();
    void CreateRightAlign();
    void CreateCenterAlign();
    void CreateTopAlign();
    void CreateBottomAlign();
    void CreateVerticalCenterAlign();

    // Button
    void CreateBitmapButton();
    void CreateIconButton();
    void CreateTextButton();

    // Others
    void CreateFlatButton();
    void CreateMultiLineButton();
    void CreateNotifyButton();

    void OnDoubleClicked();

    void InitDialog();
};
