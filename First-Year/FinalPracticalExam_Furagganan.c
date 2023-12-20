/* Final Practical Examination
     REIN ANDRE D. FURAGGANAN
     BSIT 1-1
     July 29, 2023             */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int x=0; 

//Structure Declaration
struct Book{
	int bookNo;
	char book_title[100];
	char book_author[100];
	int book_qty;
}list[100];

//Function Declaration
void MENU();
void RECORD();
void CHANGE();
void DISPLAY();

//Main Function
int main() {
    //Reads Current Existing Records
    FILE* fp = fopen("BookReceipt.txt", "r");
    while (fscanf(fp, "Book Number  %d \nBook Title   %[^\n] \nAuthor/s     %[^\n] \nQuantity     %d \n",
                  &list[x].bookNo, list[x].book_title, list[x].book_author, &list[x].book_qty) == 4) {
        ++x;
    }
    fclose(fp);
    //function MENU access
    MENU();
    //Ending Program
    printf("\n > Ending Program... Thank you");
    Sleep(3000);
    return 0;
}

//MENU function - user choice prompt
void MENU(){
	int invalid;
	do{
		int choice;
		invalid=0;
		system("cls");	
		printf("        ABC Library Inventory Manager       \n\n");
		printf("           [1] Enter New Record             \n"); 
		printf("           [2] Change Quantity              \n");
		printf("           [3] Display the Record           \n\n");
		printf("           [4] Exit Program                 \n");
		
          //switch-case for Choices - function access prompt
		choice = getch()-'0';
		switch(choice){
			case 1:
				RECORD();
				break;
			case 2:
				CHANGE();
				break;
			case 3:
				DISPLAY();
				break;
			case 4:
				return;
				break;
			default:
				printf("\n > Invalid Input: Please Try Again...");
				Sleep(1500);
				invalid=1;
		}
	} while(invalid==1);
}

//RECORD function - new record prompt
void RECORD(){
	int invalid;
	char repeat;
	do{
		system("cls");
		printf("        ABC Library Inventory Manager       \n");
		printf("             Enter a New Record             \n\n");

		//Input Prompts
		do{		//do-while - Take Book No.
			invalid = 0;
			list[x].bookNo = 0;
			printf("  Book Number  : "); scanf("%d", &list[x].bookNo); getchar();
			for (int i = 0; i < x; i++) {
				if (list[x].bookNo == list[i].bookNo) {
				printf("> Number already taken. Please try again.\n");
				invalid = 1;
				break;
		        	}
		    	}
		} while (invalid == 1);
		
		printf("  Book Title   : "); gets(list[x].book_title);
          printf("  (Separate Multiple Authors using ,)\n");
          printf("  Book Author/s: "); gets(list[x].book_author);
          printf("  Desired Qty. : "); scanf("%d", &list[x].book_qty);
	
          //Repeat Prompt
		++x;
		printf("\n\n> Enter 'Y' to enter a new record.\nOtherwise, press any other key to return to the MENU");
		repeat=getch();
	} while(repeat=='Y'||repeat=='y');

     //File Access for File printing
	FILE* fp;
	fp = fopen("BookReceipt.txt", "w");
	for(int i=0; i<x; i++){
		fprintf(fp,"Book Number  %d \n", list[i].bookNo);
		fprintf(fp,"Book Title   %s \n", list[i].book_title);
		fprintf(fp,"Author/s     %s \n", list[i].book_author);
		fprintf(fp,"Quantity     %d \n\n", list[i].book_qty);
	}
	fclose(fp);
	MENU();
}

//CHANGE function - quantity change prompt
void CHANGE(){
	int bookIN, exist=0, temp;
	system("cls");
	printf("        ABC Library Inventory Manager       \n");
	printf("            Change Book Quantity            \n\n");

     //Input Prompt - for Book Number
	printf("  Book Number : "); scanf("%d", &bookIN);

	//Input Availability Checker
	for(int i=0; i<=x; i++){	
		if(bookIN==list[i].bookNo){
			exist=1;
			temp=i;
			break;
		}
		else{
			exist=0;
			continue;
		}
	}

     //Available Output
	if (exist==1){
		printf("  Book No.%03d %s\n", list[temp].bookNo, list[temp].book_title);
		printf("  by %s\n", list[temp].book_author);
          printf("  Current Qty  : %d\n", list[temp].book_qty);
		printf("  Desired Qty  : "); scanf("%d", &list[temp].book_qty);
	}
     //Unavailable Ouput: Returns to Menu
	else {
		printf("\n > Book no. %d is not Available:\n  Please Try Again\n", bookIN);
		Sleep(1500);
	}

     //File Access for File printing
	FILE* fp;
	fp = fopen("BookReceipt.txt", "w");
	for(int i=0; i<x; i++){
		fprintf(fp,"Book Number  %d\n", list[i].bookNo);
		fprintf(fp,"Book Title   %s\n", list[i].book_title);
		fprintf(fp,"Author/s     %s\n", list[i].book_author);
		fprintf(fp,"Quantity     %d\n\n", list[i].book_qty);
	}
	fclose(fp);
	MENU();
}

//DISPLAY function - file output 
void DISPLAY(){
	char repeat;

	//PROGRAM output
	system("cls");
	printf("        ABC Library Inventory Manager       \n");
	printf("               Display Record               \n");
	printf("    > Enter 'Y' to return to the MENU       \n\n");
	for(int i=0; i<x; i++){
		printf("         Book Number : %d\n", list[i].bookNo);
		printf("         Book Title  : %s\n", list[i].book_title);
		printf("         Author/s    : %s\n", list[i].book_author);
		printf("         Book Qty.   : %d\n\n", list[i].book_qty);
	}

     //Exit Prompt
	repeat=getch();
	if(repeat=='Y'||repeat=='y'){
		MENU();
	}
}

