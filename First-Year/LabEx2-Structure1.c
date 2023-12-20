/* Laboratory Exercise 2 - Part 1
     - always show 2d array seat assignment
     - input: seat number
          - Error when already taken
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

//Structure Declaration
struct airplane {                                 
     int repeat, col, row;
     char assignment[5][4];
}seat;

int main (){
     int i, j, k;
     char input[3], assigned='X', again;

     do {
          //Assigning Initial Values
          for(i=0; i<5; i++){                          
               seat.assignment[i][0]='A';
               seat.assignment[i][1]='B';
               seat.assignment[i][2]='C';
               seat.assignment[i][3]='D';
          }
          //Array Output
          for (k=0; k<=20; k++){      
     
               //Array Printing               
               for(i=0; i<5; i++){
                    printf("%d\t", i+1);
                    for(j=0; j<4; j++){
                         printf("%c\t", seat.assignment[i][j]);
                         if (j==3)
                              printf("\n");
                    }
               } 

               //Input-again prompt     
               if(k>0){
                    printf("\nWould you like to assign another seat? (Enter 'Y' to continue, or press any key to end)");
                    again=getch();
               }

               //Limiter for all seats
               if (k != 20){                                                                                            
                    do{                                                         
                         seat.repeat=0;

                         //Input Prompt
                         printf("\nWhat seat would like to have? (%d seat/s remaining) ", 20-k);                        
                         scanf("%s", input);

                         //Character-Integer Converter
                         seat.col=(input[0]-'0')-1;                                                                               
                         if (input[1]=='A'||input[1]=='B'||input[1]=='C'||input[1]=='D'||input[1]=='a'||input[1]=='b'||input[1]=='c'||input[1]=='d'){
                              if (input[1]=='A'||input[1]=='B'||input[1]=='C'||input[1]=='D')
                                   seat.row=(input[1]-'@')-1;
                              else if (input[1]=='a'||input[1]=='b'||input[1]=='c'||input[1]=='d')
                                   seat.row=(input[1]-'`')-1;
                         }
                         else {
                              printf("\nINVALID INPUT, please try again");
                              seat.repeat=1;
                         }

                         //Invalid Input Checker
                         if ((seat.col<0 || seat.col>4)||(seat.row<0 || seat.row>3)){                                                       
                              printf("\nINVALID INPUT, please try again");
                              seat.repeat=1;
                         }
                         
                         //Repeated Input Checker
                         if (seat.assignment[seat.col][seat.row]=='X'){                                                           
                              printf("\nSorry, the seat you have requested has already been assigned to someone else.");   
                              seat.repeat=1;
                         }
                         
                    } while(seat.repeat==1);

                    //Seat Assigner
                    seat.assignment[seat.col][seat.row]=assigned;                                                       

                    system("cls");
                    continue;
               }

               //End Message
               else 
                    printf("\n\nThere are now no available seats left in this airplane");
          }
     } while(again=='Y'||again=='y');
     printf("\n\nThank you for using the Program :^D");
}