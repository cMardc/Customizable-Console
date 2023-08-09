#include <stdio.h>
#include "ConsoleColor.h"

int main(int argc, char** argv) {
    c_reset();
    c_errorBox("Alert!!!");
    alertSound();
}