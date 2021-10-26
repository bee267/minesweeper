#include "console.h"
#include "main.h"

int main() {

    setColorBGTextXY(1, 1, 0, 8, const_cast<char*>("B"));
    std::cout << std::endl;
    system("pause");
    return 0;
}