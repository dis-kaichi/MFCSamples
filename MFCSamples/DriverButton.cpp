// DriverButton.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MFCSamples.h"
#include "DriverButton.h"
#include "afxdialogex.h"


// CDriverButton �_�C�A���O

IMPLEMENT_DYNAMIC(CDriverButton, CDialogEx)

CDriverButton::CDriverButton(CWnd* pParent /*=NULL*/)
{
}

CDriverButton::~CDriverButton()
{
}

void CDriverButton::DoDataExchange(CDataExchange* pDX)
{
}


BEGIN_MESSAGE_MAP(CDriverButton, CMFCButton)
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDriverButton ���b�Z�[�W �n���h���[


void CDriverButton::OnLButtonDown(UINT nFlags, CPoint point)
{
    TRACE("[DriverButton] (Flag, x ,y) = (%d, %d, %d)\n", nFlags, point.x, point.y);
    CButtonDialog dialog;
    dialog.DoModal();
    CMFCButton::OnLButtonDown(nFlags, point);
}
