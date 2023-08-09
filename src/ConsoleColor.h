//Customizable Console

//Starting of ConsoleColor.h file
//This header file helps to you to customize your console applications

#pragma once

//Used files / Headers / Libraries 

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#ifdef linux
#include <sys/ioctl.h>
#include <unistd.h>
#elif _WIN32
#include <Windows.h>
#include <stdio.h>
#endif



//Pre-defines for escape characters

//ANSI escape codes

//Color values
#ifdef linux
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

    //ASCII escape codes
    #define E_ALERT '\a'
    #define E_BACKSPACE '\b'
    #define E_FORM_FEED '\f' //Not used
    #define E_NEWLINE '\n'
    #define E_RETURN '\r' //Actually, enter on keyboard
    #define E_TAB '\t' 
    #define E_BACKSLASH '\\'
    #define E_DOUBLE_QUOTE '\"'
    #define E_SINGLE_QUOTE '\''
    #define E_VERTICAL_TAB '\v'
    #define E_QUESTION_MARK '\?' // ? Is This Needed

#elif _WIN32
    #define C_BLACK 0
    #define C_DARKBLUE FOREGROUND_BLUE
    #define C_DARKGREEN FOREGROUND_GREEN
    #define C_DARKCYAN FOREGROUND_GREEN | FOREGROUND_BLUE
    #define C_DARKRED FOREGROUND_RED
    #define C_DARKMAGENTA FOREGROUND_RED | FOREGROUND_BLUE
    #define C_DARKYELLOW FOREGROUND_RED | FOREGROUND_GREEN
    #define C_DARKGRAY FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
    #define C_GRAY FOREGROUND_INTENSITY
    #define C_BLUE FOREGROUND_INTENSITY | FOREGROUND_BLUE
    #define C_GREEN FOREGROUND_INTENSITY | FOREGROUND_GREEN
    #define C_CYAN FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE
    #define C_RED FOREGROUND_INTENSITY | FOREGROUND_RED
    #define C_MAGENTA FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE
    #define C_YELLOW FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN
    #define C_WHITE FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#endif

#ifdef linux
    //Set an attribute for console look
    void c_setAttribute(const char* attribute) {
        printf("%s", attribute);
    }

    //Reset console
    void c_reset() {
        printf(A_RESET);
    }

    //Set more than one Attribute
    void c_setAll(const char* attributes[], const size_t length) {
        for (size_t i = 0; i < length; i++) {
            c_setAttribute(attributes[i]);
        }
    }

    // Function to get the current number of rows in the console
    // ! (Linux Only)
    int c_get_rows() {
        struct winsize ws;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
        return ws.ws_row;
    }

    // Function to get the current number of columns in the console
    // ! (Linux Only)
    int c_get_columns() {
        struct winsize ws;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
        return ws.ws_col;
    }


    // Function to set the cursor position to an absolute row and column
    // ! (Linux Only)
    void c_setCursorPosition(const int row, const int col) {
        printf("\033[%d;%dH", row, col);
    }

    // Function to move the cursor to the beginning of a specific row
    // ! (Linux Only)
    void c_moveToRow(const int row) {
        c_setCursorPosition(row, 1);
    }

    // Function to move the cursor to the beginning of a specific column
    // ! (Linux Only)
    void c_moveToColumn(const int col) {
        c_setCursorPosition(1, col);
    }
    //Function to show an error box
    void c_errorBox(const char* msg) {
        c_reset();
        c_setAttribute(BG_RED);
        printf("%s", msg);
    }

    //Function to show a warning box
    void c_warningBox(const char* msg) {
        c_reset();
        c_setAttribute(BG_YELLOW);
        printf("%s", msg);
    }

    //Function to show a message box
    void c_messageBox(const char* msg) {
        c_reset();
        c_setAttribute(BG_CYAN);
        printf("%s", msg);
    }

    //Function to show a success box
    void c_successBox(const char* msg) {
        c_reset();
        c_setAttribute(BG_GREEN);
        printf("%s", msg);
    }

    //Function to alert
    void alertSound() {
        printf("%c", E_ALERT);
    }

#elif _WIN32

#define C_BLACK 0
#define C_DARKBLUE FOREGROUND_BLUE
#define C_DARKGREEN FOREGROUND_GREEN
#define C_DARKCYAN FOREGROUND_GREEN | FOREGROUND_BLUE
#define C_DARKRED FOREGROUND_RED
#define C_DARKMAGENTA FOREGROUND_RED | FOREGROUND_BLUE
#define C_DARKYELLOW FOREGROUND_RED | FOREGROUND_GREEN
#define C_DARKGRAY FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define C_GRAY FOREGROUND_INTENSITY
#define C_BLUE FOREGROUND_INTENSITY | FOREGROUND_BLUE
#define C_GREEN FOREGROUND_INTENSITY | FOREGROUND_GREEN
#define C_CYAN FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE
#define C_RED FOREGROUND_INTENSITY | FOREGROUND_RED
#define C_MAGENTA FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE
#define C_YELLOW FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN
#define C_WHITE FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE


void c_setAttribute(int attribute) {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, attribute);
}

void c_reset() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, C_WHITE);
}

void c_setAll(int attributes[], const size_t length) {
    for (size_t i = 0; i < length; i++) {
        c_setAttribute(attributes[i]);
    }
}
//Function to show an error box
void c_errorBox(const char* msg) {
    c_reset();
    c_setAttribute(FOREGROUND_INTENSITY | FOREGROUND_RED);
    printf("%s", msg);
}

//Function to show a warning box
void c_warningBox(const char* msg) {
    c_reset();
    c_setAttribute(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("%s", msg);
}

//Function to show a message box
void c_messageBox(const char* msg) {
    c_reset();
    c_setAttribute(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("%s", msg);
}

//Function to show a success box
void c_successBox(const char* msg) {
    c_reset();
    c_setAttribute(FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    printf("%s", msg);
}

//Function to alert
void alertSound() {
    printf("%c", '\a');
}

#endif

// Function to draw a horizontal line with a specified width
void c_drawHorizontalLine(const int width, const char horizontalChar) {
    for (int i = 0; i < width; i++) {
        putchar(horizontalChar);
    }
    putchar('\n');
}

//Function to draw a box with given height and width
void c_draw_box(const int width, const int height, const char crossChar, const char horizontalChar, const char verticalChar) {
    printf("%c", crossChar);
    for (int i = 0; i < width - 2; i++) {
        printf("%c", verticalChar);
    }
    printf("%c\n", crossChar);

    for (int i = 0; i < height - 2; i++) {
        printf("%c", horizontalChar);
        for (int j = 0; j < width - 2; j++) {
            printf("%c", ' ');
        }
        printf("%c\n", horizontalChar);
    }

    printf("%c", crossChar);
    for (int i = 0; i < width - 2; i++) {
        printf("%c", verticalChar);
    }
    printf("%c\n", crossChar);
}

//Function to draw text box
void c_draw_text_box(const int height, const char crossChar, const char horizontalChar, const char verticalChar, const char* text) {
    int textPoint = -1;

    if (height % 2 == 0) {
        textPoint = height / 2;
    }
    else {
        textPoint = height / 2 - 1;
    }

    printf("%c", crossChar);
    for (int i = 0; i < strlen(text); i++) {
        printf("%c", verticalChar);
    }
    printf("%c\n", crossChar);

    for (int i = 0; i < height - 2; i++) {
        printf("%c", horizontalChar);
        if (i == textPoint) {
            printf("%s", text);
        }
        else {
            for (int j = 0; j < strlen(text); j++) {
                printf("%c", ' ');
            }
        }
        printf("%c\n", horizontalChar);
    }

    printf("%c", crossChar);
    for (int i = 0; i < strlen(text); i++) {
        printf("%c", verticalChar);
    }
    printf("%c\n", crossChar);
}

//Function to draw a circle
void c_draw_circle(const int radius) {
    for (int y = -radius; y <= radius; ++y) {
        for (int x = -radius; x <= radius; ++x) {
            double distance = sqrt(x * x + y * y);
            if (distance > radius - 0.5 && distance < radius + 0.5) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

//Function to draw a triangle
void c_draw_triangle(const int height) {
    for (int row = 1; row <= height; ++row) {
        for (int space = 1; space <= height - row; ++space) {
            printf(" ");
        }
        for (int star = 1; star <= 2 * row - 1; ++star) {
            printf("*");
        }
        printf("\n");
    }
}

//Function to draw a triangle with text
void c_draw_text_triangle(const int height, const char* text) {
    int textLength = strlen(text);
    int textPosition = (2 * height - 1 - textLength) / 2;

    for (int row = 1; row <= height; ++row) {
        for (int space = 1; space <= height - row; ++space) {
            printf(" ");
        }
        if (row == height / 2 + 1) {
            printf("%*s%s%*s", textPosition, "", text, textPosition, "");
        }
        else {
            for (int star = 1; star <= 2 * row - 1; ++star) {
                printf("*");
            }
        }
        printf("\n");
    }
}
