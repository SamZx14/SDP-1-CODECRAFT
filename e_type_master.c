#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
double avg_speed=0.0,
       avg_right=0.0,
       avg_wrong=0.0,
       avg_accuracy=0.0;
int score_t=0;
int back_t=1; // Global variables to store score and back status
void check_ans_type(int round, int high_si,int level,int time_limit,int *life,int *comlite_type,int line,char *ans[]){  // Function to check the answer
   
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
               dis_score("TYPE MASTER",round,score_t,high_si,level,*life);
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
               dis_score("TYPE MASTER",round,score_t,high_si,level,*life);
               set_cnl_pos(0, 10+line+(line-line1)+1);
                animation("\033[1;31mTime Up\033[0m",4);
                line1=0;
        }
    }
    if(time_diff<time_limit){
        speed= total_in_char/ (time_al/60);
        if(right == 0) speed = 0;// Avoid division by zero
       
        accuracy = (right / total_char) * 100; // Calculate accuracy
         score_t +=( accuracy/10); // Update the score based on accuracy
         high_score_w(score_t,high_si);
                dis_score("TYPE MASTER",round,score_t,high_si,level,*life); // Display the score
        (*comlite_type)++;
        system("cls");
         set_cnl_pos((W_size.x / 2) - 4, 0);
    printf("%sCODECRAFT", c2(15));
      set_cnl_pos((W_size.x / 2) - 5, 1);
    printf("%sTYPE MASTER", c2(14));

    set_cnl_pos((W_size.x / 2) - 5, (W_size.y / 2) - 4);
    animation("\033[1;31mDash Board", 2);
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 2);
    printf("%sYour current score: %02d%s", c2(13), score_t, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 1);
    printf("%sYour right input: %03d%s", c2(13), (int)right, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) );
    printf("%sYour wrong input: %03d%s", c2(13), (int)wrong, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2)+1);
    printf("%sYour typing speed: %04.2lf c/m%s", c2(13),speed, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) + 2);
        printf("%sYour accuracy: %04.2lf%%\n%s", c2(13), accuracy, c2(0));

    avg_right+=right;
    avg_wrong+=wrong;
    avg_speed+=speed;
    avg_accuracy+= accuracy;

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

//EASY LEVEL QUESTIONS CODE STARTS FROM HERE

int tm1_l1(int *life){//question 1 for easy level 1
    pair W_size = get_cnl_wh();
    int round = 1, high_si = 4, level = 1, time_limit = 70, complite_type =0,line=5;
    char *ans[] = {"#include <stdio.h>", "int main() {", "printf(\"Hello, World!\\n\");", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sprintf%s(%s\"Hello, World!\\n\"%s);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm2_l1(int *life){//question 2 for easy level 1
    pair W_size = get_cnl_wh();
    int round = 2, high_si = 4, level = 1, time_limit = 80, complite_type =0,line=6;
    char *ans[] = {"#include <stdio.h>", "int main() {", "char c = \'A\';", "printf(\"%%c\", c);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%schar %sc = %s\'A\'%s;\n%sprintf%s(%s\"%%c\"%s, c);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(11),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm3_l2(int *life){//question 3 for easy level 2
    pair W_size = get_cnl_wh();
    int round = 3, high_si = 4, level = 2, time_limit = 80, complite_type =0,line=6;
    char *ans[] = {"#include <stdio.h>", "int main() {", "float pi = 3.14;", "printf(\"%%.2f\", pi);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sfloat %spi = %s3.14%s;\n%sprintf%s(%s\"%%.2f\"%s, pi);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm4_l2(int *life){//question 4 for easy level 2
    pair W_size = get_cnl_wh();
    int round = 4, high_si = 4, level = 2, time_limit = 80, complite_type =0,line=6;
    char *ans[] = {"#include <stdio.h>", "int main() {", "char name[20] = \"CodeCraft\";", "printf(\"%%s\", name);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%schar %sname[%s20%s] = %s\"CodeCraft\"%s;\n%sprintf%s(%s\"%%s\"%s, name);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(11),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm5_l3(int *life){//question 5 for easy level 3
    pair W_size = get_cnl_wh();
    int round = 5, high_si = 4, level = 3, time_limit = 100, complite_type =0,line=9;
    char *ans[] = {"#include <stdio.h>", "int main() {", "int i = 0;", "while (i < 3) {", "printf(\"Loop\\n\");", "i++;", "}", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sint %si = %s0%s;\n%swhile %s(i < %s3%s) {\n%sprintf%s(%s\"Loop\\n\"%s);\ni++;\n}\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm6_l4(int *life){//question 6 for easy level 3
    pair W_size = get_cnl_wh();
    int round = 6, high_si = 4, level = 3, time_limit = 100, complite_type =0,line=10;
    char *ans[] = {"#include <stdio.h>", "int main() {", "for (int i = 0; i < 3; i++) {", "if (i == 1) {", "continue;", "}", "printf(\"%%d\", i);", "}", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sfor %s(%sint %si = %s0%s; i < %s3%s; i++) {\n%sif %s(i == %s1%s) {\ncountinue;\n%sprintf%s(%s\"%%d\"%s, i);\n}\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(13),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

//MIDIUM LEVEL QUESTIONS CODE STARTS FROM HERE

int tm7_l1(int *life){//question 1 for midium level 1
    pair W_size = get_cnl_wh();
    int round = 1, high_si = 4, level = 1, time_limit = 80, complite_type =0,line=6;
    char *ans[] = {"#include <stdio.h>", "int main() {", "int x = 3, y = 4, z = 5;", "printf(\"%%d\", x * y * z);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sint %sx = %s3%s, y = %s4%s, z = %s5%s;\n%sprintf%s(%s\"%%d\"%s, x * y * z);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm8_l1(int *life){//question 2 for midium level 1
    pair W_size = get_cnl_wh();
    int round = 2, high_si = 4, level = 1, time_limit = 90, complite_type =0,line=8;
    char *ans[] = {"#include <stdio.h>", "int main() {", "int value = 5;", "int sum = 10;", "sum += value;", "printf(\"%%d\", sum);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sint %svalue = %s5%s;\n%sint %ssum = %s10%s;\nsum += value;\n%sprintf%s(%s\"%%d\"%s, sum);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm9_l2(int *life){//question 3 for midium level 2
    pair W_size = get_cnl_wh();
    int round = 3, high_si = 4, level = 2, time_limit = 80, complite_type =0,line=6;
    char *ans[] = {"#include <stdio.h>", "int main() {", "int arr[3] = {1, 2, 3};", "printf(\"%%d\", arr[0]);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sint %sarr[%s3%s] = {%s1%s, %s2%s, %s3%s};\n%sprintf%s(%s\"%%d\"%s, arr[%s0%s]);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(14),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm10_l2(int *life){//question 4 for midium level 2
    pair W_size = get_cnl_wh();
    int round = 4, high_si = 4, level = 2, time_limit = 90, complite_type =0,line=8;
    char *ans[] = {"#include <stdio.h>", "void greet() {", "printf(\"Hi CodeCrafter !\");", "}", "int main() {", "greet();", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%svoid %sgreet%s() {\n%sprintf%s(%s\"Hi CodeCrafter !\"%s);\n}\n%sint %smain%s() {\ngreet();\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(12),c2(16),c2(11),c2(16),c2(14),c2(10),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm11_l3(int *life){//question 5 for midium level 3
    pair W_size = get_cnl_wh();
    int round = 5, high_si = 4, level = 3, time_limit = 100, complite_type =0,line=9;
    char *ans[] = {"#include <stdio.h>", "int factorial(int n) {", "if (n == 0) {", "return 1;", "}", "int main() {", "printf(\"%%d\", factorial(4));", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %sfactorial%s(%sint %sn) {\n%sif %s(n == %s0%s) {\n%sreturn %s1%s;\n}\n%sint %smain%s() {\n%sprintf%s(%s\"%%d\"%s, factorial(%s4%s));\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(13),c2(16),c2(14),c2(16),c2(13),c2(14),c2(16),c2(14),c2(10),c2(16),c2(12),c2(16),c2(11),c2(16),c2(14),c2(16),c2(13),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm12_l3(int *life){//question 6 for midium level 3
    pair W_size = get_cnl_wh();
    int round = 6, high_si = 4, level = 3, time_limit = 120, complite_type =0,line=15;
    char *ans[] = {"#include <stdio.h>", "int main() {", "int choice = 2;", "switch (choice) {", "case 1:", "printf(\"One\");", "break;", "case 2:", "printf(\"Two\");", "break;", "default:", "printf(\"Other\");", "}", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sint %schoice = %s2%s;\n%sswitch %s(choice) {\n%scase %s1%s:\n%sprintf%s(%s\"CODECRAFT\"%s);\n%sbreak%s;\n%scase %s2%s:\n%sprintf%s(%s\"CRAFTCODE\"%s);\n%sbreak%s;\n%sdefault%s:\n%sprintf%s(%s\"CODECRAFTER\"%s);\n}\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(13),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(16),c2(13),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(16),c2(13),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

//HARD LEVEL QUESTIONS CODE STARTS FROM HERE

int tm13_l1(int *life){//question 1 for hard level 1
    pair W_size = get_cnl_wh();
    int round = 1, high_si = 4, level = 1, time_limit = 80, complite_type =0,line=6;
    char *ans[] = {"#include <stdio.h>", "int main() {", "int num = 7;", "(num %% 2 == 0) ? printf(\"Even\") : printf(\"Odd\");", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sint %snum = %s7%s;\n(num %% %s2 %s== %s0%s) ? %sprintf%s(%s\"Even\"%s) : %sprintf%s(%s\"Odd\"%s);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm14_l1(int *life){//question 2 for hard level 1
    pair W_size = get_cnl_wh();
    int round = 2, high_si = 4, level = 1, time_limit = 70, complite_type =0,line=6;
    char *ans[] = {"#include <stdio.h>", "#define PI 3.1416", "int main() {", "printf(\"%%.4f\", PI);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%s#%sdefine %sPI 3.1416\n%sint %smain%s() {\n%sprintf%s(%s\"%%.4f\"%s, PI);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(16),c2(13),c2(16),c2(14),c2(10),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm15_l2(int *life){//question 3 for hard level 2
    pair W_size = get_cnl_wh();
    int round = 3, high_si = 4, level = 2, time_limit = 90, complite_type =0,line=7;
    char *ans[] = {"#include <stdio.h>", "#include <stdlib.h>", "int main() {", "int *arr = (int *)malloc(5 * sizeof(int));", "free(arr);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%s#%sinclude %s<stdlib.h>\n%sint %smain%s() {\n%sint %s*arr = (%sint %s*)%smalloc%s(%s5 %s* %ssizeof%s(%sint%s));\n%sfree%s(arr);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(14),c2(16),c2(13),c2(16),c2(14),c2(16),c2(12),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm16_l2(int *life){//question 4 for hard level 2
    pair W_size = get_cnl_wh();
    int round = 4, high_si = 4, level = 2, time_limit = 100, complite_type =0,line=9;
    char *ans[] = {"#include <stdio.h>", "#include <string.h>", "int main() {", "char src[20] = \"Code\";", "char dest[20];", "strcpy(dest, src);", "printf(\"%%s\", dest);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%s#%sinclude %s<string.h>\n%sint %smain%s() {\n%schar %ssrc[%s20%s] = %s\"Code\"%s;\n%schar %sdest[%s20%s];\n%sstrcpy%s(dest, src);\n%sprintf%s(%s\"%%s\"%s, dest);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(11),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm17_l3(int *life){//question 5 for hard level 3
    pair W_size = get_cnl_wh();
    int round = 5, high_si = 4, level = 3, time_limit = 150, complite_type =0,line=13;
    char *ans[] = {"#include <stdio.h>", "#include <stdlib.h>", "int main() {", "FILE *fp = fopen(\"data.txt\", \"r\");", "if (fp == NULL) {", "return 1;", "}", "char line[100];", "fgets(line, 100, fp);", "printf(\"%%s\", line);", "fclose(fp);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%s#%sinclude %s<stdlib.h>\n%sint %smain%s() {\nFILE *fp = fopen(%s\"data.txt\"%s, %s\"r\"%s);\n%sif %s(fp == %sNULL%s) {\n%sreturn %s1%s;\n}\n%schar %sline[%s100%s];\nfgets(line, %s100%s, fp);\n%sprintf%s(%s\"%%s\"%s, line);\nfclose(fp);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(11),c2(16),c2(11),c2(16),c2(13),c2(16),c2(13),c2(16),c2(13),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

int tm18_l3(int *life){//question 6 for hard level 3
    pair W_size = get_cnl_wh();
    int round = 6, high_si = 4, level = 3, time_limit = 110, complite_type =0,line=10;
    char *ans[] = {"#include <stdio.h>", "struct Student {", "int id;", "char name[20];", "};", "int main() {", "struct Student s = {1, \"CodeCrafter\"};", "printf(\"%%d %%s\", s.id, s.name);", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sstruct %sStudent %s{\n%sint %sid;\n%schar %sname[%s20%s];\n};\n%sint %smain%s() {\n%sstruct %sStudent s %s= {%s1%s, %s\"CodeCrafter\"%s};\n%sprintf%s(%s\"%%d %%s\"%s, s.id, s.name);\n%sreturn %s0%s;\n}\n",c2(16),c2(13),c2(11),c2(13),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(10),c2(16),c2(13),c2(10),c2(16),c2(14),c2(16),c2(11),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
    return complite_type;
}

//QUESTION CODE ENDS HERE

int (*level_teasy[])() = {tm1_l1,tm2_l1,tm3_l2,tm4_l2,tm5_l3,tm6_l4 /* other levels can be added here */}; // Array of function pointers for level 1 questions
int (*level_tmedium[])() = {tm7_l1,tm8_l1,tm9_l2,tm10_l2,tm11_l3,tm12_l3/* level 2 functions */}; // Array of function pointers for level 2 questions
int (*level_thard[])() = {tm13_l1,tm14_l1,tm15_l2,tm16_l2,tm17_l3,tm18_l3/* level 3 functions */}; // Array of function pointers for level 3 questions

void score_board_t(int complite_type, int life) { // Function to display the score board
    system("cls");
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 4, 0);
    printf("%sCODECRAFT\n\n", c2(15));
    set_cnl_pos((W_size.x / 2) - 7, (W_size.y / 2) - 6);
    if (life == 0) animation("\033[1;31mGAME OVER 0_0", 2);
    else        animation("\033[1;31mGAME COMPLETE", 2);
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 4);
    printf("%sYour right input: %03d%s", c2(14),(complite_type==0)? 0: ((int)avg_right/complite_type), c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 3);
    printf("%sYour wrong input: %03d%s", c2(14), (complite_type==0)? 0:((int)avg_wrong/complite_type), c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2)-2);
    printf("%sYour typing speed: %lf w/m%s", c2(14),(complite_type==0)? 0: (avg_speed/complite_type), c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) -1);
    printf("%sYour accuracy: %lf%%\n%s", c2(14),(complite_type==0)? 0:( avg_accuracy/complite_type), c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) +1);
    printf("%sYour current score: %02d%s", c2(15), score_t, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) +2);
    printf("%sYour High score: %02d%s", c2(15), high_score_r(4), c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) +3);
    printf("%sYour Complete Type: %02d%s", c2(15), complite_type, c2(0));
     set_cnl_pos((W_size.x / 2) - 11, W_size.y -2);
    animation("\033[1;34mPress any key for next...\033[0m", 3);
    _getch();

    score_t = 0;
}

void easy_t() { // Function for easy type master
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Easy Type Master...\n", 2);
    int life = 3, complite_type=0;
    for (int i = 0; i < 6; i++) {
        complite_type += level_teasy[i](&life);
        if (life == 0) break;
    }
    score_board_t(complite_type, life); // Call the score board function
}

void medium_t() { // Function for medium type master
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Medium Type Master...\n", 2);
    int life = 3, complite_type=0;
    for (int i = 0; i < 6; i++) {
        complite_type += level_tmedium[i](&life);
        if (life == 0) break;
    }
    score_board_t(complite_type, life); // Call the score board function
}

void hard_t() { // Function for hard type master
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Hard Type Master...\n", 2);
    int life = 3, complite_type=0;
    for (int i = 0; i < 6; i++) {
        complite_type += level_thard[i](&life);
        if (life == 0) break;
    }
    score_board_t(complite_type, life); // Call the score board function
}

void type_master() {
   system("cls");
    int choose = 1, stp = 0;
    char ch='1';
    while (1) {
        system("cls");
        dis_level(choose, stp++, "TYPE MASTER"); // Display the level menu
        ch = _getch();
        if ((ch == 'w' || ch == 'W' || ch == 72) && choose > 1) choose--;
        else if ((ch == 'x' || ch == 'X' || ch == 80) && choose < 4) choose++;
        else if (ch == '\r' || ch == 's' || ch == 's') {
            if (choose == 1) easy_t(); // Call the easy type master function
            else if (choose == 2) medium_t(); // Call the medium type master function
            else if (choose == 3) hard_t(); // Call the hard type master function
            else if (choose == 4) break;
        }
    }
}