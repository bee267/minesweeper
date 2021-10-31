#include "main.h"
#include "functions.h"

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
void drawPiece(short x, short y, short color) {
    switch (color) {
    case 0:
    }
}
void drawTable(short x, short y, short color) {
    for (int i = 0; i < table.R; i++)
        for (int j = 0; j < table.C; i++)
            drawPiece(i, j, 1);
}
