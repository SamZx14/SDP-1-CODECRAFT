#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>

void code_quiz(); // Function prototype for the code quiz

const char sm_ar[]={'"','%','&',}; // Array to store special characters for the question

int score = 0; // Global variable to keep track of the score
int back = 1;
// Function for andswers navigation
// This function takes the user's input and checks if it matches the correct answer
void ans_nvg(char *ch,int *choice,int *ans,int Ans,int inc,int *stp, int round, int high_si, int level, int life,int data_pos, const char *op_a, const char *op_b, const char *op_c, const char *op_d, const char *hint,int *hint_pos){
  
    data_pos+=6;
    if (*stp==0) animation("\033[1;32mChoose the correct answer:\n\n",3);
    else printf("\033[1;32mChoose the correct answer:\n\n");
    if ((*ch == 'd' || *ch == 'D' || *ch == 77) && *choice < 5) (*choice)++;
    else if ((*ch == 'a' || *ch == 'A' || *ch == 75) && *choice > 1) (*choice)--;
    else if ((*ch == 'w' || *ch == 'W' || *ch == 72) && (*choice ==3 || *choice ==4 || *choice == 5)) *choice-=2;
    else if ((*ch == 'x' || *ch == 'X' || *ch == 80) && (*choice ==1 || *choice ==2 || *choice == 3)) *choice+=2;
    if (*ch == '@') {
        back = 0; // Set back to false if '@' is pressed
        return; // Exit the function
    }
    int tab_size=(strlen(op_a)>=strlen(op_c))?strlen(op_a):strlen(op_c);
        // Display the options with color coding
        printf("%s A:%s %s",*choice==1?"\033[41m":"\033[1;37m",c2(8),op_a);
        set_cnl_pos(tab_size+11, data_pos-5);
        printf("%s B:%s %s\n\n",*choice==2?"\033[41m":"\033[1;37m",c2(8),op_b);
        printf("%s C:%s %s",*choice==3?"\033[41m":"\033[1;37m",c2(8),op_c);
        set_cnl_pos(tab_size+11, data_pos-3);
        printf("%s D:%s %s\n\n",*choice==4?"\033[41m":"\033[1;37m",c2(8),op_d);
        printf("%s E:%s Hint",*choice==5?"\033[41m":"\033[1;37m",c2(7));
        c1(8);
        printf(" (If you take a hint, your lose 5 point and you just take once for a round.)");
        c1(7);
      
    // Check for valid input and update the choice accordingly
    
    if (*ch == '\r' || *ch == 's' || *ch == 'S') {
        if (*choice == 1) *ans = 1; // Option A
        else if (*choice == 2) *ans = 2; // Option B
        else if (*choice == 3) *ans = 3; // Option C
        else if (*choice == 4) *ans = 4; // Option D
        
        if (*ans == Ans) {
            score += inc; // Increment score by 10 for correct answer
            high_score_w(score, 1); // Update high score for code quiz
            set_cnl_pos(0,data_pos+1);
            animation("\033[1;32mCorrect!", 2);
           
        }
        else if (*choice == 5&&*hint_pos==0) {
            (*hint_pos)++;
            score -= 5; // Increment score by 5 for incorrect answer
            high_score_w(score, 1); // Update high score for code quiz
            set_cnl_pos(0,data_pos);
            printf("%s%s",c2(11),hint);
        }
        
    }
   
}

void easy_q(); // Function prototypes for different difficulty levels
void medium_q(); // Function prototypes for different difficulty levels 
void hard_q(); // Function prototypes for different difficulty levels

//EASY LEVEL QUESTIONS CODE STARTS FROM HERE

int cq1_l1(int *life){ // question 1 for level 1 for easy level
    pair W_size = get_cnl_wh();
    int round=1,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=2,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhich of the following is a valid variable name?\n\n",2);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"321ch", "s_1", "float", "@number","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhich of the following is a valid variable name?\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"321ch", "s_1", "float", "@number","Identifiers must initiate with an alphabetic character or underscore.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("variable name must be start from a character. Special characters, numbers and \nkeywords are allowed. We can use ( _ ) into variable name.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    return complite_quiz;
}

int cq2_l1(int *life){ // question 2 for level 1 for easy level
    pair W_size = get_cnl_wh();
    int round=2,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=3,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhich one is a derived data type ?\n\n",2);
    // Display the question
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"void", "union", "pointers", "char","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhich one is a derived data type ?\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"void", "union", "pointers", "char","Built from existing basic types.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("Pointers is a derived data type because it is created from a basic data type.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    return complite_quiz;
}

int cq3_l1(int *life){ // question 3 for level 1 for easy level
    pair W_size = get_cnl_wh();
    int round=3,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=1,time_limit=15,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32m% [Modulo] works on _?_\n\n",2);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"int", "double", "float", "all the above ","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32m%c [Modulo] works on _?_\n\n",sm_ar[1]);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"int", "double", "float", "all the above ","Handles only discrete numeric values.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("The ( % ) operator in C is designed to work with integers only.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    return complite_quiz;
}

int cq4_l2(int *life){ // question 1 for level 2 for easy level
    pair W_size = get_cnl_wh();
    int round=4,high_si=1,level=2,choice =1,stp=0,ans=0,correct_ans=4,time_limit=15,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the output of the variable y ?\n\n",2);
    // Display the question
    printf("%sint %sx %s= 9;\n%sint %sy %s= x %s/ %s81;\n%sprintf%s(%s%c%cd%c,y%s);\n\n",c2(13),c2(15),c2(8),c2(13),c2(15),c2(8),c2(14),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,14/*data pos*/,"0.111", "error", "9", "0","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the output of the variable y ?\n\n");
    // Display the question
    printf("%sint %sx %s= 9;\n%sint %sy %s= x %s/ %s81;\n%sprintf%s(%s%c%cd%c,y%s);\n\n",c2(13),c2(15),c2(8),c2(13),c2(15),c2(8),c2(14),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,14/*data pos*/,"0.111", "error", "9", "0","This will perform integer division.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,21); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,23); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("Here both the nembers are integer type thats why the result will store only the\nineteger part",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    return complite_quiz;
}

int cq5_l2(int *life){ // question 2 for level 2 for easy level
    pair W_size = get_cnl_wh();
    int round=5,high_si=1,level=2,choice =1,stp=0,ans=0,correct_ans=3,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhich one is not an operator type ?\n\n",2);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"bitwise", "conditional", "functional", "assignment","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhich one is not an operator type ?\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"bitwise", "conditional", "functional", "assignment","Three of these are common operators in C; the fourth is more about how functions behave.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("There is no operator like functional operator in C.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    
    return complite_quiz;
}

int cq6_l2(int *life){ // question 3 for level 2 for easy level
    pair W_size = get_cnl_wh();
    int round=6,high_si=1,level=2,choice =1,stp=0,ans=0,correct_ans=2,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mDefine the type of output here --\n\n",2);
    // Display the question
    printf("%sint %s+ %soparetor %s+ %sfloat %s= ?;\n\n",c2(13),c2(14),c2(13),c2(14),c2(13),c2(8));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,12/*data pos*/,"int", "float", "double", "error","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mDefine the type of output here --\n\n");
    // Display the question
    printf("%sint %s+ %soparetor %s+ %sfloat %s= ?;\n\n",c2(13),c2(14),c2(13),c2(14),c2(13),c2(8));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,12/*data pos*/,"int", "float", "double", "error","When an integer interacts with a floating-point value, the result is promoted to the broader type.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,19); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,21); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("In C, when different data types are used in the same expression, C convert the \nsmaller type to the bigger type before doing the calculation. This is \ncalled type promotion",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    
    return complite_quiz;
}

int cq7_l3(int *life){ // question 1 for level 3 for easy level
    pair W_size = get_cnl_wh();
    int round=7,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=4,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the output will be ?\n\n",2);
    // Display the question
    printf("%sint %sm %s= 10, %sn %s= 9, %so %s= 8, %sp %s= 7, %sq %s= 6;\n%sprintf%s(%s%c%cd%c, m %s* %sn %s/ %so %s+ %sp %s- %sq %s);\n\n",c2(13),c2(15),c2(8),c2(15),c2(8),c2(15),c2(8),c2(15),c2(8),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(12),c2(6),c2(12),c2(6),c2(12),c2(6),c2(12),c2(6),c2(8));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,13/*data pos*/,"11.25", "10", "12.25", "12","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the output will be ?\n\n");
    // Display the question
    printf("%sint %sm %s= 10, %sn %s= 9, %so %s= 8, %sp %s= 7, %sq %s= 6;\n%sprintf%s(%s%c%cd%c, m %s* %sn %s/ %so %s+ %sp %s- %sq %s);\n\n",c2(13),c2(15),c2(8),c2(15),c2(8),c2(15),c2(8),c2(15),c2(8),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(12),c2(6),c2(12),c2(6),c2(12),c2(6),c2(12),c2(6),c2(8));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,13/*data pos*/,"11.25", "10", "12.25", "12","Follow operator precedence step by step.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,20); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,22); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("Arithmetic operator follows the precedence rule.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    
    return complite_quiz;
}

int cq8_l3(int *life){ // question 2 for level 3 for easy level
    pair W_size = get_cnl_wh();
    int round=8,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=3,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mDefine the output --\n\n",2);
    // Display the question
    printf("%s#%sinclude%s<stdio.h>\n%sint %sc = %s1%s;%s// Global variable\n%svoid %sdisplay%s()\n{\n%sstatic int %sa = %s2%s;%s//static variable\n%sa++;\n%sprintf%s(%s%c%cd%c%s,a);\n}\n%sint %smain%s()\nsdisplay();\ndisplay();\ndisplay();\n%sprintf%s(%s%c%cd%c%s,c);\n%sreturn %s0%s;\n}\n\n",c2(16),c2(13),c2(11),c2(14),c2(16),c2(14),c2(16),c2(7),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(7),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(14),c2(10),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,26/*data pos*/,"2 3 4 1", "3 4 5 0", "3 4 5 1", "3 3 3 1","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mDefine the output --\n\n");
    // Display the question
    printf("%s#%sinclude%s<stdio.h>\n%sint %sc = %s1%s;%s// Global variable\n%svoid %sdisplay%s()\n{\n%sstatic int %sa = %s2%s;%s//static variable\n%sa++;\n%sprintf%s(%s%c%cd%c%s,a);\n}\n%sint %smain%s()\nsdisplay();\ndisplay();\ndisplay();\n%sprintf%s(%s%c%cd%c%s,c);\n%sreturn %s0%s;\n}\n\n",c2(16),c2(13),c2(11),c2(14),c2(16),c2(14),c2(16),c2(7),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(7),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(14),c2(10),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,26/*data pos*/,"2 3 4 1", "3 4 5 0", "3 4 5 1", "3 3 3 1","One variable retains its value across function calls, while the other resides globally.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,33); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,35); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("Static variable remembers it's value even after the function ends and Global \nvariable is available anywhere in the program.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    
    return complite_quiz;
}

int cq9_l3(int *life){ // question 3 for level 3 for easy level
    pair W_size = get_cnl_wh();
    int round=9,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=4,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the correct output for b?\n\n",2);
    // Display the question
    printf("%sint %sa %s= 2;\n%sint %sb %s= a++ %s/ %sa;\n%sprintf%s(%s%c%cd%c,b%s);\n\n",c2(13),c2(15),c2(8),c2(13),c2(15),c2(8),c2(14),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,14/*data pos*/,"error", "garbage value", "1", "0","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the correct output for b?\n\n");
    // Display the question
    printf("%sint %sa %s= 2;\n%sint %sb %s= a++ %s/ %sa;\n%sprintf%s(%s%c%cd%c,b%s);\n\n",c2(13),c2(15),c2(8),c2(13),c2(15),c2(8),c2(14),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,14/*data pos*/,"error", "garbage value", "1", "0","Here a will increase first then will be divided.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,21); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,23); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("Because of increament operator a will be 3 from 2 and then divided by 2 which\nstores an integer value in result",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    return complite_quiz;
}

int cq10_l3(int *life){ // question 4 for level 3 for easy level
    pair W_size = get_cnl_wh();
    int round=10,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=4,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the size of the input in ' long long int ' ?\n\n",2);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"64 bytes", "32 bytes", "16 bytes", "8 bytes","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the size of the input in ' long long int ' ?\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"64 bytes", "32 bytes", "16 bytes", "8 bytes","Consider how many bytes a 64-bit value would take up in memory.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("In C, the long long int stores a large number of 8 Bytes = 64 Bits.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    
    return complite_quiz;
}

//MIDIUM LEVEL QUESTIONS CODE STARTS FROM HERE

int cq11_l1(int *life){ // question 1 for level 1 for midium level
    pair W_size = get_cnl_wh();
    int round=1,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=1,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat does if(0) do ?\n\n",2);
    // Display the question
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"skips the if block", "compilation error", "run the if block", "invalid condition","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat does if(0) do ?\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"skips the if block", "compilation error", "run the if block", "invalid condition","Zero is considered as 'false' in C, so the associated block will be bypassed during execution.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("if (0) means false ; so the if block will not run.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

 
    
    return complite_quiz;
}

int cq12_l1(int *life){ // question 2 for level 1 for midium level
    pair W_size = get_cnl_wh();
    int round=2,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=1,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the correct output for x...\n\n",2);
    // Display the question
    printf("%sint %sx %s= 5;\n%sprintf%s(%s%c%cd%c,x++%s);\n\n",c2(13),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,13/*data pos*/,"5", "6", "7", "8","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the correct output for x...\n\n");
    // Display the question
    printf("%sint %sx %s= 5;\n%sprintf%s(%s%c%cd%c,x++%s);\n\n",c2(13),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,13/*data pos*/,"5", "6", "7", "8","++a & a++ are not same. Post-Increment: The value of x is used before it's incremented.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,20); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,22); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("In the printf function, the x (which is 5) is printed first, then incremented.\nSo, it prints 5 and x becomes 6 after that.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
 
    
    return complite_quiz;
}

int cq13_l1(int *life){ // question 3 for level 1 for midium level
    pair W_size = get_cnl_wh();
    int round=3,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=2,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mAt least how many times the given code will be run ?\n\n",2);
    // Display the question
    printf("%sint %st = %s1%s;\n%sdo\n%s{\n%sprintf%s(%s%c%cd%c%s,t);\nt++;\n}\n%swhile%s(t<=%s0%s);\n\n",c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(16),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,18/*data pos*/,"0", "1", "2", "3","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mAt least how many times the given code will be run ?\n\n");
    // Display the question
    printf("%sint %st = %s1%s;\n%sdo\n%s{\n%sprintf%s(%s%c%cd%c%s,t);\nt++;\n}\n%swhile%s(t<=%s0%s);\n\n",c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(16),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,18/*data pos*/,"0", "1", "2", "3","A do-while loop executes at least once regardless of the condition.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,25); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,27); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("A do-while loop always runs at least once ; then checks the condition.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz

    
    return complite_quiz;
}

int cq14_l1(int *life){ // question 4 for level 1 for midium level
    pair W_size = get_cnl_wh();
    int round=4,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=2,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the output ?\n\n",2);
    // Display the question
    printf("%sint %sa = %s10%s;\n%sint %s*p = &a;\n*p = %s20%s;\n%sprintf%s(%s%c%cd%c%s,a);\n\n",c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,15/*data pos*/,"address of a", "20", "10", "200","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the output ?\n\n");
    // Display the question
    printf("%sint %sa = %s10%s;\n%sint %s*p = &a;\n*p = %s20%s;\n%sprintf%s(%s%c%cd%c%s,a);\n\n",c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,15/*data pos*/,"address of a", "20", "10", "200","By dereferencing the pointer p, the value at a is modified.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,22); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,24); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("A do-while loop always runs at least once ; then checks the condition.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    
    return complite_quiz;
}

int cq15_l2(int *life){ // question 1 for level 2 for midium level
    pair W_size = get_cnl_wh();
    int round=5,high_si=1,level=2,choice =1,stp=0,ans=0,correct_ans=4,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhich of the following can cause infinite recursion?\n\n",2);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"No return", "No main", "Using printf", "Function calling itself without a stop","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhich of the following can cause infinite recursion?\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"No return", "No main", "Using printf", "Function calling itself without a stop","Consider a scenario where a function continually invokes itself without any exit condition.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("A recursion function never stops calling itself until there has any break in loop. ",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    return complite_quiz;
}

int cq16_l2(int *life){ // question 2 for level 2 for midium level
    pair W_size = get_cnl_wh();
    int round=6,high_si=1,level=2,choice =1,stp=0,ans=0,correct_ans=3,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mDefine the output-\n\n",2);
    // Display the question
    printf("%sint %smain%s(){\n%sint %sx = %s57%s;\n%sprintf%s(%s%c%cd%c%s,x--);\n%sprintf%s(%s%c%cd%c%s,--x);\n%sprintf%s(%s%c%cd%c%s,x++);\n%sprintf%s(%s%c%cd%c%s,++x);\n%sreturn %s0%s;\n}\n\n",c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,19/*data pos*/,"56 56 58 58", "57 56 57 58", "57 55 55 57", "56 55 55 56","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mDefine the output-\n\n");
    // Display the question
    printf("%sint %smain%s(){\n%sint %sx = %s57%s;\n%sprintf%s(%s%c%cd%c%s,x--);\n%sprintf%s(%s%c%cd%c%s,--x);\n%sprintf%s(%s%c%cd%c%s,x++);\n%sprintf%s(%s%c%cd%c%s,++x);\n%sreturn %s0%s;\n}\n\n",c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,19/*data pos*/,"56 56 58 58", "57 56 57 58", "57 55 55 57", "56 55 55 56","Consider the behavior of post-decrement (x--) and pre-decrement (--x) operators.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,26); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,28); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("Here the value of x will be printed same as 57 because of post-decrement \nthen it will decrease and will be 56 then after being decrease again in \npre-decrement it will be 55 , like the same way in the case of \npost-increment and pre-increment it will be 55 and then 57.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    return complite_quiz;
}

int cq17_l2(int *life){ // question 3 for level 2 for midium level
    pair W_size = get_cnl_wh();
    int round=7,high_si=1,level=2,choice =1,stp=0,ans=0,correct_ans=1,time_limit=15,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mHow many backslashes are printed in the output of this code?\n\n",2);
    // Display the question
    printf("%sint %smain%s(){\n%sfor%s(%sint %si = %s1%s; i < %s5%s; i++){\n%sprintf%s(%s%cHEllo world ! Welcome to Codecraft./\\/\\/\\ %c%s);\n}\n%sreturn %s0%s;\n\n",c2(14),c2(10),c2(16),c2(13),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,16/*data pos*/,"12", "10", "11", "infinite loop","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mHow many backslashes are printed in the output of this code?\n\n");
    // Display the question
    printf("%sint %smain%s(){\n%sfor%s(%sint %si = %s1%s; i < %s5%s; i++){\n%sprintf%s(%s%cHEllo world ! Welcome to Codecraft./\\/\\/\\ %c%s);\n}\n%sreturn %s0%s;\n\n",c2(14),c2(10),c2(16),c2(13),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,16/*data pos*/,"12", "10", "11", "infinite loop","Each \\/ in the string is written as \\ in code to print one backslash.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,23); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,25); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("In the above code, the loop completes four iterations. Each iteration \nprints 3 backslashes. As a result, (3 x 4) or 12 backslashes are \nprinted in output.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    return complite_quiz;
}

int cq18_l3(int *life){ // question 1 for level 3 for midium level
    pair W_size = get_cnl_wh();
    int round=8,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=4,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mPredict the output-\n\n",2);
    // Display the question
    printf("%sint %sa = %s98%s, b = %s5%s;\n%sprintf%s(%s%c%cd%c%s,++b);\n%sprintf%s(%s%c%cd%c%s,a % b);\n\n",c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,14/*data pos*/,"6 3", "5 2", "5 3", "6 2","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mPredict the output-\n\n");
    // Display the question
    printf("%sint %sa = %s98%s, b = %s5%s;\n%sprintf%s(%s%c%cd%c%s,++b);\n%sprintf%s(%s%c%cd%c%s,a % b);\n\n",c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,14/*data pos*/,"6 3", "5 2", "5 3", "6 2","++b increases b before printing, and (%) gives the remainder when a is divided by b.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,21); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,23); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("Here b will be pre-incremented and will be stored 6 in the 98 will be mod \nby the 6.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    return complite_quiz;
}

int cq19_l3(int *life){ // question 2 for level 3 for midium level
    pair W_size = get_cnl_wh();
    int round=9,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=2,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the output ?\n\n",2);
    // Display the question
    printf("%sint %sa = %s6%s;\n%sint %sb = %s9%s;\n%sint %s*p = &a;\n*p = b;\n%sprintf%s(%s%c%cd%c%s,a);\n\n",c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,16/*data pos*/,"6", "9", "error", "address of a","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the output ?\n\n");
    // Display the question
    printf("%sint %sa = %s6%s;\n%sint %sb = %s9%s;\n%sint %s*p = &a;\n*p = b;\n%sprintf%s(%s%c%cd%c%s,a);\n\n",c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,16/*data pos*/,"6", "9", "error", "address of a","The pointer p points to a, and assigning b to *p changes the value stored at a's address.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,23); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,25); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("Here we changed “ a “ using a pointer by storing the value of b in the \naddress of a.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    return complite_quiz;
}

int cq20_l3(int *life){ // question 3 for level 3 for midium level
    pair W_size = get_cnl_wh();
    int round=10,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=3,time_limit=20,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat will be the output?\n\n",2);
    // Display the question
    printf("%sint %sx = %s3%s;\n%sswitch%s(x){\n%scase %s3%s:\n%sprintf%s(%s%cHELLO%c%s);\n%scase %s2%s:\n%sprintf%s(%s%cCODE-CRAFTER%c%s);\n%scase %s1%s:\n%sprintf%s(%s%c:)%c%s);\n%sbreak%s;\n%sdefault%s:\n%sprintf%s(%s%cBEST OF LUCK%c%s);\n}\n\n",c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(13),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(13),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(13),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(13),c2(16),c2(13),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,23/*data pos*/,"HELLO", "BEST OF LUCK", "HELLO CODE-CRAFTER :)", "HELLO CODE-CRAFTER :) BEST OF LUCK","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat will be the output?\n\n");
    // Display the question
    printf("%sint %sx = %s3%s;\n%sswitch%s(x){\n%scase %s3%s:\n%sprintf%s(%s%cHELLO%c%s);\n%scase %s2%s:\n%sprintf%s(%s%cCODE-CRAFTER%c%s);\n%scase %s1%s:\n%sprintf%s(%s%c:)%c%s);\n%sbreak%s;\n%sdefault%s:\n%sprintf%s(%s%cBEST OF LUCK%c%s);\n}\n\n",c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(13),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(13),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(13),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(13),c2(16),c2(13),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,23/*data pos*/,"HELLO", "BEST OF LUCK", "HELLO CODE-CRAFTER :)", "HELLO CODE-CRAFTER :) BEST OF LUCK","After the matching case, execution falls through to subsequent cases until a break.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,30); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,32); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("In this switch case after matching case 3, it does not stop. It keeps running\nthe next cases. after matching one case, without break, all next\ncases also run.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);

    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz

    return complite_quiz;
}

//HARD LEVEL QUESTIONS CODE STRATS FROM HERE

int cq21_l1(int *life){ // question 1 for level 1 for hard level
    pair W_size = get_cnl_wh();
    int round=1,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=1,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhich function is used to find the length of a string in C?\n\n",2);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"strlen()", "sizeof()", "length()", "len()","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhich function is used to find the length of a string in C?\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"strlen()", "sizeof()", "length()", "len()","This standard library function counts characters in a string up to, but \nnot including, the null terminator \\0.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("In C we find the length of a string with strlen() function..",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

   
    
    return complite_quiz;
}

int cq22_l1(int *life){ // question 2 for level 1 for hard level
    pair W_size = get_cnl_wh();
    int round=2,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=2,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the correct way to declare a structure in C?\n\n",2);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"class CODECRAFTER { char name[21]; int age; };", "struct CODECRAFTER { char name[21]; int age; };", "structure CODECRAFTER { char name[21]; int age; };", "str CODECRAFTER { char name[21]; int age; };","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the correct way to declare a structure in C?\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"class CODECRAFTER { char name[21]; int age; };", "struct CODECRAFTER { char name[21]; int age; };", "structure CODECRAFTER { char name[21]; int age; };", "str CODECRAFTER { char name[21]; int age; };","In C, a structure must precede the structure name and its members with \na valid keyword.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("' struct ' is the right syntax to declare a structure in C.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    return complite_quiz;
}

int cq23_l1(int *life){ // question 3 for level 1 for hard level
    pair W_size = get_cnl_wh();
    int round=3,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=4,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mMemory allocated by malloc/calloc/realloc deallocates by -\n\n",2);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"enum()", "goto()", "typedef()", "free()","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mMemory allocated by malloc/calloc/realloc deallocates by -\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"enum()", "goto()", "typedef()", "free()","Think of it as a 'clean-up' operation.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("The memory which is allocated by malloc/calloc/realloc deallocates by free()\nin C. ",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    
    return complite_quiz;
}

int cq24_l2(int *life){ // question 1 for level 2 for hard level
    pair W_size = get_cnl_wh();
    int round=4,high_si=1,level=2,choice =1,stp=0,ans=0,correct_ans=2,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the correct way to write an integer into a file in C ?\n\n",2);
    // Display the question    
    printf("%s1 -> %sprintf%s(%s%c%cd%c%s,file.codecraft);\n%s2 -> %sfprint%s(file,%s%c%cd%c%s,codecraft);\n%s3 -> %sfile.print%s(%s%c%cfd%c%s,codecraft);\n%s4 -> %sfwrite%s(%s%c%cd%c%s,sizeof(%sint%s),file);\n\n",c2(10),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(10),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(10),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(10),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(16));

    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,15/*data pos*/,"1", "2", "3", "4","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the correct way to write an integer into a file in C ?\n\n");
    // Display the question  
    printf("%s1 -> %sprintf%s(%s%c%cd%c%s,file.codecraft);\n%s2 -> %sfprint%s(file,%s%c%cd%c%s,codecraft);\n%s3 -> %sfile.print%s(%s%c%cfd%c%s,codecraft);\n%s4 -> %sfwrite%s(%s%c%cd%c%s,sizeof(%sint%s),file);\n\n",c2(10),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(10),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(10),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(10),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(16));
  
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,15/*data pos*/,"1", "2", "3", "4","The function used is similar to printf.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,22); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,24); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("In C, to write something into a file, we do not use printf() (which prints \nto the screen). Instead, we use fprintf() to print into a file.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    
    return complite_quiz;
}

int cq25_l2(int *life){ // question 2 for level 2 for hard level
    pair W_size = get_cnl_wh();
    int round=5,high_si=1,level=2,choice =1,stp=0,ans=0,correct_ans=4,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the length of the string ''Code\\0Craft'' ?\n\n",2);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"12", "11", "9", "4","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the length of the string ''Code\\0Craft'' ?\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"12", "11", "9", "4","The null character \\0 marks the end of a string.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("In C language, \0 means 'the end of the string'. So when the computer sees \n\0, it stops reading.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz
    
    return complite_quiz;
}

int cq26_l2(int *life){ // question 3 for level 2 for midium level
    pair W_size = get_cnl_wh();
    int round=6,high_si=1,level=2,choice =1,stp=0,ans=0,correct_ans=3,time_limit=15,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the output here ?\n\n",2);
    // Display the question
    printf("%sint %sarr[%s7%s] = {%s0%s,%s1%s,%s2%s,%s3%s,%s4%s};\n%sprintf%s(%s%c%cd%c%s,arr[%s6%s]);\n\n",c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,13/*data pos*/,"garbage value", "no output", "0", "error","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the output here ?\n\n");
    // Display the question
    printf("%sint %sarr[%s7%s] = {%s0%s,%s1%s,%s2%s,%s3%s,%s4%s};\n%sprintf%s(%s%c%cd%c%s,arr[%s6%s]);\n\n",c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,13/*data pos*/,"garbage value", "no output", "0", "error","In C, if we initialize only part of an array, the remaining elements are automatically set to null.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,20); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,22); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("Uninitialized elements in a statically declared array get default value 0.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    
    return complite_quiz;
}

int cq27_l3(int *life){ // question 1 for level 3 for midium level
    pair W_size = get_cnl_wh();
    int round=7,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=2,time_limit=15,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mHow to read a file till the end in C ?\n\n",2);
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"while ( fp != EOF )", "while ( !feof (fp) )", "while ( read (fp) )", "while ( fend (fp) )","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mHow to read a file till the end in C ?\n\n");
    // Display the question    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"while ( fp != EOF )", "while ( !feof (fp) )", "while ( read (fp) )", "while ( fend (fp) )","To avoid reading past the end of a file, there's a built-in check that tells  when we've hit the end.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,17); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("The function feof (fp) checks if the end of the file has been reached.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   
    char chr=_getch();
    if(chr=='@'){
        back = 0; // Set back to false if '@' is pressed
        *life = 0; // Set life to 0 if '@' is pressed
        return complite_quiz; // if '@' is pressed, exit the quiz
    } // if '@' is pressed, exit the quiz
    
    
    return complite_quiz;
}

int cq28_l3(int *life){ // question 2 for level 3 for midium level
    pair W_size = get_cnl_wh();
    int round=8,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=2,time_limit=15,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the output here ?\n\n",2);
    // Display the question
    printf("%sint %sarr[] = {%s10%s,%s20%s,%s30%s};\n%sprintf%s(%s%c%cd%c%s,*(arr+%s1%s));\n\n",c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,13/*data pos*/,"10", "20", "30", "error","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the output here ?\n\n");
    // Display the question
    printf("%sint %sarr[] = {%s10%s,%s20%s,%s30%s};\n%sprintf%s(%s%c%cd%c%s,*(arr+%s1%s));\n\n",c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(14),c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,13/*data pos*/,"10", "20", "30", "error","Array names act like pointers in expressions.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,20); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,22); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("*(arr + 1) accesses second element using pointer arithmetic.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    
    return complite_quiz;
}

int cq29_l3(int *life){ // question 3 for level 3 for midium level
    pair W_size = get_cnl_wh();
    int round=9,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=1,time_limit=15,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the output here ?\n\n",2);
    // Display the question
    printf("%sstruct %sNode %s{ %sint %sdata; %sstruct %sNode %s*%snext; };\n%sstruct %sNode %s*%shead %s= %smalloc%s(%ssizeof%s(%sstruct %sNode));\nhead->data = %s100%s;\n%sfree%s(head);\n%sprintf%s(%s%c%cd%c%s, head->data);\n\n", c2(13),c2(10),c2(16),c2(14),c2(16),c2(13),c2(10),c2(16),c2(10),c2(13),c2(10),c2(16),c2(10),c2(16),c2(12),c2(16),c2(13),c2(16),c2(13),c2(16),c2(14),c2(16),c2(12),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16));
      
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,16/*data pos*/,"dangling pointer access", "double free", "no error", "memory leak","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the output here ?\n\n");
    // Display the question
    printf("%sstruct %sNode %s{ %sint %sdata; %sstruct %sNode %s*%snext; };\n%sstruct %sNode %s*%shead %s= %smalloc%s(%ssizeof%s(%sstruct %sNode));\nhead->data = %s100%s;\n%sfree%s(head);\n%sprintf%s(%s%c%cd%c%s, head->data);\n\n", c2(13),c2(10),c2(16),c2(14),c2(16),c2(13),c2(10),c2(16),c2(10),c2(13),c2(10),c2(16),c2(10),c2(16),c2(12),c2(16),c2(13),c2(16),c2(13),c2(16),c2(14),c2(16),c2(12),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16));

    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,16/*data pos*/,"dangling pointer access", "double free", "no error", "memory leak","After free(), the pointer is no longer valid.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,23); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,25); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("Accessing head->data after free( head ) is invalid.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz


    
    return complite_quiz;
}

int cq30_l3(int *life){ // question 4 for level 3 for midium level
    pair W_size = get_cnl_wh();
    int round=10,high_si=1,level=3,choice =1,stp=0,ans=0,correct_ans=3,time_limit=15,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mPredict the output here-\n\n",2);
    // Display the question
    printf("%schar %sstr1[%s20%s] = %s''HELLO''%s;\n%schar %sstr2[%s20%s] = %s''CODECRAFTER''%s;\n%sstrcat%s(str1,str2);\n%sprintf%s(%s%c%cs%c%s, str1);\n\n",c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(12),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,15/*data pos*/,"HELLO", "CODECRAFTER", "HELLOCODECRAFTER", "Error","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mPredict the output here-\n\n");
    // Display the question
    printf("%schar %sstr1[%s20%s] = %s''HELLO''%s;\n%schar %sstr2[%s20%s] = %s''CODECRAFTER''%s;\n%sstrcat%s(str1,str2);\n%sprintf%s(%s%c%cs%c%s, str1);\n\n",c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(12),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16));
    
    ans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,15/*data pos*/,"HELLO", "CODECRAFTER", "HELLOCODECRAFTER", "Error"," It joins the two words ",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        
        set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,22); //data pos+7
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
       ans=-1;
        break;
    }
    }
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),*life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15),high_score_r(high_si),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),score,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,24); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back = 0; // Set back to false if '@' is pressed
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("strcat(str1, str2) appends str2 to str1. str1 becomes 'HELLOCODECRAFTER'.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;34mPress for next round...\033[0m",3);
   char chr=_getch();
   if(chr=='@'){
       back = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    return complite_quiz;
}

//QUESTION CODE ENDS HERE

int (*level_qeasy[])() = {cq1_l1,cq2_l1,cq3_l1,cq4_l2,cq5_l2,cq6_l2,cq7_l3,cq8_l3,cq9_l3,cq10_l3 /* other levels can be added here */}; // Array of function pointers for level 1 questions
int (*level_qmedium[])() = {cq11_l1,cq12_l1,cq13_l1,cq14_l1,cq15_l2,cq16_l2,cq17_l2,cq18_l3,cq19_l3,cq20_l3 /* level 2 functions */ }; // Array of function pointers for level 2 questions
int (*level_qhard[])() = {cq21_l1,cq22_l1,cq23_l1,cq24_l2,cq25_l2,cq26_l2,cq27_l3,cq28_l3,cq29_l3,cq30_l3 /* level 3 functions */ }; // Array of function pointers for level 3 questions


void score_board_b(int complite_quiz, int life){ // Function to display the score board
      system("cls");
     pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x/2)-4,0);
    printf("%sCODECRAFT\n\n",c2(15));
     set_cnl_pos((W_size.x/2)-7,(W_size.y/2)-4);
     if(life==0) animation("\033[1;31mGAME OVER 0_0",2);
     else        animation("\033[1;31mGAME COMPLETE",2);
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2)-2);
     printf("%sYour current score: %02d%s",c2(15),score,c2(0));
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2)-1);
     printf("%sYour High score: %02d%s",c2(15),high_score_r(1),c2(0));
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2));
     printf("%sYour Complete Quiz: %02d%s",c2(15),complite_quiz,c2(0));
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2)+2);
     animation("\033[1;34mPress any key for next...\033[0m",3);
     _getch();

   score = 0;

}

void easy_q(){ // Function for easy quiz
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+4);
    animation("\033[1;32mStarting Easy Quiz...\n",2);
    int life=3,complite_quiz=0;
    for(int i=0;i<10 && back;i++){
       complite_quiz += level_qeasy[i](&life);
        if(life==0)break;
    }
    score_board_b(complite_quiz, life); // Call the score board function
    back = 1; // Reset back flag after quiz completion
}

void medium_q(){ // Function for medium quiz
     pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+4);
    animation("\033[1;32mStarting Medium Quiz...\n",2);
    int life=3,complite_quiz=0;
    for(int i=0;i<10 && back;i++){
       complite_quiz += level_qmedium[i](&life);
        if(life==0)break;
    }
    score_board_b(complite_quiz, life); // Call the score board function
    back = 1; // Reset back flag after quiz completion
}

void hard_q(){ // Function for hard quiz
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+4);
    animation("\033[1;32mStarting Hard Quiz...\n",2);
    int life=3,complite_quiz=0;
    for(int i=0;i<10 && back;i++){
       complite_quiz += level_qhard[i](&life);
        if(life==0)break;
    }
    score_board_b(complite_quiz, life); // Call the score board function
    back = 1; // Reset back flag after quiz completion
}



void code_quiz() { // Main function for the code quiz
    system("cls");
    int choose = 1, stp = 0;
    char ch;
    

while (1) {
  
    dis_level(choose, stp++, "CODE QUIZ");
    ch = _getch();
    if ((ch == 'w' || ch == 'W' || ch == 72) && choose > 1) choose--;
    else if ((ch == 'x' || ch == 'X' || ch == 80) && choose < 4) choose++;
    else if (ch == '\r' || ch == 's' || ch == 'S') {
        if (choose == 1) easy_q();
        else if (choose == 2) medium_q();
        else if (choose == 3) hard_q();
        else if (choose == 4)  break;
        
    }
}
score = 0; // Reset score after exiting the quiz
}