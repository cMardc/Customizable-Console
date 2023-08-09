#include <stdio.h>
#include <stdlib.h>
#include "ConsoleColor.h"

int main(int argc, char** argv) {
    c_setAttribute(C_BLACK);
    c_setAttribute("H");
    c_setAttribute(C_RED);
    c_setAttribute("E");
    c_setAttribute(C_GREEN);
    c_setAttribute("L");
    c_setAttribute("L");
    c_setAttribute(C_BLUE);
    c_setAttribute("O");
    c_setAttribute(C_MAGENTA);
    c_setAttribute(", ");
    c_setAttribute(C_CYAN);
    c_setAttribute("W");
    c_setAttribute(C_BLUE);
    c_setAttribute("O");
    c_setAttribute(C_YELLOW);
    c_setAttribute("R");
    c_setAttribute(C_GREEN);
    c_setAttribute("L");
    c_setAttribute(C_WHITE);
    c_setAttribute("D\n");
    c_reset();
    return 0;
}