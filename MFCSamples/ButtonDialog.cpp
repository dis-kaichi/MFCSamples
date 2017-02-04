// ButtonDialog.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MFCSamples.h"
#include "ButtonDialog.h"
#include "afxdialogex.h"


// CButtonDialog ダイアログ

IMPLEMENT_DYNAMIC(CButtonDialog, CDialogEx)

BEGIN_MESSAGE_MAP(CButtonDialog, CDialogEx)
    ON_BN_DOUBLECLICKED(IDC_BUTTON1, OnDoubleClicked)
END_MESSAGE_MAP()


CButtonDialog::CButtonDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BUTTONDIALOG, pParent)
    , m_buttonId(BUTTON_BASE_ID)
    , m_index(0)
{
    m_numOfButtons = 100;
    m_buttons = new CButton*[m_numOfButtons];
    for (int i = 0; i < m_numOfButtons; i++) {
        m_buttons[i] = new CButton;
    }
    m_bitmapButton = new CBitmapButton();
}

CButtonDialog::~CButtonDialog()
{
    for (int i = 0; i < m_numOfButtons; i++) {
        delete m_buttons[i];
    }
    delete m_buttons;
    delete m_bitmapButton;
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
    // ダイアログサイズ
    InitDialog();

    // ボタンイベントは以下を参考
    // https://msdn.microsoft.com/ja-jp/library/tf9hd91s.aspx
    // [Notice]
    //   イベント無 : 自分でイベントをつける必要がある
    //   イベント有 : デフォルトのイベント設定がある

    ////////////////////////////////////////////////////////////
    // Button Styles
    ////////////////////////////////////////////////////////////
    // BS_3STATE : 3状態ボタン(イベント無)
    Create3StateButton();
    // BS_AUTO3STATE : 3状態ボタン(イベント有)
    CreateAuto3StateButton();
    // BS_AUTOCHECKBOX : チェックボックス(イベント有)
    CreateAutoCheckBox();
    // BS_AUTORADIOBUTTON : ラジオボタン(イベント有)
    CreateAutoRadioButton();
    // BS_AUTOCHECKBOX : チェックボックス(イベント無)
    CreateCheckBox();
    // BS_COMMANDLINK : Command Link (イベント無)
    CreateCommandLink();
    // BS_DEFCOMMANDLINK : Command Link (イベント有)
    CreateDefCommandLink();
    // BS_DEFPUSHBUTTON : Push Button (イベント有; 境界線が黒い？)
    CreateDefPushButton();
    // BS_DEFSPLITBUTTON : Split Button (イベント有)
    CreateDefSplitButton();
    // BS_GROUPBOX : Group Box (イベント有)
    CreateGroupBox();
    // BS_OWNERDRAW : Owner Draw
    CreateOwnerDrawButton();
    // BS_PUSHBUTTON : Push Button
    CreatePushButton();
    // BS_RADIOBUTTON : Radio Button(イベント無)
    CreateRadioButton();
    // BS_SPLITBUTTON : Split Button(イベント無)
    CreateSplitButton();

    ////////////////////////////////////////////////////////////
    // Option(Radio) Button or Check Box Only
    ////////////////////////////////////////////////////////////
    // BS_LEFTTEXT : 左側にテキスト表示
    CreateCheckBoxLeftText();
    // BS_RIGHTBUTTON : 左側にテキスト表示(BS_LEFTTEXTと同じ挙動)
    CreateCheckBoxRightButton();
    // BS_PUSHLIKE : コマンドボタンライクにする
    CreateCheckBoxPushLike();

    ////////////////////////////////////////////////////////////
    // Text Alignment
    ////////////////////////////////////////////////////////////
    // BS_LEFT : 左寄せ
    CreateLeftAlign();
    // BS_RIGHT : 右寄せ
    CreateRightAlign();
    // BS_CENTER : 中央寄せ
    CreateCenterAlign();
    // BS_TOP : 上寄せ
    CreateTopAlign();
    // BS_BOTTOM : 下寄せ
    CreateBottomAlign();
    // BS_VCENTER : 縦方向中央寄せ
    CreateVerticalCenterAlign();

    ////////////////////////////////////////////////////////////
    // ボタンの内容に関するOption
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
    // BS_FLAT      : フラット
    CreateFlatButton();
    // BS_MULTILINE : 文字が長い場合に複数行にする
    CreateMultiLineButton();
    // BS_NOTIFY    : 親Windowに通知
    //                BN_DBLCLICK, BN_KILLFORCUS, BN_SETFOCUSメッセージを有効にする
    // ※ これを設定しないと、ダブルクリック等が有効にならないという
    CreateNotifyButton();
    return TRUE;
}

void CButtonDialog::Create3StateButton()
{
    m_buttons[m_index++]->Create(
        _T("3State(No Events)"), BS_3STATE | WS_VISIBLE,
        CreateBlockRect(0, 0, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateAuto3StateButton()
{
    m_buttons[m_index++]->Create(
        _T("Auto3State(With Event)"), BS_AUTO3STATE | WS_VISIBLE, 
        CreateBlockRect(1, 0, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateAutoCheckBox()
{
    m_buttons[m_index++]->Create(
        _T("AutoCheckBox(With Event)"), BS_AUTOCHECKBOX | WS_VISIBLE,
        CreateBlockRect(2, 0, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateAutoRadioButton()
{
    m_buttons[m_index++]->Create(
        _T("AutoRadioButton(With Event)"), BS_AUTORADIOBUTTON | WS_VISIBLE,
        CreateBlockRect(3, 0, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateCheckBox()
{
    m_buttons[m_index++]->Create(
        _T("CheckBox(No Events)"), BS_CHECKBOX | WS_VISIBLE,
        CreateBlockRect(4, 0, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateCommandLink()
{
    CButton *button = m_buttons[m_index];
    CBitmap bitmap;
    button->Create(_T("Command Link"), BS_COMMANDLINK | WS_VISIBLE,
        CreateBlockRect(5, 0, 3, 10), this, m_buttonId++);
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
        CreateBlockRect(8, 0, 3, 10), this, m_buttonId++);
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
        CreateBlockRect(11, 0, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateDefSplitButton()
{
    m_buttons[m_index++]->Create(
        _T("Def Split Button"), BS_DEFSPLITBUTTON | WS_VISIBLE,
        CreateBlockRect(12, 0, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateGroupBox()
{
    // BS_GROUPはグルーピング用のスタイル
    // 見た目をグルーピングっぽくするだけで、子要素をまとめる機能は無い
    // (ラジオボタンをまとめる場合は、ラジオボタン側のスタイルで定義するしね。。。)
    CButton *group = m_buttons[m_index++];
    group->Create(_T("Group Box"), BS_GROUPBOX | WS_VISIBLE | WS_CHILD,
        CreateBlockRect(13, 0, 2, 10), this, m_buttonId++);
    // グループ内のボタン作成
    // ボタン１
    CButton *item1 = m_buttons[m_index++];
    item1->Create(_T("A"), BS_AUTORADIOBUTTON | WS_GROUP | WS_VISIBLE,
        CreateBlockRect(14, 1, 1, 3), this, m_buttonId++);
    item1->SetWindowPos(group, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    // ボタン２
    CButton *item2 = m_buttons[m_index++];
    item2->Create(_T("B"), BS_AUTORADIOBUTTON | WS_VISIBLE,
        CreateBlockRect(14, 4, 1, 3), this, m_buttonId++);
    item2->SetWindowPos(group, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

void CButtonDialog::CreateOwnerDrawButton()
{
    // CBitmapButtonを利用する際には、OwnerDrawを設定する必要があるらしい
    // http://www7b.biglobe.ne.jp/~makandat/VC/Group6/OwnerDraw.htm
    CBitmapButton *button = m_bitmapButton;
    button->Create(_T("OwnerDraw"), BS_PUSHBUTTON | BS_OWNERDRAW | WS_VISIBLE,
        CreateBlockRect(15, 5, 1, 10), this, m_buttonId++);
    button->LoadBitmaps(IDC_BITMAP1, IDC_BITMAP2);
    button->SizeToContent(); // Bitmapのサイズに合わせる
}

void CButtonDialog::CreatePushButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("PushButton"), BS_PUSHBUTTON | WS_VISIBLE,
        CreateBlockRect(16, 0, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateRadioButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("RadioButton"), BS_RADIOBUTTON | WS_VISIBLE,
        CreateBlockRect(17, 0, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateSplitButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("SplitButton"), BS_SPLITBUTTON | WS_VISIBLE,
        CreateBlockRect(18, 0, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateCheckBoxLeftText()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("LeftText"), BS_LEFTTEXT | BS_AUTOCHECKBOX | WS_VISIBLE,
        CreateBlockRect(0, 11, 1, 5), this, m_buttonId++);
}

void CButtonDialog::CreateCheckBoxRightButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("RightButton"), BS_RIGHTBUTTON | BS_AUTOCHECKBOX | WS_VISIBLE,
        CreateBlockRect(1, 11, 1, 5), this, m_buttonId++);
}

void CButtonDialog::CreateCheckBoxPushLike()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("PushLikeCheckBox"), BS_PUSHLIKE | BS_AUTOCHECKBOX | WS_VISIBLE,
        CreateBlockRect(2, 11, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateLeftAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Left"), BS_LEFT | BS_PUSHBUTTON | WS_VISIBLE,
        CreateBlockRect(3, 11, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateRightAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Right"), BS_RIGHT | BS_PUSHBUTTON | WS_VISIBLE,
        CreateBlockRect(4, 11, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateCenterAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Holizontal Center"), BS_CENTER | BS_PUSHBUTTON | WS_VISIBLE,
        CreateBlockRect(5, 11, 1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateTopAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Top"), BS_TOP | BS_PUSHBUTTON | WS_VISIBLE,
        CreateBlockRect(6, 11, 3, 10), this, m_buttonId++);
}

void CButtonDialog::CreateBottomAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Bottom"), BS_BOTTOM | BS_PUSHBUTTON | WS_VISIBLE,
        CreateBlockRect(9, 11, 3, 10), this, m_buttonId++);
}

void CButtonDialog::CreateVerticalCenterAlign()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Vertical Center"), BS_VCENTER | BS_PUSHBUTTON | WS_VISIBLE,
        CreateBlockRect(12, 11, 3, 10), this, m_buttonId++);
}

void CButtonDialog::CreateBitmapButton()
{
    CBitmap bitmap;
    CButton *button = m_buttons[m_index++];
    button->Create(
        _T("BitMap"), BS_BITMAP | WS_VISIBLE,
        CreateBlockRect(0, 21 ,1, 10), this, m_buttonId++);
    bitmap.LoadBitmap(IDC_BITMAP1);
    button->SetBitmap(bitmap);
    bitmap.DeleteObject();
}

void CButtonDialog::CreateIconButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Icon"), BS_ICON | WS_VISIBLE,
        CreateBlockRect(1, 21 ,1, 10), this, m_buttonId++);
    HICON hIcon = AfxGetApp()->LoadIcon(IDC_ICON_BUTTON3);
    button->SetIcon(hIcon);
    DestroyIcon(hIcon);
}

void CButtonDialog::CreateTextButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Text"), BS_TEXT | WS_VISIBLE,
        CreateBlockRect(2, 21 ,1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateFlatButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Flat"), BS_FLAT | WS_VISIBLE,
        CreateBlockRect(3, 21 ,1, 10), this, m_buttonId++);
}

void CButtonDialog::CreateMultiLineButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("MultiLine======================="), BS_MULTILINE | WS_VISIBLE,
        CreateBlockRect(4, 21 ,2, 10), this, m_buttonId++);
}

void CButtonDialog::CreateNotifyButton()
{
    CButton *button = m_buttons[m_index++];
    button->Create(_T("Notify"), BS_NOTIFY | WS_VISIBLE,
        CreateBlockRect(6, 21 ,1, 10), this, IDC_BUTTON1);
}

void CButtonDialog::OnDoubleClicked()
{
    TRACE("Double Clicked!!!\n");
}


void CButtonDialog::InitDialog()
{
    // ダイアログサイズ設定
    int width = BLOCK_SIZE * 40;
    int height = BLOCK_SIZE * 25;
    SetWindowPos(this, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER);

    // ボタン配置(OK)
    CButton *okButton = (CButton*)GetDlgItem(IDOK);
    okButton->MoveWindow(0, 425, 75, 25);
}

CRect CButtonDialog::CreateBlockRect(int i, int j, int rows, int cols) {
    int left = j * BLOCK_SIZE;
    int top = i * BLOCK_SIZE;
    int right = (j + cols) * BLOCK_SIZE;
    int bottom = (i + rows) * BLOCK_SIZE;
    return CRect(left, top, right, bottom);
}



// CButtonDialog メッセージ ハンドラー
