#include<stdio.h>
#include<conio.h>
#include<time.h>
#include "g_color.c"
#include "h_consol.c"

const char sm_ar[]={'"','%','&'}; // Array to store special characters for the question
const char *bc = "\n"; // Variable to store the background color
int score = 0; // Global variable to keep track of the score

// Function for answers navigation
// This function takes the user's input and checks if it matches the correct answer
void ans_nvg(char *ch, int *choice, int *ans, int Ans, int inc, int *stp, const char *op_a, const char *op_b, const char *op_c, const char *op_d){
    if (*stp == 0) {
        animation("\033[1;32mChoose the correct answer:\n\n\n", 3);  // Initial question display
    } else {
        printf("\033[1;32mChoose the correct answer:\n\n\n");  // Interactive mode after the first step
    }

    // Navigation logic based on key input
    if ((*ch == 'd' || *ch == 'D' || *ch == 77) && *choice < 4) (*choice)++;
    else if ((*ch == 'a' || *ch == 'A' || *ch == 75) && *choice > 1) (*choice)--;
    else if ((*ch == 'w' || *ch == 'W' || *ch == 72) && (*choice == 3 || *choice == 4)) *choice -= 2;
    else if ((*ch == 'x' || *ch == 'X' || *ch == 80) && (*choice == 1 || *choice == 2)) *choice += 2;
   

    // Display the options with color coding
    printf("%s A:%s %s\t", *choice == 1 ? "\033[41m" : "\033[1;37m", c2(8), op_a);
    printf("%s B:%s %s\n\n", *choice == 2 ? "\033[41m" : "\033[1;37m", c2(8), op_b);
    printf("%s C:%s %s\t", *choice == 3 ? "\033[41m" : "\033[1;37m", c2(8), op_c);
    printf("%s D:%s %s\n\n", *choice == 4 ? "\033[41m" : "\033[1;37m", c2(8), op_d);

    // Check if the user has selected an answer and compare it to the correct answer
    if (*ch == '\r' || *ch == 's' || *ch == 'S') {
         // Answer selection logic based on the selected choice
         if (*choice == 1) *ans = 1; // Option A
         else if (*choice == 2) *ans = 2; // Option B
         else if (*choice == 3) *ans = 3; // Option C
         else if (*choice == 4) *ans = 4; // Option D
        if (*ans == Ans) {

            score += inc; // Increment score by 10 for correct answer
            animation("\033[1;32mCorrect!\n", 2);
        } else {
            animation("\033[1;31mIncorrect! The correct answer is 5.\n", 2);
            printf("%s\n", bc);
        }
    }
}

// Function for level 1 question
int cq1_l1() {
    pair W_size = get_cnl_wh();
    int choice = 1, stp = 0, ans = 0;
    char ch;
    system("cls");

     animation("\033[1;32mWhat is the correct output for x...\n\n", 2);
    // Display the question with formatted string
    printf("%sint %sx %s= 5\n%sprintf%s(%s%c%cd%c,x++%s);\n\n", c2(13), c2(15), c2(8), c2(7), c2(8), c2(6), sm_ar[0], sm_ar[1], sm_ar[0], c2(8));

    // Call the ans_nvg function to handle answer selection and input navigation
    ans_nvg(&ch, &choice, &ans, 1 /*ans*/, 10 /*score increment*/, &stp, "5", "6", "7", "8");
    time_t start = time(NULL);
    stp++;
    
    while(1) {
        set_cnl_pos(0, 0);
        
        // If step is 0, or user presses a key, continue the loop
        if ( _kbhit()) {
            system("cls");
            ch = _getch();
            set_cnl_pos(0,W_size.y);
            printf("\033[1;32mWhat is the correct output for x...\n\n");

            // Display the question with formatted string
            printf("%sint %sx %s= 5\n%sprintf%s(%s%c%cd%c,x++%s);\n\n", c2(13), c2(15), c2(8), c2(7), c2(8), c2(6), sm_ar[0], sm_ar[1], sm_ar[0], c2(8));

            // Call the ans_nvg function to handle answer selection and input navigation
            ans_nvg(&ch, &choice, &ans, 1 /*ans*/, 10 /*score increment*/, &stp, "5", "6", "7", "8");

            // Timer logic: end quiz after 10 seconds
            if (time(NULL) - start >= 10) {
                printf("Time is up\n");
                break;
            }
            if (ans != 0) break; // Break if answer is selected
            stp++; // Increment the step for subsequent iterations
        }
    }
    
    // Continue with the next prompt
    set_cnl_pos(0, (W_size.y) - 2);
    animation("\033[1;32mPress any key to continue...", 2);
    _getch(); // Wait for user input
    return 0;
}

int main() { // Main function for the code quiz
    system("cls");
    int choose = 1, stp = 0;
    char ch;
    cq1_l1(); // Call the function for question 1
}
