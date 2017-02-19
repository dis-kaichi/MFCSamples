#pragma once

class UserDialogInterface
{
public:
    virtual ~UserDialogInterface() {}
    virtual void Open() = 0;
};