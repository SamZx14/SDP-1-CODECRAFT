#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>

int score_b = 0;
int back_b = 1;
void check_bug(int round,int high_si,int level,int time_limit,int *life,int *complite_syntax,int data_pos,int line,const char *ans,const char *explanation ){
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
                back_b=0; // If the user wants to go back, set back_b to 0
                *life = 0; // Set life to 0 to end the game
                return; // Exit the function
            }
            in_line = in_line1 - '0'; // Convert the character to an integer
         set_cnl_pos(W_size.x-12,5);
         time_diff =time(NULL)-start;
         printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
         
         if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("BUG HUNTER",round,score_b,high_si,level,*life);
               set_cnl_pos(0,data_pos);
                animation("\033[1;31mTime Up\033[0m",4);
      
        }
        else if(in_line!=line){ // Check if the user's answer is correct
              (*life)--; // Decrement the line number if the answer is incorrect
              dis_score("BUG HUNTER",round,score_b,high_si,level,*life); // Display the score
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
                dis_score("BUG HUNTER",round,score_b,high_si,level,*life);
                set_cnl_pos(0,data_pos+2);
                animation("\033[1;31mTime Up\033[0m",4);
      
            }
                else if(strcmp(in_ans, ans) == 0) {
                score_b += 10; // Increment score by 10 for correct answer
                (*complite_syntax)++; // Increment the completed syntax count
                high_score_w(score_b,high_si);
                dis_score("BUG HUNTER",round,score_b,high_si,level,*life); // Display the score
                set_cnl_pos(0,data_pos+2);
                animation("\033[1;32mCorrect!", 2);
                }
                else {
                    (*life)--; // Decrement life if the answer is incorrect
                    dis_score("BUG HUNTER",round,score_b,high_si,level,*life); // Display the score
                    set_cnl_pos(0,data_pos+2);
                    animation("\033[1;31mIncorrect!", 2);
                }
                data_pos+=2;
        }
        break;
      }
      if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("SYNTAX S-PRINT",round,score_b,high_si,level,*life);
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
        back_b=0; // If the user wants to go back, set back_b to 0
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
        back_b=0; // If the user wants to go back, set back_s to 0
        *life = 0; // Set life to 0 to end the game
        return; // Exit the function
    }
}

//EASY LEVEL QUESTIONS CODE STARTS FROM HERE

int bh1_l1(int *life) {//question 1 for easy level 1
    int round = 1, high_si = 3, level = 1, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %sint %sx = %s5%s;\n%s4  %sif %s(x = %s10%s) {\n%s5%s  printf%s(%s\"x is 10\\n\"%s);\n%s6%s  }\n%s7  %sreturn %s0%s;\n%s8  %s}",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(10),c2(16),c2(8),c2(13),c2(16),c2(10),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(16),c2(8),c2(13),c2(10),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 17 /*data pos*/, 4/*line*/, "if (x == 10) {", "The condition should use '==' for comparison, not '=' for assignment.");
    return complite_bug;
}

int bh2_l1(int *life){//question 2 for easy level 1
    int round = 2, high_si = 3, level = 1, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %sint %sa = %s10%s, b = %s20%s;\n%s4  %sif %s(a>b); {\n%s5  %sprintf%s(%s\"a is greater\"%s);\n%s6  %s}\n%s7  %sreturn %s0%s;\n%s8  %s}",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(10),c2(16),c2(14),c2(16),c2(8),c2(13),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16)); 
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 17 /*data pos*/, 4/*line*/, "if (a>b) {", "Semicolon after if - unconditional execution of printf.");
    return complite_bug;
}

int bh3_l2(int *life) {//question 1 for easy level 2
    int round = 3, high_si = 3, level = 2, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %schar %sage = %s25%s;\n%s4  %sprintf%s(%s\"Age: %%c\\n\"%s,age);\n%s5  %sreturn %s0%s;\n%s6  %s}",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 15 /*data pos*/, 3/*line*/, "char age = '25';", "25 should stored in single quotation for character type data.");
    return complite_bug;
}

int bh4_l2(int *life){//question 2 for easy level 2
    int round = 4, high_si = 3, level = 2, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %sint %sarr[%s5%s] = {%s1%s,%s2%s,%s3%s,%s4%s,%s5%s};\n%s4  %sprintf%s(%s\"%%d\"%s,arr[%s5%s]); %s//print the last element\n%s5  %sreturn %s0%s;\n%s6  %s}",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(14),c2(16),c2(6),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 15 /*data pos*/, 4/*line*/, "printf(\"%d\",arr[4]);", "It will be arr[4]; Valid indices: arr[0] to arr[4]");
    return complite_bug;
}

int bh5_l3(int *life) {//question 1 for easy level 3
    int round = 5, high_si = 3, level = 3, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %sint %snumber;\n%s4  %sprintf %s(%s\"Enter a number: \"%s);\n%s5  %sscanf%s(%s\"%%d\"%s, number);\n%s6  %sprintf%s(%s\"You entered: %%d\\n\"%s, number);\n%s7  %sreturn %s0%s; \n%s8  %s}",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 17 /*data pos*/, 5/*line*/, "scanf(\"%d\", &number);", "Missing '&' before number in scanf.");
    return complite_bug;
}

int bh6_l3(int *life){//question 2 for easy level 3
    int round = 6, high_si = 3, level = 3, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %schar %sname[%s20%s];\n%s4  %sgets(name,%s20%s,%sstdin%s);\n%s5  %sprintf%s(%s\"Name: \"%s,name);\n%s6  %sreturn %s0%s;\n%s7  %s} ",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(8),c2(16),c2(14),c2(16),c2(12),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 16 /*data pos*/, 4/*line*/, "fgets(name,20,stdin);", "Missing letter 'f'. It should be 'fgets'; which safely takes input.");
    return complite_bug;
}

//MIDIUM LEVEL QUESTIONS CODE STARTS FROM HERE

int bh7_l1(int *life) {//question 1 for midium level 1
    int round = 1, high_si = 3, level = 1, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %sint %sx = %s10%s;\n%s4  %sif %s(x > %s10%s)\n%s5  %sprintf%s(%s\"x is greater than or equal to 10\\n\"%s);\n%s6  %selse if %s(x > %s5%s)\n%s7  %sprintf%s(%s\"x is greater than 5\\n\"%s);\n%s8  %sreturn %s0%s;\n%s9  %s} ",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(8),c2(13),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 18 /*data pos*/, 4/*line*/, "if (x >= 10)", "The condition x > 10 is incorrect for the message. It should be x >= 10.");
    return complite_bug;
}

int bh8_l1(int *life){//question 2 for midium level 1
    int round = 2, high_si = 3, level = 1, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %sint %ssum = %s0%s;\n%s4  %sfor%s(%sint %si = %s1%s;i <= %s5%s;i++) {\n%s5  %ssum = i;\n%s6  %s}\n%s7  %sprintf%s(%s\"Sum = %%d\"%s,sum);\n%s8  %sreturn %s0%s;\n%s9  %s} ",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(8),c2(13),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(8),c2(16),c2(8),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 18 /*data pos*/, 5/*line*/, "sum =+ i;", "Only assigns i to sum, doesn't accumulate.");
    return complite_bug;
}

int bh9_l2(int *life) {//question 1 for midium level 2
    int round = 3, high_si = 3, level = 2, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smultiply %s(%sint %sa, %sint %sb) {\n%s3  %sreturn %sa + b;\n%s4  %s}\n%s5  %sint %smain%s() {\n%s6  %sint %sresult = multiply(%s3%s, %s4%s);\n%s7  %sprintf%s(%s\"Result: %%d\\n\"%s, result);\n%s8  %sreturn %s0%s;\n%s9  %s}\n\nOutput -> %s12",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(8),c2(13),c2(16),c2(8),c2(16),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16),c2(14));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 20 /*data pos*/, 3/*line*/, "return a * b;", "Should return a * b, not a + b.");
    return complite_bug;
}

int bh10_l2(int *life){//question 2 for midium level 2
    int round = 4, high_si = 3, level = 2, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %sfactorial%s(%sint %sn) {\n%s3  %sif%s(n == %s0%s)\n%s4  %sreturn %s0%s;\n%s5  %sreturn %sn*factorial(n - %s1%s);\n%s6  %s}\n%s7  %sint %smain%s() {\n%s8  %sprintf%s(%s\"Factorial: %%d\"%s,factorial(%s4%s));\n%s9  %sreturn %s0%s;\n%s10  %s}",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(14),c2(16),c2(8),c2(13),c2(16),c2(14),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(13),c2(16),c2(14),c2(16),c2(8),c2(16),c2(8),c2(14),c2(10),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(14),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 19 /*data pos*/, 4/*line*/, "return 1;", "Base case should return 1 (factorial of 0 = 1).");
    return complite_bug;
}

int bh11_l3(int *life) {//question 1 for midium level 3
    int round = 5, high_si = 3, level = 3, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %svoid %supdate%s(%sint %s*x) {\n%s3  %s*x = *x + %s1%s;\n%s4  %s}\n%s5  %sint %smain%s() {\n%s6  %sint %sa = %s5%s;\n%s7  %supdate%s(a);\n%s8  %sprintf%s(%s\"%%d\\n\"%s, a);\n%s9  %sreturn %s0%s;\n%s10  %s}\n\nOutput -> %s6",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(14),c2(16),c2(8),c2(16),c2(14),c2(16),c2(8),c2(16),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16),c2(14));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 21 /*data pos*/, 7/*line*/, "update(&a);", "Passed a instead of &a, pointer not receiving address.");
    return complite_bug;
}

int bh12_l3(int *life){//question 2 for midium level 3
    int round = 6, high_si = 3, level = 3, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %s#%sinclude%s<string.h>\n%s3  %sint %smain%s() {\n%s4  %sconst char %sstr1 = %s\"Hello\"%s;\n%s5  %sconst char %s*str2 = %s\"Hello\"%s;\n%s6  %sif %s(%sstrcmp %s(str1, str2) == %s0%s) {\n%s7  %sprintf%s(%s\"Strings are the same\"%s);\n%s8  %s}\n%s9  %sreturn %s0%s;\n%s10  %s} ",c2(8),c2(16),c2(13),c2(11),c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(10),c2(16),c2(11),c2(16),c2(8),c2(10),c2(16),c2(11),c2(16),c2(8),c2(13),c2(16),c2(12),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 19 /*data pos*/, 4/*line*/, "const char *str1 = \"Hello\";", "str1 should be a pointer to a constant string.");
    return complite_bug;
}

//HARD LEVEL QUESTIONS CODE STARTS FROM HERE

int bh13_l1(int *life) {//question 1 for hard level 1
    int round = 1, high_si = 3, level = 1, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %s#%sinclude %s<string.h>\n%s3  %sint %smain%s() {\n%s4  %schar %sstr[%s10%s];\n%s5  %sprintf%s(%s\"Enter a string: \"%s);\n%s6  %sscanf%s(%s\"%%s\"%s, str);\n%s7  %sif %s(%sstrlen%s(str) = %s5%s)\n%s8  %sprintf%s(%s\"String length is 5\\n\"%s);\n%s9  %selse\n%s10  %sprintf%s(%s\"String length is not 5\\n\"%s);\n%s11  %sreturn %s0%s;\n%s12  %s}",c2(8),c2(16),c2(13),c2(11),c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(16),c2(12),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 21 /*data pos*/, 7/*line*/, "if (strlen(str) == 5)", "The condition uses assignment (=) instead of equality check (==), so it always sets strlen(str) to 5 (which is invalid), causing unexpected behavior.");
    return complite_bug;
}

int bh14_l1(int *life){//question 2 for hard level 1
    int round = 2, high_si = 3, level = 1, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %sint %sarr[%s5%s] = {%s1%s,%s2%s,%s3%s,%s4%s,%s5%s};\n%s4  %ssum = %s0%s;\n%s5  %sfor%s(%sint %si = %s0%s;i <= %s5%s;i++) {\n%s6  %ssum += arr[i];\n%s7  %sprintf%s(%s\"Sum = %%d\"%s,sum);\n%s8  %sreturn %s0%s;\n%s9  %s} ",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(8),c2(16),c2(14),c2(16),c2(8),c2(13),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(8),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 18 /*data pos*/, 5/*line*/, "for(int i = 0;i < 5;i++) {", "Loop condition should be i < 5 (not i <= 5) to avoid out-of-bounds access.");
    return complite_bug;
}

int bh15_l2(int *life){//question 1 for hard level 2
    int round = 3, high_si = 3, level = 2, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sstruct %sPoint %s{\n%s3  %sint %sx;\n%s4  %sint %sy;\n%s5  %s};\n%s6  %sint %smain%s() {\n%s7  %sstruct %sPoint p1%s;\n%s8  %sp1.x = %s5%s;\n%s9  %sp1.j = %s7%s;\n%s10  %sprintf%s(%s\"Point: (%%d, %%d)\"%s,p1.x,p1.y);\n%s11  %s}\n%s12  %sreturn %s0%s;\n%s13  %s}\n\nOutput -> Point: (%s5%s, %s7%s)",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(8),c2(14),c2(16),c2(8),c2(16),c2(8),c2(14),c2(10),c2(16),c2(8),c2(13),c2(10),c2(16),c2(8),c2(16),c2(14),c2(16),c2(8),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16),c2(14),c2(16),c2(14),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 24 /*data pos*/, 9/*line*/, "p1.y = 7;", "The variable p1.y is not initialized");
    return complite_bug;
}

int bh16_l2(int *life){//question 2 for hard level 2
    int round = 4, high_si = 3, level = 2, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %s#%sinclude%s<stdlib.h>\n%s3  %sint %s*arr = %smalloc%s(%s5 %s* %ssizeof%s(%sint%s));\n%s4  %sarr[%s5%s] = %s100%s;\n%s5  %sprintf%s(%s\"%%d\"%s,arr[%s4%s]);\n%s6  %sfree%s(arr);\n%s7  %sreturn %s0%s;\n%s8  %s}\n\nOutput -> %s100",c2(8),c2(16),c2(13),c2(11),c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(16),c2(12),c2(16),c2(14),c2(16),c2(13),c2(16),c2(14),c2(16),c2(8),c2(16),c2(14),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(14),c2(16),c2(8),c2(12),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16),c2(14));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 19 /*data pos*/, 4/*line*/, "arr[4] = 100;", "Out-of-bounds access.");
    return complite_bug;
}

int bh17_l3(int *life){//question 1 for hard level 3
    int round = 5, high_si = 3, level = 3, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %sFILE *fp = fopen(%s\"data.txt\"%s,%s\"r\"%s);\n%s4  %sif%s(fp) {\n%s5  %sprintf%s(%s\"File opened successfully\"%s);\n%s6  %s}\n%s7  %selse %s{\n%s8  %sprintf%s(%s\"Failed to open file\"%s);\n%s9  %s}\n%s10  %sfclose(fp);\n%s11  %sreturn %s0%s;\n%s12  %s} ",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(16),c2(11),c2(16),c2(11),c2(16),c2(8),c2(13),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(16),c2(8),c2(13),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(16),c2(8),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 21 /*data pos*/, 4/*line*/, "if (fp != 0) {", "Should be if (fp != 0) to explicitly check if the file opened correctly.");
    return complite_bug;
}

int bh18_l3(int *life){//question 2 for hard level 3
    int round = 6, high_si = 3, level = 3, time_limit = 60, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n%s3  %schar %s*p = %s\"Hello\"%s;\n%s4  %sp[%s0%s] = %s'h'%s;\n%s5  %sprintf%s(%s\"%%s\"%s,p);\n%s6  %sreturn %s0%s;\n%s7  %s} ",c2(8),c2(16),c2(13),c2(11),c2(8),c2(14),c2(10),c2(16),c2(8),c2(14),c2(16),c2(11),c2(16),c2(8),c2(16),c2(14),c2(16),c2(11),c2(16),c2(8),c2(12),c2(16),c2(11),c2(16),c2(8),c2(13),c2(14),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 16 /*data pos*/, 3/*line*/, "p[] = \"Hello\";", "Writing to string literal is undefined behavior.");
    return complite_bug;
}

//QUESTION CODE ENDS HERE

int (*level_beasy[])() = {bh1_l1,bh2_l1,bh3_l2,bh4_l2,bh5_l3,bh6_l3 /*other levels can be added here */}; // Array of function pointers for level 1 questions
int (*level_bmedium[])() = {bh7_l1,bh8_l1,bh9_l2,bh10_l2,bh11_l3,bh12_l3/*level 2 functions */}; // Array of function pointers for level 2 questions
int (*level_bhard[])() = {bh13_l1,bh14_l1,bh15_l2,bh16_l2,bh17_l3,bh18_l3/*level 3 functions */}; // Array of function pointers for level 3 questions

void score_board_bug(int complite_bug, int life) { // Function to display the score board
    system("cls");
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 4, 0);
    printf("%sCODECRAFT\n\n", c2(15));
    set_cnl_pos((W_size.x / 2) - 7, (W_size.y / 2) - 4);
    if (life == 0) animation("\033[1;31mGAME OVER 0_0", 2);
    else        animation("\033[1;31mGAME COMPLETE", 2);
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) - 2);
    printf("%sYour current score: %02d%s", c2(15), score_b, c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) - 1);
    printf("%sYour High score: %02d%s", c2(15), high_score_r(3), c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2));
    printf("%sYour Complete Bug: %02d%s", c2(15), complite_bug, c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) + 2);
    animation("\033[1;34mPress any key for next...\033[0m", 3);
    _getch();

    score_b = 0;
}

void easy_b() { // Function for easy bug hunting
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Easy Bug Hunter...\n", 2);
    int life = 3, complite_bug=0;
    for (int i = 0; i < 6 && back_b; i++) {
        complite_bug += level_beasy[i](&life);
        if (life == 0) break;
    }
    score_board_bug(complite_bug, life); // Call the score board function
    back_b = 1; // Reset back_b to 1 for the next game
}

void medium_b() { // Function for medium bug hunting
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Medium Bug Hunter...\n", 2);
    int life = 3, complite_bug=0;
    for (int i = 0; i < 6 && back_b; i++) {
        complite_bug += level_bmedium[i](&life);
        if (life == 0) break;
    }
    score_board_bug(complite_bug, life); // Call the score board function
    back_b = 1; // Reset back_b to 1 for the next game
}

void hard_b() { // Function for hard bug hunting
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Hard Bug Hunter...\n", 2);
    int life = 3, complite_bug=0;
    for (int i = 0; i < 6 && back_b; i++) {
        complite_bug += level_bhard[i](&life);
        if (life == 0) break;
    }
    score_board_bug(complite_bug, life); // Call the score board function
    back_b = 1; // Reset back_b to 1 for the next game
}

void bug_hunter() {
     system("cls");
    int choose=1,stp=0;
    char ch='1';
    while(1){
    dis_level(choose,stp++,"BUG HUNTER"); // Display the level selection menu
    ch=_getch();
    if((ch == 'w' || ch == 'W' || ch == 72) && choose > 1) choose--;
    else if((ch == 'x' || ch == 'X' || ch == 80) && choose < 4) choose++;
    else if(ch == 's' || ch == 'S' || ch == '\r'){
        if(choose == 1)easy_b();
        else if(choose == 2)medium_b();
        else if(choose == 3)hard_b();
        else if(choose == 4)break;
    }
    }
}