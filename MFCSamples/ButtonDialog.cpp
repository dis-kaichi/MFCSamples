// ButtonDialog.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MFCSamples.h"
#include "ButtonDialog.h"
#include "afxdialogex.h"


// CButtonDialog ダイアログ

IMPLEMENT_DYNAMIC(CButtonDialog, CDialogEx)

CButtonDialog::CButtonDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BUTTONDIALOG, pParent)
{
    m_numOfButtons = 100;
    m_buttons = new CButton*[m_numOfButtons];
    for (int i = 0; i < m_numOfButtons; i++) {
        m_buttons[i] = new CButton;
    }
}

CButtonDialog::~CButtonDialog()
{
    for (int i = 0; i < m_numOfButtons; i++) {
        delete m_buttons[i];
    }
    delete m_buttons;
}

void CButtonDialog::InitButtonSamples()
{
    this->RedrawWindow();
}

void CButtonDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CButtonDialog::OnInitDialog()
{
    // ダイアログサイズ
    SetWindowPos(this, 0, 0, 300, 500, SWP_NOMOVE | SWP_NOZORDER);

    // https://msdn.microsoft.com/ja-jp/library/tf9hd91s.aspx
    CRect rect(0, 0, 200, 20);
    CRect specifyRect;
    int lineNo = 0;
    int index = 0;
    int buttonId = BUTTON_BASE_ID;
    CBitmap bitmap;

    // [Notice]
    //   イベント無 : 自分でイベントをつける必要がある
    //   イベント有 : デフォルトのイベント設定がある

    ////////////////////////////////////////////////////////////
    // 3状態ボタン(イベント無)
    ////////////////////////////////////////////////////////////
    rect.MoveToY(rect.Height() * lineNo);
    m_buttons[index]->Create(_T("3State(No Events)"), BS_3STATE | WS_VISIBLE, rect, this, buttonId);
    lineNo++;
    index++;
    ////////////////////////////////////////////////////////////
    // 3状態ボタン(イベント有)
    ////////////////////////////////////////////////////////////
    rect.MoveToY(rect.Height() * lineNo);
    m_buttons[index]->Create(_T("Auto3State(With Event)"), BS_AUTO3STATE | WS_VISIBLE, rect, this, buttonId++);
    lineNo++;
    index++;
    ////////////////////////////////////////////////////////////
    // チェックボックス(イベント有)
    ////////////////////////////////////////////////////////////
    rect.MoveToY(rect.Height() * lineNo);
    m_buttons[index]->Create(_T("AutoCheckBox(With Event)"), BS_AUTOCHECKBOX | WS_VISIBLE, rect, this, buttonId++);
    lineNo++;
    index++;
    ////////////////////////////////////////////////////////////
    // ラジオボタン(イベント有)
    ////////////////////////////////////////////////////////////
    rect.MoveToY(rect.Height() * lineNo);
    m_buttons[index]->Create(_T("AutoRadioButton(With Event)"), BS_AUTORADIOBUTTON | WS_VISIBLE, rect, this, buttonId++);
    lineNo++;
    index++;
    ////////////////////////////////////////////////////////////
    // チェックボックス(イベント無)
    ////////////////////////////////////////////////////////////
    rect.MoveToY(rect.Height() * lineNo);
    m_buttons[index]->Create(_T("CheckBox(No Events)"), BS_CHECKBOX | WS_VISIBLE, rect, this, buttonId++);
    lineNo++;
    index++;
    ////////////////////////////////////////////////////////////
    // Command Link (イベント無)
    ////////////////////////////////////////////////////////////
    rect.MoveToY(rect.Height() * lineNo);
    specifyRect.SetRectEmpty();
    specifyRect.CopyRect(&rect);
    specifyRect.InflateRect(0, 0, 0, rect.Height() * 2);
    m_buttons[index]->Create(_T("Command Link"), BS_COMMANDLINK | WS_VISIBLE, specifyRect, this, buttonId++);
    m_buttons[index]->SetNote(_T("[Note] With No Events"));
    bitmap.LoadBitmap(IDC_BITMAP_BUTTON1);
    m_buttons[index]->SetBitmap(bitmap);
    bitmap.DeleteObject();
    lineNo += 3;
    index++;
    ////////////////////////////////////////////////////////////
    // Command Link (イベント有)
    ////////////////////////////////////////////////////////////
    rect.MoveToY(rect.Height() * lineNo);
    specifyRect.SetRectEmpty();
    specifyRect.CopyRect(&rect);
    specifyRect.InflateRect(0, 0, 0, rect.Height() * 2);
    m_buttons[index]->Create(_T("Command Link"), BS_DEFCOMMANDLINK | WS_VISIBLE, specifyRect, this, buttonId++);
    m_buttons[index]->SetNote(_T("[Note] With Event"));
    bitmap.LoadBitmap(IDC_BITMAP_BUTTON1);
    m_buttons[index]->SetBitmap(bitmap);
    bitmap.DeleteObject();
    lineNo += 3;
    index++;
    ////////////////////////////////////////////////////////////
    // Push Button (イベント有)
    ////////////////////////////////////////////////////////////
    rect.MoveToY(rect.Height() * lineNo);
    m_buttons[index]->Create(_T("Push Button"), BS_DEFPUSHBUTTON | WS_VISIBLE, rect, this, buttonId++);
    lineNo++;
    index++;
    ////////////////////////////////////////////////////////////
    // Split Button (イベント有)
    ////////////////////////////////////////////////////////////
    rect.MoveToY(rect.Height() * lineNo);
    m_buttons[index]->Create(_T("Split Button"), BS_DEFSPLITBUTTON | WS_VISIBLE, rect, this, buttonId++);
    lineNo++;
    index++;
    ////////////////////////////////////////////////////////////
    // Group Box (イベント有)
    ////////////////////////////////////////////////////////////
    CreateGroupBox(rect, buttonId, lineNo, index);
    ////////////////////////////////////////////////////////////
    // Bitmap
    ////////////////////////////////////////////////////////////
    rect.MoveToY(rect.Height() * lineNo);
    m_buttons[index]->Create(_T("BitMap"), BS_BITMAP | WS_VISIBLE, rect, this, buttonId++);
    bitmap.LoadBitmap(IDC_BITMAP_BUTTON1);
    m_buttons[index]->SetBitmap(bitmap);
    bitmap.DeleteObject();
    lineNo++;
    index++;
    return TRUE;
}

void CButtonDialog::CreateGroupBox(CRect &rect, int &buttonId, int &lineNo, int &index)
{
    // BS_GROUPはグルーピング用のスタイル
    // 見た目をグルーピングっぽくするだけで、子要素をまとめる機能は無い
    // (ラジオボタンをまとめる場合は、ラジオボタン側のスタイルで定義するしね。。。)
    CRect specifyRect;
    rect.MoveToY(rect.Height() * lineNo);
    specifyRect.SetRectEmpty();
    specifyRect.CopyRect(&rect);
    specifyRect.InflateRect(0, 0, 0, rect.Height());
    CButton *group = m_buttons[index++];
    group->Create(_T("Group Box"), BS_GROUPBOX | WS_VISIBLE, specifyRect, this, buttonId++);
    // グループ内のボタン作成
    // ボタン１
    specifyRect.SetRectEmpty();
    int itemY = rect.Height() * (lineNo + 1);
    specifyRect.SetRect(10, itemY, 50, itemY + rect.Height());
    CButton *item1 = m_buttons[index++];
    item1->Create(_T("A"), BS_AUTORADIOBUTTON | WS_GROUP | WS_VISIBLE, specifyRect, this, buttonId++);
    item1->SetWindowPos(group, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    // ボタン２
    specifyRect.SetRectEmpty();
    specifyRect.SetRect(50, itemY, 90, itemY + rect.Height());
    CButton *item2 = m_buttons[index++];
    item2->Create(_T("B"), BS_AUTORADIOBUTTON | WS_VISIBLE, specifyRect, this, buttonId++);
    item2->SetWindowPos(group, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    lineNo += 2;
    index++;
}


BEGIN_MESSAGE_MAP(CButtonDialog, CDialogEx)
END_MESSAGE_MAP()


// CButtonDialog メッセージ ハンドラー
