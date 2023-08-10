// * Customizable Console

//Starting of ConsoleColor.h file
//This header file helps to you to customize your console applications

#pragma once

//=============================================================================================================================================================
// * Used files / Headers / Libraries 


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



//=============================================================================================================================================================
// * Pre-defines for escape characters

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
    //Color Values
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

#endif



//=============================================================================================================================================================
// * All Functions
#ifdef linux
    // * Functions For Linux 


    /*
        * @brief (Linux) This function sets an attribute for console look
        * @param attribute is attribute that will be used (const char*)
        * @return This function does not return anything  
    */
    void c_setAttribute(const char* attribute) {
        printf("%s", attribute);
    }

    /*
        * @brief (Linux) This function resets all attributes for current console
        * This function does not take any parameters
        * @return This function does not return anything
    */
    void c_reset() {
        printf(A_RESET);
    }

    /*
        * @brief (Linux) Set more than one Attribute
        * @param attributes A string (const char*) parameter where all attributes must be stored
        * @param length A number (const size_t) specifies length of first argument / parameter
        * @return This function does not return anything
    */
    void c_setAll(const char* attributes[], const size_t length) {
        for (size_t i = 0; i < length; i++) {
            c_setAttribute(attributes[i]);
        }
    }

    /* 
        * @brief (Linux) Function to get the current number of rows in the console
        * This function does not take any parameters
        * @return This function returns number of rows in current console (int)
        * @note This function is Linux only
    */
    int c_get_rows() {
        struct winsize ws;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
        return ws.ws_row;
    }

    
    /*
        * @brief (Linux) Function to get the current number of columns in the console
        * This function doe snot take any parameters
        * @return This function returns number of columns in current console (int)
        * @note This function is Linux only
    */
    int c_get_columns() {
        struct winsize ws;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
        return ws.ws_col;
    }


    /*
        * @brief (Linux) Function to set the cursor position to an absolute row and column
        * @param row This argument must be a number (const int) and it sets row for cursor
        * @param col This argument must be a number (const int) and it sets column for cursor
        * @return This function does not return anything
        * @note This function is Linux only
    */
    void c_setCursorPosition(const int row, const int col) {
        printf("\033[%d;%dH", row, col);
    }

    /*
        * @brief (Linux) Function to move cursor to a beginning of a specific row
        * @param row This argument must be a number (const int) and it sets row for cursor
        * @return This function does not return anything
        * @note This function is Linux only
    */
    void c_moveToRow(const int row) {
        c_setCursorPosition(row, 1);
    }

    /*
        * @brief (Linux) Function to move the cursor to the beginning of a specific column
        * @param col This argument must be a number (const int) and it sets column for cursor
        * @return This function does not return anything
        * @note This function is Linux only
    */
    void c_moveToColumn(const int col) {
        c_setCursorPosition(1, col);
    }

    /*
        * @brief (Linux) Function to print an error box
        * @param msg This argument must be a string (const char*) 
        * @return This function does not return anything
        * @note This function prints message directly without asking
    */
    void c_errorBox(const char* msg) {
        c_reset();
        c_setAttribute(BG_RED);
        printf("%s", msg);
    }

    /*
        * @brief (Linux) Function to print a warning box
        * @param msg This argument must be a string (const char*) 
        * @return This function does not return anything
        * @note This function prints message directly without asking
    */
    void c_warningBox(const char* msg) {
        c_reset();
        c_setAttribute(BG_YELLOW);
        printf("%s", msg);
    }

    /*
        * @brief (Linux) Function to print a message box
        * @param msg This argument must be a string (const char*) 
        * @return This function does not return anything
        * @note This function prints message directly without asking
    */
    void c_messageBox(const char* msg) {
        c_reset();
        c_setAttribute(BG_CYAN);
        printf("%s", msg);
    }

    /*
        * @brief (Linux) Function to print a success box
        * @param msg This argument must be a string (const char*) 
        * @return This function does not return anything
        * @note This function prints message directly without asking
    */
    void c_successBox(const char* msg) {
        c_reset();
        c_setAttribute(BG_GREEN);
        printf("%s", msg);
    }

    /*
        * @brief (Linux) Function to output alert audio
        * This function doe snot take any parameters
        * @return This function does not return anything
        * @note This function outputs alert-audio that is built-in on current OS.
    */
    void c_alertSound() {
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


// * Windows Functions

    /*
        * @brief (Windows) This function sets an attribute for console look
        * @param attribute is attribute that will be used (int)
        * @return This function does not return anything  
    */
    void c_setAttribute(int attribute) {
        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, attribute);
    }

    /*
        * @brief (Windows) This function resets all attributes for current console
        * This function does not take any parameters
        * @return This function does not return anything
    */
    void c_reset() {
        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, C_WHITE);
    }

    /*
        * @brief (Windows) Function to set multiple attributes
        * @param attributes array of arguments that will be applied (int [])
        * @param length Length of first argument (const size_t)
        * @return This function does not return anything
    */    
    void c_setAll(int attributes[], const size_t length) {
        for (size_t i = 0; i < length; i++) {
            c_setAttribute(attributes[i]);
        }
    }
    
    /*
        * @brief (Windows) Function to print an error box
        * @param msg This argument must be a string (const char*) 
        * @return This function does not return anything
        * @note This function prints message directly without asking
    */
    void c_errorBox(const char* msg) {
        c_reset();
        c_setAttribute(FOREGROUND_INTENSITY | FOREGROUND_RED);
        printf("%s", msg);
    }

    /*
        * @brief (Windows) Function to print a warning box
        * @param msg This argument must be a string (const char*) 
        * @return This function does not return anything
        * @note This function prints message directly without asking
    */
    void c_warningBox(const char* msg) {
        c_reset();
        c_setAttribute(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        printf("%s", msg);
    }

    /*
        * @brief (Windows) Function to print a message box
        * @param msg This argument must be a string (const char*) 
        * @return This function does not return anything
        * @note This function prints message directly without asking
    */
    void c_messageBox(const char* msg) {
        c_reset();
        c_setAttribute(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("%s", msg);
    }

    /*
        * @brief (Windows) Function to print a success box
        * @param msg This argument must be a string (const char*) 
        * @return This function does not return anything
        * @note This function prints message directly without asking
    */
    void c_successBox(const char* msg) {
        c_reset();
        c_setAttribute(FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("%s", msg);
    }

    /*
        * @brief (Windows) Function to output alert audio
        * @param msg This argument must be a string (const char*) 
        * @return This function does not return anything
        * @note This function outputs alert-audio that is built-in on current OS.
    */
    void c_alertSound() {
        printf("%c", '\a');
    }

#endif

// * Shared Functions Between Platforms

/* 
    * @brief Function to draw a horizontal line with a specified width
    * @param width This argument must be a number (const int) and it specifies a width for line
    * @param horizontalChar is char that will be printed on line
    * @return This function does not return anything
    * @note This function outputs line directly without asking
*/
void c_drawHorizontalLine(const int width, const char horizontalChar) {
    for (int i = 0; i < width; i++) {
        putchar(horizontalChar);
    }
    putchar('\n');
}

/*
    * @brief Function to draw a box with given height and width
    * @param width This argument must be a number (const int) and it specifies width for box
    * @param height This argument must be a number (const int) and it specifies height for box
    * @param crossChar This argument must be a character (const char) and it will be printed on the corners of box
    * @param horizontalChar This argument must be a character (const char) and it will be printed on top and bottom of box
    * @param verticalChar This argument must be a character (const char) and it will be printed on the right and left of box
    * @return This function does not return anything
    * @note This function outputs box directly without asking
*/
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

/*
    * @brief Function to draw a box with given height and width
    * @param height This argument must be a number (const int) and it specifies height for box
    * @param crossChar This argument must be a character (const char) and it will be printed on the corners of box
    * @param horizontalChar This argument must be a character (const char) and it will be printed on top and bottom of box
    * @param verticalChar This argument must be a character (const char) and it will be printed on the right and left of box
    * @param text This argument must be a string (const char*) and it will be on the center og box
    * @return This function does not return anything
    * @note This function outputs box directly without asking
*/
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

/*
    * @brief Function to draw a circle
    * @param radius This argument must be a number (const int) and it specifies radius for circle
    * @return This function does not return anything
    * @note This function prints circle directly without asking
*/
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

/*
    * @brief Function to draw a triangle
    * @param height This argument must be a number (const int) and it specifies height for triangle
    * @return This function does not return anything
    * @note This function prints triangle directly without asking
*/
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

/*
    * @brief Function to draw a triangle
    * @param height This argument must be a number (const int) and it specifies height for triangle
    * @param text This argument must be a string (const char*) and it will be printed on the center of triangle
    * @return This function does not return anything
    * @note Text may not be aligned to center correctly
*/
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
