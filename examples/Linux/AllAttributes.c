#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ConsoleColor.h"


int main(int argc, char** argv) {
    const char* attributes[] = {C_YELLOW, BG_WHITE};
    c_setAll(attributes, 2);
    printf("This Text Is Yellow And It's Background Is White!\n");
    c_reset();
    return 0;
}