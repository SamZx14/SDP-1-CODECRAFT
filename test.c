#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>




 int main (){ // Main function for the code quiz
  char *ar[5]={"ami tonake ok","ienbt thde dgg", "pirntf{}","ok","3444kk"};
  char ar1[100]="printf(\"sss\");",ar2[100];
 fgets(ar2,sizeof(ar1),stdin);
 ar2[strcspn(ar2,"\n")]=0;
   if(strcmp(ar1,ar2)==0)printf("ok\n");
   else printf("No\n");
   printf("%s\n",ar2);
  printf("%s\n",ar1);
return 0;
} 