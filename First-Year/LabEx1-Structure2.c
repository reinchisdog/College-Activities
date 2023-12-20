/* Library Information System
title of the book, author/s, borrower name, borrowed days.
- one borrower, one book policy
- max of 3 days borrowing, fine for 5php/day if exceeded*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

struct library {                                                                          //Structure Declaration
     char borrower[100], title[100], author[100];
     int days, fine, policy;
} book[100];

int main(){
     char repeat;
     int i=0, j, k;

     do{                                                                                  //do-while loop: repeat
          system("cls");                                                                       //input prompt of Library Information System
          printf(":::::::::::: LIBRARY INFORMATION SYSTEM ::::::::::::\n\n");
          printf("Registered Student Name: ");
          gets(book[i].borrower);
          printf("Title of the Book: ");
          gets(book[i].title);
          printf("Author/s of the Book: ");
          gets(book[i].author);
          printf("Days of Borrowing: ");
          scanf(" %d", &book[i].days);
          fflush(stdin);

          if(book[i].days>3)                                                                   //computation: fine
               book[i].fine=(book[i].days-3)*5;

          printf("\n\nInput another library entry?\n(Enter 'Y' to continue, or enter any key to end)");
          repeat = getch();
          i++;
     } while(repeat == 'y' || repeat == 'Y');

     system("cls");
     for(j=0; j<i; j++){                
          book[j].policy=0;                                                  //value assignment for array that checks if borrower is repeated
          for(k=0; k<j; k++){
               if(strcmp(book[j].borrower,book[k].borrower) == 0){
                    book[j].policy=1;
                    break;
               }
               else{
                    continue;
               }
          }
     }
     printf(":::::::::::: LIBRARY INFORMATION SYSTEM ::::::::::::\n\n");
     for(j=0; j<i; j++){                                                                  //Printing of Library Information System
          if(book[j].policy==1){
               printf("\n------------------- Borrower #%d -------------------\n", j+1);
               printf("\nBORROWER HAS ALREADY BORROWED A BOOK\n");
          }
          else {
               printf("\n------------------- Borrower #%d -------------------\n\n", j+1);
               printf("Student Name: %s\n", book[j].borrower);
               printf("Book Title: %s\n", book[j].title);
               printf("Book Author/s: %s\n", book[j].author);
               printf("Borrowing Days: %d\n", book[j].days);
               printf("Overdue Fine: P%d.00\n\n", book[j].fine);
          }
     }
}

