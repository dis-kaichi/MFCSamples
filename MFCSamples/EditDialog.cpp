// EditDialog.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MFCSamples.h"
#include "EditDialog.h"
#include "afxdialogex.h"
#include "CommonUtility.h"


// CEditDialog �_�C�A���O

IMPLEMENT_DYNAMIC(CEditDialog, CDialog)

CEditDialog::CEditDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_EDITDIALOG, pParent)
    , m_edit_id(EDIT_BASE_ID)
    , m_index(0)
    , m_current_edit_id(EDIT_BASE_ID)
    , m_is_shift_pressed(false)
{
    m_num_of_edits = 100;
    m_edits = new CEdit*[m_num_of_edits];
    for (int i = 0; i < m_num_of_edits; i++) {
        m_edits[i] = new CEdit;
    }
}

CEditDialog::~CEditDialog()
{
    for (int i = 0; i < m_num_of_edits; i++) {
        delete m_edits[i];
    }
    delete m_edits;
}

BEGIN_MESSAGE_MAP(CEditDialog, CDialog)
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CEditDialog::Open()
{
    DoModal();
}

void CEditDialog::InitEditSamples()
{
    RedrawWindow();
}

void CEditDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CEditDialog::OnOK()
{
    // Enter�ŕ��Ȃ��悤�ɂ���
    //__super::OnOK();
}

BOOL CEditDialog::PreTranslateMessage(MSG * pMsg)
{
    switch (pMsg->message) {
    case WM_KEYDOWN:
        switch (pMsg->wParam) {
        case VK_TAB:
            if (IsShiftPressed())
                GotoDlgCtrl(GetDlgItem(GetPreviousEditId()));
            else
                GotoDlgCtrl(GetDlgItem(GetNextEditId()));
            return TRUE;
        case VK_SHIFT:
            m_is_shift_pressed = true;
            return TRUE;
        }
    case WM_KEYUP:
        switch (pMsg->wParam) {
        case VK_SHIFT:
            m_is_shift_pressed = false;
            return TRUE;
        }
    }
    return __super::PreTranslateMessage(pMsg);
}

BOOL CEditDialog::OnInitDialog()
{
    InitDialog();

    // �G�f�B�b�g�{�b�N�X�C�x���g�͈ȉ����Q��
    // https://msdn.microsoft.com/ja-jp/library/6e36b89f.aspx

    // ES_AUTOHSCROLL : �����������X�N���[��
    CreateAutoHScroll();
    // ES_AUTOVSCROLL : �c���������X�N���[��
    CreateAutoVScroll();
    // ES_CENTER : ��������
    CreateCenter();
    // ES_LEFT : ������
    CreateLeft();
    // ES_LOWERCASE : �������ϊ�
    CreateLowerCase();
    // ES_MULTILINE : �����s
    CreateMultiLine();
    // ES_NOHIDESEL : �I����Ԃ������������̃A�N�V�������폜����
    CreateNoHideSel();
    // ES_NUMBER : ���l�̂ݓ���
    CreateNumber();
    // ES_OEMCONVERT : ANSI(Windows�����Z�b�g)��OEM�ɕϊ����A���̌�ANSI�ɕϊ������H
    //               : ANSI��OEM�ɂ��͈ȉ��̃����N���Q��
    // http://docs.embarcadero.com/products/rad_studio/radstudio2007/RS2007_helpupdates/HUpdate4/JA/html/devwin32/intappsoemandansicharactersets_xml.html
    CreateOEMConvert();
    // ES_PASSWORD : �p�X���[�h("*"�Œu����������)
    CreatePassword();
    // ES_READONLY : �ҏW�s��
    CreateReadoOnly();
    // ES_RIGHT : �E����
    CreateRight();
    // ES_UPPPERCASE : �啶���ϊ�
    CreateUpperCase();
    // ES_WANTRETURN : Return��������CR��}������(�����s�̉��s���͂�������)
    CreateWantReturn();

    InitFocus();
    // �A�C�e����Focus�𓖂Ă�ׂ�FALSE�ɂ���
    return FALSE;
}

void CEditDialog::CreateAutoHScroll()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_AUTOHSCROLL | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(0, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("AutoHScroll"));
}

void CEditDialog::CreateAutoVScroll()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_AUTOVSCROLL | ES_MULTILINE | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(1, 0, 2, 10), this, m_edit_id++);
    edit->SetWindowText(_T("AutoVScroll"));
}

void CEditDialog::CreateCenter()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_CENTER | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(3, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("Center"));
}

void CEditDialog::CreateLeft()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_LEFT | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(4, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("Left"));
}

void CEditDialog::CreateLowerCase()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_LOWERCASE | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(5, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("LowerCase"));
}

void CEditDialog::CreateMultiLine()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_MULTILINE | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(6, 0, 2, 10), this, m_edit_id++);
    edit->SetWindowText(_T("MultiLine"));
}

void CEditDialog::CreateNoHideSel()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_NOHIDESEL | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(8, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("NoHideCell"));
}

void CEditDialog::CreateNumber()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_NUMBER | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(9, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("0123456789"));
}

void CEditDialog::CreateOEMConvert()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_OEMCONVERT | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(10, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("OEMConvert"));
}

void CEditDialog::CreatePassword()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_PASSWORD | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(11, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("Password"));
}

void CEditDialog::CreateReadoOnly()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_READONLY | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(12, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("ReadOnly"));
}

void CEditDialog::CreateRight()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_RIGHT | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(13, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("Right"));
}

void CEditDialog::CreateUpperCase()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_UPPERCASE | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(14, 0, 1, 10), this, m_edit_id++);
    edit->SetWindowText(_T("Uppercase"));
}

void CEditDialog::CreateWantReturn()
{
    CEdit *edit = m_edits[m_index++];
    edit->Create(
        ES_WANTRETURN | ES_MULTILINE | WS_VISIBLE,
        CCommonUtility::CreateBlockRect(15, 0, 2, 10), this, m_edit_id++);
    edit->SetWindowText(_T("WantReturn"));
}

void CEditDialog::InitDialog()
{
    // �_�C�A���O�T�C�Y�ݒ�
    CRect rect = CCommonUtility::CCommonUtility::CreateBlockRect(0, 0, 25, 40);
    int width = rect.Width();
    int height = rect.Height();
    SetWindowPos(this, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER);

    // �{�^���z�u(OK)
    CButton *okButton = (CButton*)GetDlgItem(IDOK);
    okButton->MoveWindow(0, 425, 75, 25);
}

UINT CEditDialog::GetPreviousEditId()
{
    m_current_edit_id--;
    if (m_current_edit_id < EDIT_BASE_ID)
        m_current_edit_id = m_edit_id - 1;
    return m_current_edit_id;
}

bool CEditDialog::IsShiftPressed()
{
    return m_is_shift_pressed;
}

UINT CEditDialog::GetNextEditId()
{
    m_current_edit_id++;
    if (m_current_edit_id >= m_edit_id)
        m_current_edit_id = EDIT_BASE_ID;
    return m_current_edit_id;
}

void CEditDialog::InitFocus()
{
    CEdit *edit = m_edits[0];
    edit->SetFocus();
    edit->SetSel(0, -1); // �S�I��
}
