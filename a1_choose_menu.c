#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include "g_color.c"

#include "h_consol.c"

#include "j_game_w.c"

void user()
{

    pair W_size = get_cnl_wh(); // Get console window size

    int choose = 1;

    char ch;

    char username[21];

    while (1)
    {

        system("cls");

        set_cnl_pos((W_size.x / 2) - 4, 0);

        printf("%sCODECRAFT\n\n", c2(15));

        set_cnl_pos((W_size.x / 2) - 7, (W_size.y / 2) - 5);

        printf("%s--LOGING PAGE--\n", c2(16));

        set_cnl_pos((W_size.x / 2) - 5, (W_size.y / 2) - 3);

        printf("%s%sLogin%s\n", c2(11), choose == 1 ? "-> " : "   ", c2(0));

        set_cnl_pos((W_size.x / 2) - 8, (W_size.y / 2) - 2);

        printf("%s%sCreate User%s\n", c2(14), choose == 2 ? "-> " : "   ", c2(0));

        ch = _getch();

        if ((ch == 'w' || ch == 'W' || ch == 72) && choose > 1)
            choose--;

        else if ((ch == 'x' || ch == 'X' || ch == 80) && choose < 2)
            choose++;

        else if (ch == '\r' || ch == 's' || ch == 's')

        {

            if (choose == 1)
            {

                system("cls");

                set_cnl_pos((W_size.x / 2) - 4, 0);

                printf("%sCODECRAFT\n\n", c2(15));

                set_cnl_pos((W_size.x / 2) - 7, (W_size.y / 2) - 5);

                animation("\033[1;33m--LOGING PAGE--", 3);

                set_cnl_pos((W_size.x / 2) - 4, (W_size.y / 2) - 1);

                printf("%sUsername", c2(11));

                set_cnl_pos((W_size.x / 2) - 4, (W_size.y / 2));

                scanf("%10s", username); // Read username from user input

                system("cls");

                int inc = search_file(username); // Search for the user file

                if (inc)
                {

                    animation("\n\033[1;31mEnter a key to continue...", 2); // Animation function to indicate file not found

                    _getch();

                    return; // If user file found, return to main menu
                }
            }

            else if (choose == 2)
            {

                system("cls");

                set_cnl_pos((W_size.x / 2) - 4, 0);

                printf("%sCODECRAFT\n\n", c2(15));

                set_cnl_pos((W_size.x / 2) - 6, (W_size.y / 2) - 5);

                animation("\033[1;33m--SIGN UP--", 3);

                set_cnl_pos((W_size.x / 2) - 23, (W_size.y / 2) - 3);

                printf("%sNote: %sUsername must be less than 20 characters\n", c2(11), c2(7));

                set_cnl_pos((W_size.x / 2) - 4, (W_size.y / 2) - 1);

                printf("%sUsername\n ", c2(11));

                set_cnl_pos((W_size.x / 2) - 4, (W_size.y / 2));

                scanf("%20s", username); // Read username from user input

                system("cls");

                int inc = create_file(username); // Create a new user file

                if (inc)
                {

                    animation("\n\033[1;31mEnter a key to continue...", 2); // Animation function to indicate file not found

                    _getch();

                    return; // If user file found, return to main menu
                }
            }

            c1(7);

            printf("\nPress any key to continue...\n");

            _getch(); // Wait for user input
        }
    }
}

void dis_nvg()
{ // Navigation screen

    system("cls");

    pair W_size = get_cnl_wh(); // Get console window size

    set_cnl_pos((W_size.x / 2) - 4, 0);

    printf("%sCODECRAFT\n\n", c2(15));

    c1(14);

    set_cnl_pos((W_size.x / 2) - 17, (W_size.y / 2) - 7);

    animation("Navigation arrows written down below", 2);

    set_cnl_pos((W_size.x / 2) - 1, (W_size.y / 2) - 4);

    printf("W");

    set_cnl_pos((W_size.x / 2) - 1, (W_size.y / 2) - 3);

    printf("^");

    set_cnl_pos((W_size.x / 2) - 7, (W_size.y / 2) - 1);

    printf("A<    S    >D");

    set_cnl_pos((W_size.x / 2) - 1, (W_size.y / 2) + 1);

    printf("v");

    set_cnl_pos((W_size.x / 2) - 1, (W_size.y / 2) + 2);

    printf("X");

    set_cnl_pos((W_size.x / 2) - 14, (W_size.y / 2) + 5);

    animation("\033[1;35mPress any key to continue...\n", 2);

    c1(7);

    _getch();
}

// Function to display the welcome screen

void dis_wel()
{

    system("cls");

    pair W_size = get_cnl_wh(); // Get console window size

    set_cnl_pos((W_size.x / 2) - 4, 0);

    printf("%sCODECRAFT\n\n", c2(15));

    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 2);

    animation("\033[1;31mWELCOME TO CODECRAFT !\n\n", 2);

    set_cnl_pos((W_size.x / 2) - 17, (W_size.y / 2));

    animation("\033[0;33mA game to test your coding skills.\n", 2.5);

    set_cnl_pos((W_size.x / 2) - 14, (W_size.y / 2) + 1);

    animation("\033[0;34mPress any key to continue...\n", 3);

    _getch();
}

// Function to display the main menu

void dis_menu(int choose, int stp)
{

    system("cls");

    pair W_size = get_cnl_wh(); // Get console window size

    set_cnl_pos((W_size.x / 2) - 4, 0);

    printf("%sCODECRAFT\n\n", c2(15));

    set_cnl_pos((W_size.x / 2) - 4, 4);

    if (stp == 0)
        animation("\033[1;35mMain Menu\n\n", 2);

    else
        printf("%sMain Menu%s\n\n", c2(14), c2(0));

    set_cnl_pos((W_size.x / 2) - 6, 6);

    printf("%s%sCode Quiz%s\n", c2(11), choose == 1 ? "-> " : " ", c2(0));

    set_cnl_pos((W_size.x / 2) - 6, 7);

    printf("%s%sSyntax Sprint%s\n", c2(12), choose == 2 ? "-> " : " ", c2(0));

    set_cnl_pos((W_size.x / 2) - 6, 8);

    printf("%s%sBug Hunter%s\n", c2(13), choose == 3 ? "-> " : " ", c2(0));

    set_cnl_pos((W_size.x / 2) - 6, 9);

    printf("%s%sType Master%s\n", c2(14), choose == 4 ? "-> " : " ", c2(0));

    set_cnl_pos((W_size.x / 2) - 6, 10);

    printf("%s%sMix Mode%s\n", c2(15), choose == 5 ? "-> " : " ", c2(0));

    set_cnl_pos((W_size.x / 2) - 6, 11);

    printf("%s%sAbout%s\n", c2(16), choose == 6 ? "-> " : " ", c2(0));

    set_cnl_pos((W_size.x / 2) - 6, 12);

    printf("%s%sExit%s\n", c2(10), choose == 7 ? "-> " : " ", c2(0));
}

// Function to display the level selection screen

void dis_exit()
{

    system("cls");

    pair W_size = get_cnl_wh(); // Get console window size

    set_cnl_pos((W_size.x / 2) - 4, 0);

    printf("%sCODECRAFT\n\n", c2(15));

    animation("\033[1;33mTHANK YOU FOR PLAYING CODECRAFT !", 20);

    printf("%s  (^-^)\n\n\n", c2(10));

    animation("\033[0;34m=>> Did You Enjoy The Coding Adventure ?", 20);

    printf("%s  (*o*)\n\n", c2(10));

    animation("\033[1;37mYou've just experienced the amazing world of \033[1;34mCODECRAFT \033[1;37mby being our amazing \033[0;34mCODECRAFTER \033[1;37mwhile having a blast of enjoyment ! \n\033[1;37mWe hope you leveled up your programming prowess by aced \033[1;31mCODE QUIZ \033[1;37m, raced against logic in \033[1;31mSYNTAX SPRINT \033[1;37m, hunted down bugs\nwildly in \033[1;31mBUG HUNTER  \033[1;37mor typed like a pro in \033[1;31mTYPE MASTER \033[1;37m.\n\n\n", 40);

    animation("\033[1;32m=>> WHAT'S NEXT ?", 10);

    printf("%s  (*-*)\n\n", c2(10));

    animation("\033[1;32m# \033[0;36mChallenge Yourself Again ", 20);

    printf("%s---> Try %sMIX MODE %sfor the ultimate test ...!\n", c2(8), c2(6), c2(8));

    animation("\033[1;32m# \033[0;36mBeat Your High Score ", 20);

    printf("%s---> Can you conquer %sHARD %smode ...?\n", c2(8), c2(6), c2(8));

    animation("\033[1;32m# \033[0;36mShare with Friends ", 20);

    printf("%s---> Who's the %sBEST CODER %sin your Squad ...?\n\n", c2(8), c2(6), c2(8));

    animation("\033[1;35m||> DARE IF YOU CAN DO BETTER NEXT TIME ... DARE IF YOU WANT TO PROVE YOURSELF THE BEST CODECRAFTER EVER  ...<||", 30);

    printf("%s  (>-*)\n\n", c2(10));

    animation("\033[1;36m=>>Farewell, Future Code Master !", 10);

    printf("%s  (>-<)\n\n", c2(10));

    animation("\033[1;37mThe best debugger is a good night's sleep ... or another round of ", 20);

    printf("%sCODECRAFT !\n\n", c2(13));

    animation("\033[1;33m=>> Made With :\n\n", 20);

    animation("\033[1;31m*THE C GURU*", 20);

    printf("%s  (*+*)\n\n", c2(10));

    animation("\033[1;34m# Keep Coding... Keep Crafting...#\n\n", 20);

    // end code -SAMIRA

    c1(5);

    printf("\nPress any key to exit the game...\n");

    _getch();

    c1(7);
}

// Function to display the about screen

void dis_about()
{

    system("cls");

    pair W_size = get_cnl_wh(); // Get console window size

    set_cnl_pos((W_size.x / 2) - 4, 0);

    printf("%sCODECRAFT\n\n", c2(15));

    animation("\033[1;34mABOUT CODECRAFT :\n\n\n", 20);

    animation("\033[1;37mWelcome to \033[0;35mThe Ultimate Coding Challenge Arena \033[1;33mCODECRAFT \033[1;37m; The World of \033[0;33mConsole-based C Game\033[1;37m.\n\nThis is an interactive game designed with the combination of \033[0;36mlearning skill \033[1;37m, \033[0;36mquick-thinking skill \033[1;37m, \033[0;36mlogic building\nskill\033[1;37m,\033[0;36m typing skill \033[1;37mwith a lots of fun and entertainment for our \033[0;33mCODECRAFTERS\033[1;37m. If you are a beginner in programming\nand looking to strengthen your  fundamentals with easy syntax and with fun then \033[1;33m CODECRAFT \033[1;37moffers you a \033[0;35mdynamic and\nchallenging experience.\n\n\n", 50);

    animation("\033[1;32mMini-Games Breakdown :\n\n", 20);

    animation("\033[1;32m} \033[1;31mCODE QUIZ \033[0;32m==> \033[1;37mTest your knowledge of  C Programming  with a  fast-paced quiz !  Answer  multiple-choice  questions\n  covering concepts, functions and logic to prove your expertise.\n\n", 30);

    animation("\033[1;32m} \033[1;31mSYNTAX SPRINT \033[0;32m==> \033[1;37mA race against time! Fill in the missing syntax in incomplete code snippets. Can you reconstruct\n  the code correctly before the clock runs out..?\n\n", 30);

    animation("\033[1;32m} \033[1;31mBUG HUNTER \033[0;32m==> \033[1;37mDebug like a pro ! Hunt down errors  in buggy code segments, fix  and make the program run smoothly.\n  Perfect for improving problem-solving skills.\n\n", 30);

    animation("\033[1;32m} \033[1;31mTYPE MASTER \033[0;32m==> \033[1;37mSpeed and accuracy  matter! Type out  given code snippets  within a strict  time limit. The faster\n  and more precise you are, the higher you score!\n\n\n", 30);

    animation("\033[1;36mGame Modes & Difficulty Levels For \033[1;34mCODECRAFTERS \033[1;36m: ", 20);

    printf("%s  (x.x)\n\n\n", c2(10));

    animation("\033[1;32mEasy \033[0;37m, \033[1;33mMedium \033[0;37m, \033[1;31mHard \033[0;36m--> \033[0;37mEach mini-game features three difficulty levels, ensuring a smooth learning curve.\n\n", 30);

    animation("\033[1;35mMIX MODE \033[0;36m--> \033[0;37mFeeling adventurous ? \033[1;31m(*.0) \033[0;37mPlay a randomized mix of all four games for the ultimate coding challenge !\n\n\n", 30);

    animation("\033[1;35mWhy Play CODECRAFT ?\n\n", 20);

    animation("\033[1;32mo \033[0;37mLearn C Programming in a Fun Way\n\033[1;32mo \033[0;37mImprove Debugging & Syntax Skills\n\033[1;32mo \033[0;37mEnhance Typing Speed for Coding\n\033[1;32mo \033[0;37mTest Knowledge with Real-World Challenges\n\033[1;32mo \033[0;37mCompete Against Yourself & Beat High Scores\n\n\033[0;36mDive into \033[1;34mCODECRAFT \033[0;36mand transform coding practice into an exciting adventure ! \n\033[1;37mCan you conquer all levels and become the ultimate \033[0;34mCODECRAFTER ? \033[1;31m(0-0)\n\n\n", 45);

    animation("\033[1;33mTHE C GURU :\n\n", 20);

    animation("\033[1;32m* \033[0;34mSayem Islam Leon\n\033[1;32m> \033[1;36mID : \033[0;37m20244103117\n\033[1;32m* \033[0;31mSamira  Ibrahim\n\033[1;32m> \033[1;36mID : \033[0;37m20244103085\n\033[1;32m* \033[0;32mMotmayeen Billah\n\033[1;32m> \033[1;36mID : \033[0;37m20244103083\n\033[1;32m* \033[0;35mSuborna Akter\n\033[1;32m> \033[1;36mID : \033[0;37m20244103092\n\033[1;32m* \033[0;33mFarjana Shanjida Shinzu\n\033[1;32m> \033[1;36mID : \033[0;37m20244103115\n\n", 30);

    printf("\nPress any key to return to the menu...\n");

    _getch();

    c1(7);
}
