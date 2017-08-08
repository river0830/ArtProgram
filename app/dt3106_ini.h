#ifndef DT3106_INI_H
#define DT3106_INI_H

#include "iniControl.h"

class CIniDt3106 : public CIniFile
{
public:
    CIniDt3106();
    ~CIniDt3106();

    enum
    {
        CINIFLEN = 128,
    };

    void test();

private:
    char fname[CINIFLEN];
};

#endif // DT3106_INI_H
