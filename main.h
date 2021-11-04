#pragma once
#include<iostream>
#include<ctime>

#define ClickTrai 0x5A
#define ClickPhai 0x58

struct stable
{
    short C = 0;  // column
    short R = 0;  // row
    short B = 0;  // bom
    short O = 0;  // be opened
    short F = 0;  // flat
};

struct spiece
{
    bool bBom = false;
    bool bBeOpened = false;
    bool bFlat = false;
    short Neighbor = 0;
};
