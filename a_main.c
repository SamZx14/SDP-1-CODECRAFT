#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Include necessary headers and function prototypes
#include "a1_choose_menu.c"
#include "b_code_quize.c"
#include "c_syntax_sprint.c"
#include "d_bug_hunter.c"
#include "e_type_master.c"
#include "f_mix_mode.c"

int main (){
    int choose=1,stp=0;
    char ch;
    dis_wel(); // Welcome screen
    dis_nvg(); // Navigation screen
    user(); // User login or account creation
    

   
    // Main menu loop
    // The loop will continue until the user chooses to exit the game
    while(1){
       
        dis_menu(choose,stp++); // Display the main menu
        ch=_getch();
        if((ch=='w'|| ch=='W' || ch == 72)&& choose>1) choose --;
        else if((ch=='x' || ch=='X' || ch == 80)&& choose<7) choose ++;
        else if(ch=='\r'|| ch=='s' || ch=='s'){
            if(choose==1) code_quiz(); // Call the code quiz function
            else if(choose==2) syntax_sprint(); // Call the syntax sprint function 
            else if(choose==3) bug_hunter(); // Call the bug hunter function
            else if(choose==4) type_master(); // Call the type master function
            else if(choose==5) mix_mode(); // Call the mix mode function
            else if(choose==6) dis_about(); // Call the about function
            else if(choose==7) {
                dis_exit();  // Call the exit function
                return 0;
            }
    }
    }
    return 0;
}