#include <string.h>
#include <stdio.h>
#include <iostream>

#include "dt3106_ini.h"

#define HSW1000CFG_FILE_NAME "ArtPro.ini"

CIniDt3106::CIniDt3106()
{
    snprintf(fname, CINIFLEN, "%s", HSW1000CFG_FILE_NAME);

    this->Load(fname);
}

CIniDt3106::~CIniDt3106()
{

}

void CIniDt3106::test()
{
    WriteInt("IntParam", "axlenum", 12);
    WriteInt("IntParam", "speedlen", 180);

    std::cout << "IntParam axlenum " << ReadInt("IntParam", "axlenum", 15) << std::endl;
    std::cout << "IntParam speedlen " << ReadInt("IntParam", "speedlen", 100) << std::endl;
}
