#include <stdio.h>
#include "ConsoleColor.h"

int main(int argc, char** argv) {
    c_reset();
    c_setAttribute(BG_RED);
    printf("This is an error box!");
    c_reset();
    printf("\n");
    c_setAttribute(BG_BLUE);
    printf("This is a message box!");
    c_reset();
    printf("\n");
    c_setAttribute(BG_GREEN);
    printf("This is a success box!");
    c_reset();
    printf("\n");
    c_setAttribute(BG_YELLOW);
    printf("This is a warning box!");
    c_reset();
    printf("\n");
}