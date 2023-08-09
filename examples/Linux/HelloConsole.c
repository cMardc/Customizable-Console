#include <stdio.h>
#include "ConsoleColor.h"

int main(int argc, char** argv) {
    c_reset();
    c_setAttribute(C_RED);
    c_draw_text_box(7, '*', '|', '=', "         Hello Console!        ");
    c_reset();
    return 0;
}