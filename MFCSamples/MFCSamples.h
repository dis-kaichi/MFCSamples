
// MFCSamples.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMFCSamplesApp:
// このクラスの実装については、MFCSamples.cpp を参照してください。
//

class CMFCSamplesApp : public CWinApp
{
public:
	CMFCSamplesApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMFCSamplesApp theApp;