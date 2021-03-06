
// MFCSamplesDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MFCSamples.h"
#include "MFCSamplesDlg.h"
#include "afxdialogex.h"
#include "CommonUtility.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCSamplesDlg ダイアログ

CMFCSamplesDlg::CMFCSamplesDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(IDD_MFCSAMPLES_DIALOG, pParent)
    , m_alt_key_pressed(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSamplesDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCSamplesDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_COMMAND_RANGE(IDC_MFC_DRIVER_BUTTON1, IDC_MFC_DRIVER_BUTTON100, OnLButtonClicked)
END_MESSAGE_MAP()


// CMFCSamplesDlg メッセージ ハンドラー

BOOL CMFCSamplesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

    // CreateButtons
    m_button_for_button.Create(_T("ButtonSamples"), BS_PUSHBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(0, 0, 1, 10), this, IDC_MFC_DRIVER_BUTTON1);
    m_button_for_edit.Create(_T("EditSamples"), BS_PUSHBUTTON | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(1, 0, 1, 10), this, IDC_MFC_DRIVER_BUTTON2);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMFCSamplesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMFCSamplesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCSamplesDlg::OnLButtonClicked(UINT nID) {
    TRACE("[MFCSamplesDlg] OnLButtonClicked (%d)\n", nID);
    m_button_manager.DriveButton(nID);
}

BOOL CMFCSamplesDlg::PreTranslateMessage(MSG *pMsg) {
    switch (pMsg->message) {
    case WM_SYSKEYDOWN:
        switch (pMsg->wParam) {
        case VK_MENU:
            m_alt_key_pressed = true;
            return TRUE;
        }
    case WM_SYSKEYUP:
        switch (pMsg->wParam) {
        case VK_MENU:
            m_alt_key_pressed = false;
            return TRUE;
        }
    case WM_KEYDOWN:
        switch (pMsg->wParam) {
        case 'A':
            if (IsAltKeyPressed())
                m_button_manager.DriveButton(IDC_MFC_DRIVER_BUTTON1);
            return TRUE;
        case 'B':
            if (IsAltKeyPressed())
                m_button_manager.DriveButton(IDC_MFC_DRIVER_BUTTON2);
            return TRUE;
        }
    }
    return CDialog::PreTranslateMessage(pMsg);
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////

bool CMFCSamplesDlg::IsAltKeyPressed()
{
    return m_alt_key_pressed;
}
