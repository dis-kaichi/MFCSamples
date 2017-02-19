#pragma once
class CCommonUtility
{
public:

    static const int BLOCK_SIZE = 20;
    static CRect CreateBlockRect(int row, int col, int numOfRows, int numOfCols);
private:
    CCommonUtility();
};

