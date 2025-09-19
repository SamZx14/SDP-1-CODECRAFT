#include<stdio.h>
#include<string.h>
char filename[30]; // Buffer to store the filename
char ending[] = ".txt";
int ar[5]={0,0,0,0,0}; // Array to store high scores for 5 games
char us[21];
    
int search_file(char name[]){ // Function to search for a file based on the username
    strcpy(us,name); // Copy the username to a global variable
    strcpy(filename, "x_");
    strcat(filename,name); // Concatenate the username to the filename
    strcat(filename,ending); // Append the file extension
    
    FILE *fp = fopen(filename, "r+"); // Open the file in read/write mode
    if(fp == NULL) {
       animation("\033[1;31mUser not found. Create a new account ...\n",2); // Animation function to indicate file not found
       fclose(fp); // Close the file
       return 0; // Return 0 to indicate failure
    } else {
        char line[50];
        strcpy(line,"\033[1;35mWelcome ");
        strcat(line,name); // Concatenate the username to the welcome message
       animation(line,2); // Animation function to indicate success
    }
    fclose(fp); // Close the file
    return 1;
}

int create_file(char name[]){ // Function to create a new file based on the username
    strcpy(us,name); // Copy the username to a global variable
    strcpy(filename, "x_"); // Initialize filename with prefix
    strcat(filename,name); // Concatenate the username to the filename
    strcat(filename,ending); // Append the file extension
    
    FILE *fp = fopen(filename, "r+"); // Open the file in read/write mode
    if(fp != NULL) {
       animation("\033[1;31mUser already exist, please login...\n",2);
       fclose(fp);
       return 0;
    }

    else {
        fp = fopen(filename, "w+"); // Open the file in write mode
    if(fp == NULL) {
        animation("\033[1;31mError creating file.\n",2); // Animation function to indicate error
    } else {
        char line[50];
        strcpy(line,"\033[1;35mWelcome ");
        strcat(line,name); // Concatenate the username to the welcome message
        animation(line,2); // Animation function to indicate success
        for(int i=0;i<5;i++){
            fprintf(fp,"%d\n",0); // Initialize high scores to 0
        }
    }

}
    fclose(fp); // Close the file
    return 1; // Return 1 to indicate success
}


int high_score_r(int game){
    FILE *fp;
    fp = fopen(filename,"r+");
    if(fp != NULL) {
        for(int i=0;i<5;i++){
            fscanf(fp,"%d\n",&ar[i]);
        }
        fclose(fp);
    }
    return ar[game-1];

}
void high_score_w(int score,int game){
    high_score_r(game);
    ar[game-1]=(score > ar[game-1])?score:ar[game-1];
    FILE *fp;
    fp = fopen(filename,"w+");
    if (fp != NULL) {
        for(int i=0;i<5;i++){
            fprintf(fp,"%d\n",ar[i]);
        }
        fclose(fp);
    }
}

void dis_level(int choose,int stp,const char *game) // Function to display the level selection screen
{
    system("cls");
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x/2)-4,0);
    printf("%sCODECRAFT\n\n",c2(15));
    set_cnl_pos((W_size.x/2)-(strlen(game)/2),1);
    printf("%s%s%s\n",c2(11),game,c2(0));
    set_cnl_pos((W_size.x/2)-4,(W_size.y/2)-5);
    if(stp==0) animation("\033[1;35mLevel Menu\n\n",2);
    else printf("%sLevel Menu%s\n\n",c2(14),c2(0));
    set_cnl_pos((W_size.x/2)-3,(W_size.y/2)-3);
    printf("%s%sEasy%s\n",c2(11),choose==1?"-> ":" ",c2(0));
    set_cnl_pos((W_size.x/2)-3,(W_size.y/2)-2);
    printf("%s%sMedium%s\n",c2(12),choose==2?"-> ":" ",c2(0));
    set_cnl_pos((W_size.x/2)-3,(W_size.y/2)-1); 
    printf("%s%sHard%s\n",c2(13),choose==3?"-> ":" ",c2(0));
    set_cnl_pos((W_size.x/2)-3,(W_size.y/2));
    printf("%s%sBack%s\n",c2(10),choose==4?"-> ":" ",c2(0));
    set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+3);
    if(stp==0) animation("\033[1;35mPlease choose a level... \n",2);
    c1(7);
}

// Function to display the score screen
// This function displays the current score, high score, level, time, and life remaining
void dis_score(const char *name,int rnd,int c_score,int h_score,int lev,int life ){

    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x/2)-4,0);
    printf("%sCODECRAFT",c2(15));
    int len = strlen(name);
    set_cnl_pos((W_size.x/2)-(len/2),1);
    printf("%s%s%s",c2(14),name,c2(0));
    set_cnl_pos((W_size.x/2)-4,3);
    printf("%sLevel: %02d%s",c2(15),lev,c2(0));
    set_cnl_pos(0,4);
    printf("%sRound: %02d",c2(15),rnd);
    set_cnl_pos(W_size.x-11,4);
    printf("%sLife: %02d%s",c2(15),life,c2(0));
    set_cnl_pos(0,W_size.y-1);
    printf("%sHigh Score: %02d%s",c2(15), high_score_r(h_score),c2(0));
    set_cnl_pos(W_size.x-20,W_size.y-1);
    printf("%sCurrent Score: %02d %s",c2(15),c_score,c2(0));
    if (h_score==1) {
        set_cnl_pos((W_size.x/2)-7,(W_size.y)-2);
        printf("%sBack: Shift+2%s",c2(1),c2(0));
    } else {
        set_cnl_pos((W_size.x/2)-10,(W_size.y)-2);
        printf("%sBack: Shift+2, Enter%s",c2(1),c2(0));
    }
    set_cnl_pos((W_size.x/2)-6,(W_size.y)-1);
    printf("%sUser: %s%s",c2(15),us,c2(0));
    
}
