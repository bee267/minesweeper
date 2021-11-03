#include "main.h"
#include "functions.h"
#include "console.h"

stable table;
spiece** p;

void createArray() {
    p = new spiece * [table.R];
    for (int i = 0; i < table.R; i++) p[i] = new spiece[table.C];
}

void deleteArray() {
    for (int i = 0; i < table.R; i++) delete p[i];
    delete[] p;
}
void constructor(short R, short C, short B) {
    table.R = R;
    table.C = C;
    table.B = B;
    table.O = 0;
    table.F = 0;
    createArray();
    deleteArray();
}
short toaDoX(short x) { // toạ độ x vẽ bảng
    return x * 2 ;
}
short toaDoY(short y) { // toạ độ y vẽ bảng
    return y;
}
void drawPiece(short x, short y, short color) {
    switch (color) {
    case 0: // ô không có bom màu xanh lá
        setColorBGTextXY(toaDoX(x), toaDoY(y), 0, 10, const_cast<char*>("  "));
        break;
    // 1 đến 8 là nền trắng, chỉ số bom xung quanh ô
    case 1: // màu xanh dương
        setColorBGTextXY(toaDoX(x), toaDoY(y), 9, 15, const_cast<char*>("1 "));
        break;
    case 2: // xanh lá
        setColorBGTextXY(toaDoX(x), toaDoY(y), 2, 15, const_cast<char*>("2 "));
        break;
    case 3: // đỏ
        setColorBGTextXY(toaDoX(x), toaDoY(y), 12, 15, const_cast<char*>("3 "));
        break;
    case 4: // xanh dương đậm
        setColorBGTextXY(toaDoX(x), toaDoY(y), 1, 15, const_cast<char*>("4 "));
        break;
    case 5: // đỏ đậm
        setColorBGTextXY(toaDoX(x), toaDoY(y), 4, 15, const_cast<char*>("5 "));
        break;
    case 6: // Cyan đậm
        setColorBGTextXY(toaDoX(x), toaDoY(y), 3, 15, const_cast<char*>("6 "));
        break;
    case 7: // đen 
        setColorBGTextXY(toaDoX(x), toaDoY(y), 0, 15, const_cast<char*>("7 "));
        break;
    case 8: // hồng
        setColorBGTextXY(toaDoX(x), toaDoY(y), 13, 15, const_cast<char*>("8 "));
        break;
    case 9: // bom
        setColorBGTextXY(toaDoX(x), toaDoY(y), 0, 12, const_cast<char*>("B "));
        break;
    case 10: // ô chẵn
        setColorBGTextXY(toaDoX(x), toaDoY(y), 0, 8, const_cast<char*>("  "));
        break;
    case 11: // ô lẻ
        setColorBGTextXY(toaDoX(x), toaDoY(y), 0, 7, const_cast<char*>("  "));
        break;
    case 12: // theo dõi con trỏ
        setColorBGTextXY(toaDoX(x), toaDoY(y), 0, 13, const_cast<char*>("  "));
        break;
    case 13: // cắm cờ 
        setColorBGTextXY(toaDoX(x), toaDoY(y), 12, 14, const_cast<char*>("P "));
        break;
    case 14:  // cắm cờ sai, ô không có bom
        setColorBGTextXY(toaDoX(x), toaDoY(y), 15, 16, const_cast<char*>("Px"));
        break;
    case 15: // cắm cờ đúng
        setColorBGTextXY(toaDoX(x), toaDoY(y), 12, 14, const_cast<char*>("  "));
        break;
}
void drawTable(short x, short y, short color) {
    for (int i = 0; i < table.R; i++)
        for (int j = 0; j < table.C; i++)
            drawPiece(j, i, 1);
}
