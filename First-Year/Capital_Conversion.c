/*Create Code that will make the input 
Capital If more letters are capital 
and Small caps If more letters are smaller*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

main (void){
     int i, upper=0, lower=0;
     char input[1000];
     
     printf(">> Enter string of letters with different Capitalizations: ");
     fgets(input, sizeof(input), stdin);

     for (i=0; i < strlen(input); i++){
          if (input[i] >= 65 && input[i] <= 90){
               upper++;
               continue;
          }
          else if (input[i] >= 97 && input[i] <= 122){
               lower++;
               continue;
          }
     }

     if (upper >= lower)
          strupr(input);
     else 
          strlwr(input);

     puts(input);

     return 0;
}