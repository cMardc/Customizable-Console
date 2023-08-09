#include <stdio.h>
#include <math.h>
#include "ConsoleColor.h"

int main(int argc, char** argv) {
    c_reset();
    c_errorBox("This is an error box! (X)\n");
    c_warningBox("This is a warning box! (!)\n");
    c_messageBox("This is a message box! (i)\n");
    c_successBox("This is a success box! (v)\n");
    c_reset();
}