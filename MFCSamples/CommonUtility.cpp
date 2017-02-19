#include "stdafx.h"
#include "CommonUtility.h"


CCommonUtility::CCommonUtility()
{

}

CRect CCommonUtility::CreateBlockRect(int i, int j, int rows, int cols) {
    int left = j * BLOCK_SIZE;
    int top = i * BLOCK_SIZE;
    int right = (j + cols) * BLOCK_SIZE;
    int bottom = (i + rows) * BLOCK_SIZE;
    return CRect(left, top, right, bottom);
}
