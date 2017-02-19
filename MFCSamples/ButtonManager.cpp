#include "stdafx.h"
#include "ButtonManager.h"
#include "ButtonDialog.h"
#include "UserDialogInterface.h"
#include "EditDialog.h"


CButtonManager::CButtonManager()
{
}


CButtonManager::~CButtonManager()
{
}

void CButtonManager::DriveButton(UINT nID)
{
    UserDialogInterface *dialog = nullptr;
    switch (nID) {
    case IDC_MFC_DRIVER_BUTTON1:
        dialog = new CButtonDialog();
        break;
    case IDC_MFC_DRIVER_BUTTON2:
        dialog = new CEditDialog();
        break;
    default:
        break;
    }
    if (nullptr != dialog) {
        dialog->Open();
        delete dialog;
    }
}
