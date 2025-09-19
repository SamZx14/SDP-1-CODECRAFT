#include<stdio.h>
#include<windows.h>
#include <stdlib.h>  // For system calls like "cls" (optional)
#include <time.h>    // For struct timespec and nanosleep
#include <conio.h>   // For _getch() (optional)


void animation (const char *title,double time_set){ // Function to animate the text
    struct timespec dily;
    dily.tv_sec =0;
    dily.tv_nsec =100000000/time_set;
    int ck=1;
    for (int i=0;title[i]!='\0';i++){
        if(title[i] == '\033' && title[i + 1] == '[')ck=0;
        if(title[i]=='m'&&ck==0)ck=1;
        printf("%c",title[i]);
        fflush(stdin);
       if(ck) nanosleep(&dily,NULL);
    }
}

// Function to set the console text color (Windows)
void c1(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


const char* c2(int color){
    const char *ar[] = {
        "\033[0m",                // Reset to default color 0
        "\033[0;30m",             // Black 1
        "\033[0;31m",             // Red 2 
        "\033[0;32m",             // Green 3
        "\033[0;33m",             // Yellow 4
        "\033[0;34m",             // Blue 5
        "\033[0;35m",             // Magenta 6
        "\033[0;36m",             // Cyan 7
        "\033[0;37m",             // White 8
    
        "\033[1;30m",             // Bold Black 9
        "\033[1;31m",             // Bold Red 10
        "\033[1;32m",             // Bold Green 11
        "\033[1;33m",             // Bold Yellow 12
        "\033[1;34m",             // Bold Blue 13
        "\033[1;35m",             // Bold Magenta 14
        "\033[1;36m",             // Bold Cyan 15
        "\033[1;37m",             // Bold White 16
    
        "\033[40m",              // Black Background 17 
        "\033[41m",              // Red Background 18
        "\033[42m",              // Green Background 19
        "\033[43m",              // Yellow Background 20
        "\033[44m",              // Blue Background 21
        "\033[45m",              // Magenta Background 22
        "\033[46m",              // Cyan Background 23
        "\033[47m",              // White Background 24
    };
    
    return ar[color];
}