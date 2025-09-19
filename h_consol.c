#include<stdio.h>
#include<windows.h>

typedef struct { // Structure to hold console window size
    int x;
    int y;
} pair;

// Function to get the console window size
pair get_cnl_wh() {
    CONSOLE_SCREEN_BUFFER_INFO cnli; // Structure to hold console screen buffer information
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cnli); // Get the console screen buffer information
    pair size; // Create a pair structure to hold the size
    size.x = cnli.srWindow.Right - cnli.srWindow.Left + 1;
    size.y = cnli.srWindow.Bottom - cnli.srWindow.Top + 1;
    return size;
}

// Function to set the console cursor position
void set_cnl_pos(int x, int y) {
    COORD coord; // Create a COORD structure to hold the coordinates
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Set the cursor position
}