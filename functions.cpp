#include "main.h"
#include "functions.h"
#include "console.h"

stable table;
spiece** p;

COORD viTriConTro; 
bool suDungPhim = false;

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
    createBomb();
    drawTable();
    //exportBomb();
    //deleteArray();
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
        for (int j = 0; j < table.C; j++){
            if ((i + j) % 2) drawPiece(j, i, 11); // vẽ ô lẻ
            else drawPiece(j, i, 10); // vẽ ô chẵn
            if (suDungPhim) {
                drawPiece(viTriConTro.X, viTriConTro.Y, 12);
            }
        }
}
    
void createBomb() {
    short soBom = table.B;
    short sx, sy; // vị trí dòng/cột sẽ ramdom bom
    srand(time(NULL));
    while (soBom) {
        sx = rand() % table.R;
        sy = rand() % table.C;
        if (p[sx][sy].bBom)
            continue;
        p[sx][sy].bBom = true;
        --soBom;
    } 
}

void exportBomb() {
    for (int i = 0; i < table.R; i++) {
        for (int j = 0; j < table.C; j++) {
            std::cout << p[i][j].bBom << " ";
        }
        std::cout << std::endl;
    }  
}

void xuLyPhim(KEY_EVENT_RECORD key) {
    if (key.bKeyDown) { // có nhấn phím
        switch (key.wVirtualKeyCode) {
        case VK_UP: // lên xuống trái phải
            //std::cout << "Len" << std::endl;
            suDungPhim = true;
            viTriConTro.Y = ((viTriConTro.Y == 0) ? table.R - 1 : viTriConTro.Y - 1);
            drawTable();
            break; 
        case VK_DOWN: 
            //std::cout << "xuong" << std::endl;
            suDungPhim = true;
            viTriConTro.Y = ((viTriConTro.Y == table.R - 1) ? 0 : viTriConTro.Y + 1);
            drawTable();
            break;
        case VK_LEFT: 
            //std::cout << "trai" << std::endl;
            suDungPhim = true;
            viTriConTro.X = ((viTriConTro.X == 0) ? table.C - 1 : viTriConTro.X - 1);
            drawTable();
            break;
        case VK_RIGHT: 
            //std::cout << "phai" << std::endl;
            suDungPhim = true;
            viTriConTro.X = ((viTriConTro.X == table.C - 1 ) ? 0 : viTriConTro.X + 1);
            drawTable();
            break;
        case VK_RETURN: // Enter
            std::cout << "enter" << std::endl;
            break; 
        case VK_ESCAPE: // phím Esc để thoát
            std::cout << "esc" << std::endl;
            break; 
        case ClickPhai : // phím X cắm cờ
            std::cout << "x" << std::endl;
            break; 
        case ClickTrai : // phím Z mở ô
            std::cout << "z" << std::endl;
            break; 
        }
    }
}

void xuLySuKien() {
    while (1) {
        DWORD NumberOfEvents = 0; // Lưu lại sự kiện hiện tại
        DWORD NumbeOfEventsRead = 0; // Lưu lại số lượng sự kiện đã được lọc

        HANDLE HConsoleInput = GetStdHandle(STD_INPUT_HANDLE); // thiết bị đầu vào
        GetNumberOfConsoleInputEvents(HConsoleInput, &NumberOfEvents); // Đặt sự kiện đầu vào cho biến NOE

        // Chạy vòng lặp để đọc sự kiện
        if (NumberOfEvents) {
            INPUT_RECORD* IREventBuffer = new INPUT_RECORD[NumberOfEvents]; // con trỏ EventBuffer
            ReadConsoleInput(HConsoleInput, IREventBuffer, NumberOfEvents, &NumbeOfEventsRead); // Đặt các sự kiện được lưu vào EventBuffer
            for (DWORD i = 0; i < NumberOfEvents; ++i) {
                if (IREventBuffer[i].EventType == KEY_EVENT) { // sự kiện là phím
                    xuLyPhim(IREventBuffer[i].Event.KeyEvent);
                }
                //if (IREventBuffer[i].EventType == MOUSE_EVENT) { // sự kiện chuột

                //}
            }
        }
    }
}
