// ButtonDialog.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MFCSamples.h"
#include "ButtonDialog.h"
#include "afxdialogex.h"
#include "CommonUtility.h"


// CButtonDialog �_�C�A���O

IMPLEMENT_DYNAMIC(CButtonDialog, CDialogEx)

BEGIN_MESSAGE_MAP(CButtonDialog, CDialogEx)
    ON_BN_DOUBLECLICKED(IDC_BUTTON_SAMPLE1, OnDoubleClicked)
END_MESSAGE_MAP()


CButtonDialog::CButtonDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BUTTONDIALOG, pParent)
    , m_button_id(BUTTON_BASE_ID)
    , m_index(0)
{
    m_num_of_buttons = 100;
    m_buttons = new CButton*[m_num_of_buttons];
    for (int i = 0; i < m_num_of_buttons; i++) {
        m_buttons[i] = new CButton;
    }
    m_bitmap_button = new CBitmapButton();
}

CButtonDialog::~CButtonDialog()
{
    for (int i = 0; i < m_num_of_buttons; i++) {
        delete m_buttons[i];
    }
    delete m_buttons;
    delete m_bitmap_button;
}

void CButtonDialog::Open()
{
    DoModal();
}

void CButtonDialog::InitButtonSamples()
{
    RedrawWindow();
}

void CButtonDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CButtonDialog::OnInitDialog()
{
    // �_�C�A���O�T�C�Y
    InitDialog();

    // �{�^���C�x���g�͈ȉ����Q�l
    // https://msdn.microsoft.com/ja-jp/library/tf9hd91s.aspx
    // [Notice]
    //   �C�x���g�� : �����ŃC�x���g������K�v������
    //   �C�x���g�L : �f�t�H���g�̃C�x���g�ݒ肪����

    ////////////////////////////////////////////////////////////
    // Button Styles
    ////////////////////////////////////////////////////////////
    // BS_3STATE : 3��ԃ{�^��(�C�x���g��)
    Create3StateButton();
    // BS_AUTO3STATE : 3��ԃ{�^��(�C�x���g�L)
    CreateAuto3StateButton();
    // BS_AUTOCHECKBOX : �`�F�b�N�{�b�N�X(�C�x���g�L)
    CreateAutoCheckBox();
    // BS_AUTORADIOBUTTON : ���W�I�{�^��(�C�x���g�L)
    CreateAutoRadioButton();
    // BS_AUTOCHECKBOX : �`�F�b�N�{�b�N�X(�C�x���g��)
    CreateCheckBox();
    // BS_COMMANDLINK : Command Link (�C�x���g��)
    CreateCommandLink();
    // BS_DEFCOMMANDLINK : Command Link (�C�x���g�L)
    CreateDefCommandLink();
    // BS_DEFPUSHBUTTON : Push Button (�C�x���g�L; ���E���������H)
    CreateDefPushButton();
    // BS_DEFSPLITBUTTON : Split Button (�C�x���g�L)
    CreateDefSplitButton();
    // BS_GROUPBOX : Group Box (�C�x���g�L)
    CreateGroupBox();
    // BS_OWNERDRAW : Owner Draw
    CreateOwnerDrawButton();
    // BS_PUSHBUTTON : Push Button
    CreatePushButton();
    // BS_RADIOBUTTON : Radio Button(�C�x���g��)
    CreateRadioButton();
    // BS_SPLITBUTTON : Split Button(�C�x���g��)
    CreateSplitButton();

    ////////////////////////////////////////////////////////////
    // Option(Radio) Button or Check Box Only
    ////////////////////////////////////////////////////////////
    // BS_LEFTTEXT : �����Ƀe�L�X�g�\��
    CreateCheckBoxLeftText();
    // BS_RIGHTBUTTON : �����Ƀe�L�X�g�\��(BS_LEFTTEXT�Ɠ�������)
    CreateCheckBoxRightButton();
    // BS_PUSHLIKE : �R�}���h�{�^�����C�N�ɂ���
    CreateCheckBoxPushLike();

    ////////////////////////////////////////////////////////////
    // Text Alignment
    ////////////////////////////////////////////////////////////
    // BS_LEFT : ����
    CreateLeftAlign();
    // BS_RIGHT : �E��
    CreateRightAlign();
    // BS_CENTER : ������
    CreateCenterAlign();
    // BS_TOP : ���
    CreateTopAlign();
    // BS_BOTTOM : ����
    CreateBottomAlign();
    // BS_VCENTER : �c����������
    CreateVerticalCenterAlign();

    ////////////////////////////////////////////////////////////
    // �{�^���̓��e�Ɋւ���Option
    ////////////////////////////////////////////////////////////
    // BS_BITMAP    : Bitmap
    CreateBitmapButton();
    // BS_ICON      : Icon
    CreateIconButton();
    // BS_TEXT      : Text
    CreateTextButton();

    ////////////////////////////////////////////////////////////
    // Others
    ////////////////////////////////////////////////////////////
    // BS_FLAT      : �t���b�g
    CreateFlatButton();
    // BS_MULTILINE : �����������ꍇ�ɕ����s�ɂ���
    CreateMultiLineButton();
    // BS_NOTIFY    : �eWindow�ɒʒm
    //                BN_DBLCLICK, BN_KILLFORCUS, BN_SETFOCUS���b�Z�[�W��L���ɂ���
    // �� �����ݒ肵�Ȃ��ƁA�_�u���N���b�N�����L���ɂȂ�Ȃ��Ƃ���
    CreateNotifyButton();
    return TRUE;
}

void CButtonDialog::Create3StateButton()
{
    m_buttons[m_index++]->Create(
        _T("3State(No Events)"), BS_3STATE | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(0, 0, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateAuto3StateButton()
{
    m_buttons[m_index++]->Create(
        _T("Auto3State(With Event)"), BS_AUTO3STATE | WS_VISIBLE, 
        CCommonUtility::CreateBlockRect(1, 0, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateAutoCheckBox()
{
    m_buttons[m_index++]->Create(
        _T("AutoCheckBox(With Event)"), BS_AUTOCHECKBOX | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(2, 0, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateAutoRadioButton()
{
    m_buttons[m_index++]->Create(
        _T("AutoRadioButton(With Event)"), BS_AUTORADIOBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(3, 0, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateCheckBox()
{
    m_buttons[m_index++]->Create(
        _T("CheckBox(No Events)"), BS_CHECKBOX | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(4, 0, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateCommandLink()
{
    CButton *button = m_buttons[m_index];
    CBitmap bitmap;
    button->Create(_T("Command Link"), BS_COMMANDLINK | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(5, 0, 3, 10), this, m_button_id++);
    button->SetNote(_T("[Note] With No Events"));
    bitmap.LoadBitmap(IDC_BITMAP1);
    m_buttons[m_index]->SetBitmap(bitmap);
    bitmap.DeleteObject();
    m_index++;
}

void CButtonDialog::CreateDefCommandLink()
{
    CButton *button = m_buttons[m_index];
    CBitmap bitmap;
    button->Create(_T("Command Link"), BS_DEFCOMMANDLINK | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(8, 0, 3, 10), this, m_button_id++);
    button->SetNote(_T("[Note] With Event"));
    bitmap.LoadBitmap(IDC_BITMAP1);
    m_buttons[m_index]->SetBitmap(bitmap);
    bitmap.DeleteObject();
    m_index++;
}

void CButtonDialog::CreateDefPushButton()
{
    m_buttons[m_index++]->Create(
        _T("Def Push Button"), BS_DEFPUSHBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(11, 0, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateDefSplitButton()
{
    m_buttons[m_index++]->Create(
        _T("Def Split Button"), BS_DEFSPLITBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(12, 0, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateGroupBox()
{
    // BS_GROUP�̓O���[�s���O�p�̃X�^�C��
    // �����ڂ��O���[�s���O���ۂ����邾���ŁA�q�v�f���܂Ƃ߂�@�\�͖���
    // (���W�I�{�^�����܂Ƃ߂�ꍇ�́A���W�I�{�^�����̃X�^�C���Œ�`���邵�ˁB�B�B)
    CButton *group = m_buttons[m_index++];
    group->Create(_T("Group Box"), BS_GROUPBOX | WS_VISIBLE | WS_CHILD,
        CCommonUtility::CreateBlockRect(13, 0, 2, 10), this, m_button_id++);
    // �O���[�v���̃{�^���쐬
    // �{�^���P
    CButton *item1 = m_buttons[m_index++];
    item1->Create(_T("A"), BS_AUTORADIOBUTTON | WS_GROUP | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(14, 1, 1, 3), this, m_button_id++);
    item1->SetWindowPos(group, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    // �{�^���Q
    CButton *item2 = m_buttons[m_index++];
    item2->Create(_T("B"), BS_AUTORADIOBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(14, 4, 1, 3), this, m_button_id++);
    item2->SetWindowPos(group, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

void CButtonDialog::CreateOwnerDrawButton()
{
    // CBitmapButton�𗘗p����ۂɂ́AOwnerDraw��ݒ肷��K�v������炵��
    // http://www7b.biglobe.ne.jp/~makandat/VC/Group6/OwnerDraw.htm
    CBitmapButton *button = m_bitmap_button;
    button->Create(_T("OwnerDraw"), BS_PUSHBUTTON | BS_OWNERDRAW | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(15, 5, 1, 10), this, m_button_id++);
    button->LoadBitmaps(IDC_BITMAP1, IDC_BITMAP2);
    button->SizeToContent(); // Bitmap�̃T�C�Y�ɍ��킹��
}

void CButtonDialog::CreatePushButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("PushButton"), BS_PUSHBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(16, 0, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateRadioButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("RadioButton"), BS_RADIOBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(17, 0, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateSplitButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("SplitButton"), BS_SPLITBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(18, 0, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateCheckBoxLeftText()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("LeftText"), BS_LEFTTEXT | BS_AUTOCHECKBOX | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(0, 11, 1, 5), this, m_button_id++);
}

void CButtonDialog::CreateCheckBoxRightButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("RightButton"), BS_RIGHTBUTTON | BS_AUTOCHECKBOX | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(1, 11, 1, 5), this, m_button_id++);
}

void CButtonDialog::CreateCheckBoxPushLike()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("PushLikeCheckBox"), BS_PUSHLIKE | BS_AUTOCHECKBOX | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(2, 11, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateLeftAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Left"), BS_LEFT | BS_PUSHBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(3, 11, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateRightAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Right"), BS_RIGHT | BS_PUSHBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(4, 11, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateCenterAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Holizontal Center"), BS_CENTER | BS_PUSHBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(5, 11, 1, 10), this, m_button_id++);
}

void CButtonDialog::CreateTopAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Top"), BS_TOP | BS_PUSHBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(6, 11, 3, 10), this, m_button_id++);
}

void CButtonDialog::CreateBottomAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Bottom"), BS_BOTTOM | BS_PUSHBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(9, 11, 3, 10), this, m_button_id++);
}

void CButtonDialog::CreateVerticalCenterAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Vertical Center"), BS_VCENTER | BS_PUSHBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(12, 11, 3, 10), this, m_button_id++);
}

void CButtonDialog::CreateBitmapButton()
{
    CBitmap bitmap;
    CButton *button = m_buttons[m_index++];
    button->Create(
        _T("BitMap"), BS_BITMAP | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(0, 21 ,1, 10), this, m_button_id++);
    bitmap.LoadBitmap(IDC_BITMAP1);
    button->SetBitmap(bitmap);
    bitmap.DeleteObject();
}

void CButtonDialog::CreateIconButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Icon"), BS_ICON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(1, 21 ,1, 10), this, m_button_id++);
    HICON hIcon = AfxGetApp()->LoadIcon(IDC_ICON_BUTTON3);
    button->SetIcon(hIcon);
    DestroyIcon(hIcon);
}

void CButtonDialog::CreateTextButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Text"), BS_TEXT | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(2, 21 ,1, 10), this, m_button_id++);
}

void CButtonDialog::CreateFlatButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Flat"), BS_FLAT | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(3, 21 ,1, 10), this, m_button_id++);
}

void CButtonDialog::CreateMultiLineButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("MultiLine======================="), BS_MULTILINE | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(4, 21 ,2, 10), this, m_button_id++);
}

void CButtonDialog::CreateNotifyButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Notify"), BS_NOTIFY | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(6, 21 ,1, 10), this, IDC_BUTTON_SAMPLE1);
}

void CButtonDialog::OnDoubleClicked()
{
    TRACE("Double Clicked!!!\n");
}


void CButtonDialog::InitDialog()
{
    // �_�C�A���O�T�C�Y�ݒ�
    CRect rect = CCommonUtility::CCommonUtility::CreateBlockRect(0, 0, 25, 40);
    //int width = BLOCK_SIZE * 40;
    //int height = BLOCK_SIZE * 25;
    int width = rect.Width();
    int height = rect.Height();
    SetWindowPos(this, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER);

    // �{�^���z�u(OK)
    CButton *okButton = (CButton*)GetDlgItem(IDOK);
    okButton->MoveWindow(0, 425, 75, 25);
}
