//Starting of ConsoleColor.h file
//This header file helps to you to customize your console applications

#pragma once

//Used files / Headers / Libraries 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <sys/ioctl.h>
#include <unistd.h>

//Pre-defines for escape characters

//Color values
#define C_BLACK "\033[30m"
#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_BLUE "\033[34m"
#define C_MAGENTA "\033[35m"
#define C_CYAN "\033[36m"
#define C_WHITE "\033[37m"

//Background values
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

//Style values
#define S_BOLD "\033[1m"
#define S_DIM "\033[2m"
#define S_UNDERLINED "\033[4m"
#define S_BLINK "\033[5m"
#define S_REVERSE "\033[7m"
#define S_HIDDEN "\033[8m"

//Cursor values
#define R_CLEAR "\033[2J"
#define R_UP "\033[A"
#define R_DOWN "\033[B"
#define R_RIGHT "\033[C"
#define R_LEFT "\033[D"

//Reset value
#define A_RESET "\033[0m"

//Set an attribute for console look
void c_setAttribute(const char* attribute) {
    printf("%s", attribute);
}

//Reset console
void c_reset() {
    printf(A_RESET);
}

//Set more than one Attribute
void c_setAll(const char* attributes[], size_t length) {
    for(size_t i = 0; i < length; i++) {
        c_setAttribute(attributes[i]);
    }
}

// Function to get the current number of rows in the console
int c_get_rows() {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    return ws.ws_row;
}

// Function to get the current number of columns in the console
int c_get_columns() {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    return ws.ws_col;
}


// Function to set the cursor position to an absolute row and column
void c_setCursorPosition(int row, int col) {
    printf("\033[%d;%dH", row, col);
}

// Function to move the cursor to the beginning of a specific row
void c_moveToRow(int row) {
    c_setCursorPosition(row, 1);
}

// Function to move the cursor to the beginning of a specific column
void c_moveToColumn(int col) {
    c_setCursorPosition(1, col);
}

// Function to draw a horizontal line with a specified width
void c_drawHorizontalLine(int width, char horizontalChar) {
    for (int i = 0; i < width; i++) {
        putchar(horizontalChar);
    }
    putchar('\n');
}

//Function to draw a box with given height and width
void c_draw_box(int width, int height, char crossChar, char horizontalChar, char verticalChar) {
    printf("%c", crossChar);
    for(int i = 0; i < width - 2; i++) {
        printf("%c", verticalChar);
    }
    printf("%c\n", crossChar);

    for(int i = 0; i < height - 2; i++) {
        printf("%c", horizontalChar);
        for(int j = 0; j < width - 2; j++) {
            printf("%c", ' ');
        }
        printf("%c\n", horizontalChar);
    }

    printf("%c", crossChar);
    for(int i = 0; i < width - 2; i++) {
        printf("%c", verticalChar);
    }
    printf("%c\n", crossChar);
}

void c_draw_text_box(int height, char crossChar, char horizontalChar, char verticalChar, const char* text) {
    int textPoint = -1;

    if(height % 2 == 0) {
        textPoint = height / 2;
    }   
    else {
        textPoint = height / 2 - 1;
    }

    printf("%c", crossChar);
    for(int i = 0; i < strlen(text); i++) {
        printf("%c", verticalChar);
    }
    printf("%c\n", crossChar);

    for(int i = 0; i < height - 2; i++) {
        printf("%c", horizontalChar);
        if(i == textPoint) {
            printf("%s", text);
        }
        else {
            for(int j = 0; j < strlen(text); j++) {
                printf("%c", ' ');
            }
        }
        printf("%c\n", horizontalChar);
    }

    printf("%c", crossChar);
    for(int i = 0; i < strlen(text); i++) {
        printf("%c", verticalChar);
    }
    printf("%c\n", crossChar);
}



