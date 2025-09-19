#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>

int score_m=0; // Global variable to store score for mix mode
int back_m=1; // Global variable to store back status for mix mode

double mavg_speed=0.0,
       mavg_right=0.0,
       mavg_wrong=0.0,
       mavg_accuracy=0.0;

void mans_nvg(char *ch,int *choice,int *ans,int Ans,int inc,int *stp, int round, int high_si, int level, int life,int data_pos, const char *op_a, const char *op_b, const char *op_c, const char *op_d, const char *hint,int *hint_pos){
  
    data_pos+=6;
    if (*stp==0) animation("\033[1;32mChoose the correct answer:\n\n",3);
    else printf("\033[1;32mChoose the correct answer:\n\n");
    if ((*ch == 'd' || *ch == 'D' || *ch == 77) && *choice < 5) (*choice)++;
    else if ((*ch == 'a' || *ch == 'A' || *ch == 75) && *choice > 1) (*choice)--;
    else if ((*ch == 'w' || *ch == 'W' || *ch == 72) && (*choice ==3 || *choice ==4 || *choice == 5)) *choice-=2;
    else if ((*ch == 'x' || *ch == 'X' || *ch == 80) && (*choice ==1 || *choice ==2 || *choice == 3)) *choice+=2;
    if (*ch == '@') {
        back_m = 0; // Set back to false if '@' is pressed
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
            score_m += inc; // Increment score by 10 for correct answer
            high_score_w(score_m, 5); // Update high score for code quiz
            set_cnl_pos(0,data_pos+1);
            animation("\033[1;32mCorrect!", 2);
           
        }
        else if (*choice == 5&&*hint_pos==0) {
            (*hint_pos)++;
            score_m -= 5; // Increment score by 5 for incorrect answer
            high_score_w(score_m, 5); // Update high score for code quiz
            set_cnl_pos(0,data_pos);
            printf("%s%s",c2(11),hint);
        }
        
    }
   
}

void mcheck_ans(int round,int high_si,int level,int time_limit,int *life,int *complite_syntax,int ans_pos_x,int ans_pos_y,int data_pos,const char *ans,const char *explanation){ // Function to check the answer
    data_pos+=3;
    pair W_size = get_cnl_wh();
    c1(11);
    animation("\n\nType your answer here to complete the code and level up!",3); // Prompt the user to type their answer
    time_t start = time(NULL),time_diff; // Start the timer
     char in_ans[15]; // Variable to store the user's input
  
    while(1){
     
      time_diff =time(NULL)-start; // Calculate the time difference
       set_cnl_pos(W_size.x-12,5);
       printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
       if(_kbhit()){ // Check if a key is pressed
        set_cnl_pos(ans_pos_x,ans_pos_y);
        c1(3);
        scanf("%s",&in_ans);
        if(strcmp(in_ans,"@") == 0) {
            back_m=0; // If the user wants to go back, set back_m to 0
            *life = 0; // Set life to 0 to end the game
            return; // Exit the function
        }
         set_cnl_pos(ans_pos_x,ans_pos_y);
         c1(10);
         in_ans[strcspn(in_ans, "\n")] = 0; // Remove the newline character from the input
         set_cnl_pos(W_size.x-12,5);
         time_diff =time(NULL)-start;
         printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
         
         if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("MIX MODE",round,score_m,high_si,level,*life);
               set_cnl_pos(0,data_pos);
                animation("\033[1;31mTime Up\033[0m",4);
        }
         set_cnl_pos(W_size.x-12,5);
         time_diff =time(NULL)-start;
         printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer

         if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("MIX MODE",round,score_m,high_si,level,*life);
               set_cnl_pos(0,data_pos);
                animation("\033[1;31mTime Up\033[0m",4);
      
        }
        else if(strcmp(ans,in_ans)==0){ // Check if the user's answer is correct
              score_m+=10; // Increment score by 10 for correct answer
              (*complite_syntax)++; // Increment the completed syntax count
              high_score_w(score_m,high_si);
              dis_score("MIX MODE",round,score_m,high_si,level,*life); // Display the score
              set_cnl_pos(0,data_pos);
              animation("\033[1;32mCorrect!", 2); 
        }
        else { // If the answer is incorrect

              high_score_w(score_m,high_si);
              dis_score("MIX MODE",round,score_m,high_si,level,*life); // Display the score
              ( *life)--;
              dis_score("MIX MODE",round,score_m,high_si,level,*life);
              set_cnl_pos(0,data_pos);
              animation("\033[1;31mIncorrect!", 2);

        }
        break;
      }
      if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("MIX MODE",round,score_m,high_si,level,*life);
               set_cnl_pos(0,data_pos);
            animation("\033[1;31mTime Up\033[0m",4);
            break;
        }
     
    }
      
     c1(10);
      set_cnl_pos(0,data_pos+2);
    if(strcmp(ans,in_ans)!=0){ // If the answer is incorrect
        animation("For the explanation press Y, else press N\n",3);
    char ex_ch=_getch();
    if(ex_ch=='@'){
        back_m=0; // If the user wants to go back, set back_s to 0
        *life = 0; // Set life to 0 to end the game
        return; // Exit the function
    }
    if(ex_ch=='y'||ex_ch=='Y') { // If the user wants to see the explanation
        animation(explanation,4);
    }
    }
    char chr;
    set_cnl_pos(0,(W_size.y)-4);
    animation("\033[1;34mPress for next round...\033[0m",3);
    chr=_getch();
    if(chr=='@'){
        back_m=0; // If the user wants to go back, set back_m to 0
        *life = 0; // Set life to 0 to end the game
        return; // Exit the function
    }
    
}

void mcheck_bug(int round,int high_si,int level,int time_limit,int *life,int *complite_syntax,int data_pos,int line,const char *ans,const char *explanation ){
 data_pos+=2;
    pair W_size = get_cnl_wh();
    c1(11);
    animation("\n\nEnter the line number where you found the problem: ",3); // Prompt the user to type their answer
    time_t start = time(NULL),time_diff; // Start the timer
    char in_line1; // Variable to store the user's input
    int in_line;
    char in_ans[200]; // Variable to store the user's input
    while(1){
     
      time_diff =time(NULL)-start; // Calculate the time difference
       set_cnl_pos(W_size.x-12,5);
       printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
       if(_kbhit()){ // Check if a key is pressed
         c1(10);
         set_cnl_pos(52,data_pos-1);
         scanf("%c",&in_line1); // Read the line number from the user
            if(in_line1=='@') { // If the user wants to go back
                back_m=0; // If the user wants to go back, set back_m to 0
                *life = 0; // Set life to 0 to end the game
                return; // Exit the function
            }
            in_line = in_line1 - '0'; // Convert the character to an integer
         set_cnl_pos(W_size.x-12,5);
         time_diff =time(NULL)-start;
         printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
         
         if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("MIX MODE",round,score_m,high_si,level,*life);
               set_cnl_pos(0,data_pos);
                animation("\033[1;31mTime Up\033[0m",4);
      
        }
        else if(in_line!=line){ // Check if the user's answer is correct
              (*life)--; // Decrement the line number if the answer is incorrect
              dis_score("MIX MODE",round,score_m,high_si,level,*life); // Display the score
              set_cnl_pos(0,data_pos);
              animation("\033[1;31mIncorrect line Number!", 2); 
        }
        else { // If the answer is incorrect
             set_cnl_pos(0,data_pos+1);
             c1(11);
             animation("Input the corrected code line exactly as you would write it.", 3);
             c1(8);
             animation("\n[make sure to include spaces and formatting as shown in the question].", 2);
             data_pos+=3;
              set_cnl_pos(0,data_pos);
                c1(10);
              fgets(in_ans, sizeof(in_ans), stdin); // Read the corrected code line from the user
              set_cnl_pos(W_size.x-12,5);
              time_diff =time(NULL)-start;
              printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
                in_ans[strcspn(in_ans, "\n")] = 0; // Remove the newline character from the input
                 if(time_diff>=time_limit){ // Check if the time limit is exceeded
                ( *life)--;
                dis_score("MIX MODE",round,score_m,high_si,level,*life);
                set_cnl_pos(0,data_pos+2);
                animation("\033[1;31mTime Up\033[0m",4);
      
            }
                else if(strcmp(in_ans, ans) == 0) {
                score_m += 10; // Increment score by 10 for correct answer
                (*complite_syntax)++; // Increment the completed syntax count
                high_score_w(score_m,high_si);
                dis_score("MIX MODE",round,score_m,high_si,level,*life); // Display the score
                set_cnl_pos(0,data_pos+2);
                animation("\033[1;32mCorrect!", 2);
                }
                else {
                    (*life)--; // Decrement life if the answer is incorrect
                    dis_score("MIX MODE",round,score_m,high_si,level,*life); // Display the score
                    set_cnl_pos(0,data_pos+2);
                    animation("\033[1;31mIncorrect!", 2);
                }
                data_pos+=2;
        }
        break;
      }
      if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("MIX MODE",round,score_m,high_si,level,*life);
               set_cnl_pos(0,data_pos);
            animation("\033[1;31mTime Up\033[0m",4);
            break;
        }
     
    }
      
     c1(10);
      set_cnl_pos(0,data_pos+2);
    if(strcmp(ans,in_ans)!=0){ // If the answer is incorrect
        animation("For the explanation press Y, else press N\n",3);
    char ex_ch=_getch();
    if(ex_ch=='@'){
        back_m=0; // If the user wants to go back, set back_m to 0
        *life = 0; // Set life to 0 to end the game
        return; // Exit the function
    }
    if(ex_ch=='y'||ex_ch=='Y') { // If the user wants to see the explanation
        c1(15);
        animation(explanation,4);
    }
    }
    char chr;
    set_cnl_pos(0,(W_size.y)-4);
    animation("\033[1;34mPress for next round...\033[0m",3);
    chr=_getch();

    if(chr=='@'){
        back_m=0; // If the user wants to go back, set back_s to 0
        *life = 0; // Set life to 0 to end the game
        return; // Exit the function
    }
}

void mcheck_ans_type(int round, int high_si,int level,int time_limit,int *life,int *comlite_type,int line,char *ans[]){  // Function to check the answer
   
    // Implement the logic to check the answer for Type Master game
    pair W_size = get_cnl_wh();
    c1(11);
    animation("\n\033[1;32mType the given text as fast as you can!\n", 3);
    c1(8);
    animation("[make sure to include spaces and formatting as shown in the question].\n", 3);
    double speed = 0.0, right = 0.0, wrong = 0.0, accuracy = 0.0,total_char=0,time_al,total_in_char=0; 
    char input[256];
    time_t start = time(NULL),time_diff; // Start the timer
    int line1=line;
    while(line1){
        time_diff = time(NULL) - start; // Calculate the time difference
         set_cnl_pos(W_size.x-12,5);
         printf("%s Time: %03ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
        
        if(_kbhit()){
            for(;line1>0;line1--){
                 set_cnl_pos(0, 10+line+(line-line1));
                 c1(15-(line-line1));
                 fgets(input, sizeof(input), stdin); // Read the input from the user
                 if(strcmp(input, "@\n") == 0) { // If the user wants to go back
                        back_t = 0; // If the user wants to go back, set back_t to 0
                     *life = 0; // Set life to 0 to end the game
                     return; // Exit the function
                 }
                 total_in_char+=strlen(input);
                 time_diff = time(NULL) - start; // Calculate the time difference
                 set_cnl_pos(W_size.x-12,5);
                 printf("%s Time: %03ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
                 time_al=time_diff;
         if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("MIX MODE",round,score_m,high_si,level,*life);
               set_cnl_pos(0, 10+line+(line-line1)+1);
                animation("\033[1;31mTime Up\033[0m",4);
                line1=0;
                break;
      
        }
                 input[strcspn(input, "\n")] = 0; // Remove the newline character from the input
            
                for(int j= 0;j<strlen(ans[line-line1]);j++){
                    if(ans[line-line1][j] != input[j]) wrong++;
                    else right++;
                    total_char++;
                }
              }
            }
             if(line1&&(time_diff>=time_limit)){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("MIX MODE",round,score_m,high_si,level,*life);
               set_cnl_pos(0, 10+line+(line-line1)+1);
                animation("\033[1;31mTime Up\033[0m",4);
                line1=0;
        }
    }
    if(time_diff<time_limit){
        speed= total_in_char/ (time_al/60);
        if(right == 0) speed = 0;// Avoid division by zero
       
        accuracy = (right / total_char) * 100; // Calculate accuracy
         score_m +=( accuracy/10); // Update the score based on accuracy
         high_score_w(score_m,high_si);
                dis_score("MIX MODE",round,score_m,high_si,level,*life); // Display the score
        (*comlite_type)++;
        system("cls");
         set_cnl_pos((W_size.x / 2) - 4, 0);
    printf("%sCODECRAFT", c2(15));
      set_cnl_pos((W_size.x / 2) - 5, 1);
    printf("%sMIX MODE", c2(14));

    set_cnl_pos((W_size.x / 2) - 5, (W_size.y / 2) - 4);
    animation("\033[1;31mDash Board", 2);
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 2);
    printf("%sYour current score: %02d%s", c2(13), score_m, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 1);
    printf("%sYour right input: %03d%s", c2(13), (int)right, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) );
    printf("%sYour wrong input: %03d%s", c2(13), (int)wrong, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2)+1);
    printf("%sYour typing speed: %04.2lf c/m%s", c2(13),speed, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) + 2);
        printf("%sYour accuracy: %04.2lf%%\n%s", c2(13), accuracy, c2(0));

    mavg_right+=right;
    mavg_wrong+=wrong;
    mavg_speed+=speed;
    mavg_accuracy+= accuracy;

    }
    set_cnl_pos((W_size.x / 2) - 11, W_size.y  -2);
     animation("\033[1;34mPress any key for next...\033[0m", 3);
     char chr = _getch(); // Wait for user input
    if (chr == '@') { // If the user wants to go back
        back_t = 0; // Set back_t to 0 to indicate going back
        *life = 0; // Set life to 0 to end the game
        return; // Exit the function
    }
    
}


int mcq1_l1(int *life){ // question 1 for level 1 for easy level
    pair W_size = get_cnl_wh();
    int round=1,high_si=5,level=1,choice =1,stp=0,ans=0,correct_ans=2,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("MIX MODE",round,score_m,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life

    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhich of the following is a valid variable name?\n\n",2);
    // Display the question    
    mans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"321ch", "s_1", "float", "@number","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back_m = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("MIX MODE",round,score_m,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhich of the following is a valid variable name?\n\n");
    // Display the question    
    mans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"321ch", "s_1", "float", "@number","Identifiers must initiate with an alphabetic character or underscore.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
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
    printf("%sCurrent Score: %02d %s",c2(15),score_m,c2(0));
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
int mss1_l1(int *life){//question 1 for easy level 1
    pair W_size = get_cnl_wh();
    int round=2,level=1,high_si=5,time_limit=15,complite_syntax=0;
    const char *ans="int";
    system("cls");
    dis_score("MIX MODE",round,score_m,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%sint %smain%s () {\n%s___%s i = %s0%s; %s// what should be placed here ?\n%swhile%s (i < %s10%s) {\n%sprintf (%s%c%cd%c,%s i);\ni++;\n}\n%sreturn %s0%s;\n\n}",c2(13),c2(10),c2(16),c2(13),c2(16),c2(2),c2(8),c2(6),c2(13),c2(16),c2(2),c2(16),c2(12),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(2),c2(16));
   
   mcheck_ans(round,high_si,level,time_limit,life,&complite_syntax,0/*blank x pos*/,10/*blank y pos*/,18/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34mint\033[0;33m because \033[1;37mi\033[0;33m is an integer variable, and \033[1;34\033[0;33mint is used to declare integer types in \033[1;35mC."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}
int mbh1_l1(int *life) {//question 1 for easy level 1
    int round = 3, high_si = 5, level = 1, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("MIX MODE", round, score_m, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %sint %sx = %s5%s;\n%s4  %sif %s(x = %s10%s) {\n%s5%s  printf%s(%s\"x is 10\\n\"%s);\n%s6%s  }\n%s7  %sreturn %s0%s;\n%s8  %s}",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(10),c2(16),c2(8),c2(13),c2(16),c2(10),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(16),c2(8),c2(13),c2(10),c2(16),c2(8),c2(16));
    mcheck_bug(round, high_si, level, time_limit, life, &complite_bug, 17 /*data pos*/, 4/*line*/, "if (x == 10) {", "The condition should use '==' for comparison, not '=' for assignment.");
    return complite_bug;
}
int mtm1_l1(int *life){//question 1 for easy level 1
    pair W_size = get_cnl_wh();
    int round = 4, high_si = 5, level = 1, time_limit = 70, complite_type =0,line=5;
    char *ans[] = {"#include <stdio.h>", "int main() {", "printf(\"Hello, World!\\n\");", "return 0;", "}"};
    system("cls");
    dis_score("MIX MODE", round, score_m, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sprintf%s(%s\"Hello, World!\\n\"%s);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     mcheck_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int mcq2_l2(int *life){ // question 1 for level 1 for midium level
    pair W_size = get_cnl_wh();
    int round=1,high_si=5,level=2,choice =1,stp=0,ans=0,correct_ans=1,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("MIX MODE",round,score_m,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life

    set_cnl_pos(W_size.x-12,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat does if(0) do ?\n\n",2);
    // Display the question
    mans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"skips the if block", "compilation error", "run the if block", "invalid condition","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
         time_t time_dff=time(NULL)-start; //taking the time different
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            ch=_getch();
            if(ch=='@')  {
                back_m = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("MIX MODE",round,score_m,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat does if(0) do ?\n\n");
    // Display the question    
    mans_nvg(&ch,&choice,&ans,correct_ans,10/*score increment*/,&stp,round,high_si,level,*life,10/*data pos*/,"skips the if block", "compilation error", "run the if block", "invalid condition","Zero is considered as 'false' in C, so the associated block will be bypassed during execution.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
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
    printf("%sCurrent Score: %02d %s",c2(15),score_m,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back_m = 0; // Set back to false if '@' is pressed
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
       back_m = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

 
    
    return complite_quiz;
}

int mss2_l2(int *life){//question 1 for medium level 1
    pair W_size = get_cnl_wh();
    int round=2,level=2,high_si=5,time_limit=15,complite_syntax=0;
    const char *ans="for";
    system("cls");
    dis_score("MIX MODE",round,score_m,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%sint %smain%s(){\n%s___%s(%sint %si = %s0%s; i < %s5%s; i++); %s// what should be placed here ?{\n%sprintf%s(%s%c%cd%c%s,i);\n}\n%sreturn %s0%s;\n\n}",c2(14),c2(10),c2(16),c2(13),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(6),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
   
   mcheck_ans(round,high_si,level,time_limit,life,&complite_syntax,0/*blank x pos*/,10/*blank y pos*/,16/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34mfor\033[0;33m because it is the right keyword to input a condition in \033[1;35mC."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}

int mbh2_l2(int *life) {//question 1 for medium level 1
    int round = 3, high_si = 5, level = 2, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("MIX MODE", round, score_m, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %sint %sx = %s10%s;\n%s4  %sif %s(x > %s10%s)\n%s5  %sprintf%s(%s\"x is greater than or equal to 10\\n\"%s);\n%s6  %selse if %s(x > %s5%s)\n%s7  %sprintf%s(%s\"x is greater than 5\\n\"%s);\n%s8  %sreturn %s0%s;\n%s9  %s} ",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(8),c2(13),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    mcheck_bug(round, high_si, level, time_limit, life, &complite_bug, 18 /*data pos*/, 4/*line*/, "if (x >= 10)", "The condition x > 10 is incorrect for the message. It should be x >= 10.");
    return complite_bug;
}

int mtm2_l2(int *life){//question 1 for midium level 1
    pair W_size = get_cnl_wh();
    int round = 4, high_si = 5, level = 2, time_limit = 80, complite_type =0,line=6;
    char *ans[] = {"#include <stdio.h>", "int main() {", "int x = 3, y = 4, z = 5;", "printf(\"%%d\", x * y * z);", "return 0;", "}"};
    system("cls");
    dis_score("MIX MODE", round, score_m, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sint %sx = %s3%s, y = %s4%s, z = %s5%s;\n%sprintf%s(%s\"%%d\"%s, x * y * z);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     mcheck_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int mcq3_l3(int *life){ // question 2 for level 1 for hard level
    pair W_size = get_cnl_wh();
    int round=1,high_si=5,level=3,choice =1,stp=0,ans=0,correct_ans=2,time_limit=10,hint_pos=0,complite_quiz=0; //high_si == high score index                                                                                                                                                               
    char ch='1';
    system("cls");
    dis_score("MIX MODE",round,score_m,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life

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
                back_m = 0;
                *life = 0; // Set life to 0 if '@' is pressed
                return complite_quiz; // if '@' is pressed, exit the quiz
            } // if '@' is pressed, exit the quiz
    dis_score("MIX MODE",round,score_m,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
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
    printf("%sCurrent Score: %02d %s",c2(15),score_m,c2(0));
    if(ans==correct_ans)complite_quiz=1;
    if(ans!=correct_ans){
          set_cnl_pos(0,19); //data pos+7+2
          if(ans==-1) animation("\033[1;31mPress Y for explanation, else press N for next\n", 3);
            else animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='@')  {
                back_m = 0; // Set back to false if '@' is pressed
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
       back_m = 0; // Set back to false if '@' is pressed
       *life = 0; // Set life to 0 if '@' is pressed
       return complite_quiz; // if '@' is pressed, exit the quiz
   } // if '@' is pressed, exit the quiz

    
    return complite_quiz;
}

int mss3_l3(int *life){//question 1 for hard level 1
    pair W_size = get_cnl_wh();
    int round=2,level=3,high_si=5,time_limit=15,complite_syntax=0;
    const char *ans="1,2,3,4,5";
    system("cls");
    dis_score("MIX MODE",round,score_m,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%s#%sinclude%s<stdio.h>\n%sint %smain%s(){\n%sint %snumber[%s5%s] = {_________}; %s// Note: Ans should be first n number of positive value.\n%sprintf%s(%s%cFirst:%cd%c%s,number[%s0%s]);\n%sreturn %s0%s;\n\n}",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(6),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(14),c2(16),c2(13),c2(14),c2(16));
   
   mcheck_ans(round,high_si,level,time_limit,life,&complite_syntax,17/*blank x pos*/,11/*blank y pos*/,16/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34m'1,2,3,4,5'\033[0;33m because the first 5 numbers are 1,2,3,4,5."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}

int mbh3_l3(int *life) {//question 1 for hard level 1
    int round = 3, high_si = 5, level = 3, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("MIX MODE", round, score_m, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %s#%sinclude %s<string.h>\n%s3  %sint %smain%s() {\n%s4  %schar %sstr[%s10%s];\n%s5  %sprintf%s(%s\"Enter a string: \"%s);\n%s6  %sscanf%s(%s\"%%s\"%s, str);\n%s7  %sif %s(%sstrlen%s(str) = %s5%s)\n%s8  %sprintf%s(%s\"String length is 5\\n\"%s);\n%s9  %selse\n%s10  %sprintf%s(%s\"String length is not 5\\n\"%s);\n%s11  %sreturn %s0%s;\n%s12  %s}",c2(8),c2(16),c2(13),c2(11),c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(16),c2(12),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    mcheck_bug(round, high_si, level, time_limit, life, &complite_bug, 21 /*data pos*/, 7/*line*/, "if (strlen(str) == 5)", "The condition uses assignment (=) instead of equality check (==), so it always sets strlen(str) to 5 (which is invalid), causing unexpected behavior.");
    return complite_bug;
}

int mtm3_l3(int *life){//question 1 for hard level 1
    pair W_size = get_cnl_wh();
    int round = 4, high_si = 5, level = 3, time_limit = 80, complite_type =0,line=6;
    char *ans[] = {"#include <stdio.h>", "int main() {", "int num = 7;", "(num %% 2 == 0) ? printf(\"Even\") : printf(\"Odd\");", "return 0;", "}"};
    system("cls");
    dis_score("MIX MODE", round, score_m, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sint %snum = %s7%s;\n(num %% %s2 %s== %s0%s) ? %sprintf%s(%s\"Even\"%s) : %sprintf%s(%s\"Odd\"%s);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     mcheck_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int (*level_measy[])() = { mcq1_l1, mss1_l1, mbh1_l1, mtm1_l1,/* other levels can be added here */}; // Array of function pointers for level 1 questions
int (*level_mmedium[])() = { mcq2_l2, mss2_l2, mbh2_l2, mtm2_l2,/* level 2 functions */}; // Array of function pointers for level 2 questions
int (*level_mhard[])() = { mcq3_l3, mss3_l3, mbh3_l3, mtm3_l3,/* level 3 functions */}; // Array of function pointers for level 3 questions
void mscore_board_b(int complite_quiz, int life){ // Function to display the score board
      system("cls");
     pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x/2)-4,0);
    printf("%sCODECRAFT\n\n",c2(15));
     set_cnl_pos((W_size.x/2)-7,(W_size.y/2)-4);
     if(life==0) animation("\033[1;31mGAME OVER 0_0",2);
     else        animation("\033[1;31mGAME COMPLETE",2);
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2)-2);
     printf("%sYour current score: %02d%s",c2(15),score_m,c2(0));
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2)-1);
     printf("%sYour High score: %02d%s",c2(15),high_score_r(1),c2(0));
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2));
     printf("%sYour Complete Quiz: %02d%s",c2(15),complite_quiz,c2(0));
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2)+2);
     animation("\033[1;34mPress any key for next...\033[0m",3);
     _getch();

   score_m = 0;

}

void easy_m() { // Function for easy mix mode
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Easy Mix Mode...\n", 2);
    int life = 3, complite_type=0;
    for (int i = 0; i < 4; i++) {
        complite_type += level_measy[i](&life);
        if (life == 0) break;
    }
    mscore_board_b(complite_type, life); // Call the score board function
}

void medium_m() { // Function for medium mix mode
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Medium Mix Mode...\n", 2);
    int life = 3, complite_type=0;
    for (int i = 0; i < 4; i++) {
        complite_type += level_mmedium[i](&life);
        if (life == 0) break;
    }
    mscore_board_b(complite_type, life); // Call the score board function
}

void hard_m() { // Function for hard mix mode
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Hard Mix Mode...\n", 2);
    int life = 3, complite_type=0;
    for (int i = 0; i < 4; i++) {
        complite_type += level_mhard[i](&life);
        if (life == 0) break;
    }
    mscore_board_b(complite_type, life); // Call the score board function
}


void mix_mode() {
    back_m=1; 
   system("cls");
    int choose = 1, stp = 0;
    char ch='1';
    while (1) {
        system("cls");
        dis_level(choose, stp++, "MIX MODE"); // Display the level menu
        ch = _getch();
        if ((ch == 'w' || ch == 'W' || ch == 72) && choose > 1) choose--;
        else if ((ch == 'x' || ch == 'X' || ch == 80) && choose < 4) choose++;
        else if (ch == '\r' || ch == 's' || ch == 's') {
            if (choose == 1) easy_m(); // Call the easy mix mode function
            else if (choose == 2) medium_m(); // Call the medium mix mode function
            else if (choose == 3) hard_m(); // Call the hard mix mode function
            else if (choose == 4) break;
        }
    }
}