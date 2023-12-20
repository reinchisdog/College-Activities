//LABORATORY EXERCISE 3 - Part 1
// BSIT 1-1: Almadrones, Felipe, Furagganan
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
 
int x=0;

//Structure Declaration
struct shoe{
    int Nstock;
    int style_num;
    int Size;
    float Nprice;
}list[100];;

void RECORD();
void CHANGE();
void DISPLAY();
void MENU();

//Main Function
int main(){
	//FILE access to keep track of existing records
	FILE* fp;
	fp=fopen("ShoeReceipt.txt", "r");
	while(fscanf(fp, "Stock Number %d \nStyle Number %d \nShoe Size %d \nShoe Price %f\n", &list[x].Nstock, &list[x].style_num, &list[x].Size, &list[x].Nprice)==4){
		++x;
	};
	fclose(fp);
	//function MENU access
	MENU();
	printf("\n > Ending Program... Thank you");
	Sleep(3000);
    return 0;
}

//RECORD function - new record prompt
void RECORD(){
	int invalid;
	char repeat;
	do{
		system("cls");
		printf("____________________________________________\n");
		printf("|-------Shoe Store Inventory Manager-------|\n");
		printf("|____________Enter a New Record____________|\n\n");
		
		do{		//do-while - Taken Stock No.
			invalid = 0;
			list[x].Nstock = 0;
			printf("  Stock Number : "); scanf("%d", &list[x].Nstock);
			for (int i = 0; i < x; i++) {
				if (list[x].Nstock == list[i].Nstock) {
				printf("> Stock already taken. Please try again.\n");
				invalid = 1;
				break;
		        	}
		    	}
		} while (invalid == 1);
		
		do{		//do-while - Invalid Style
			invalid=0;
			printf("  Style Number : "); scanf("%d", &list[x].style_num);	
			if(list[x].style_num<0||list[x].style_num>50){
				printf("> Style no. Not Available: Please Try Again\n");
				invalid=1;
			}
		}while(invalid==1);
		
		do{		//do-while - Invalid Size No.
			invalid=0;
			printf("  Shoe Size    : "); scanf("%d", &list[x].Size);
			if(list[x].Size<3||list[x].Size>14){
				printf("> Shoe S. Not Available: Please Try Again\n");
				invalid=1;
			}
		}while(invalid==1);
		
		printf("  Desired Price: PHP"); scanf("%f", &list[x].Nprice);
	
		++x;
		printf("\n\n> Enter 'Y' to enter a new record.\nOtherwise, press any other key to return to the MENU");
		repeat=getch();
	} while(repeat=='Y'||repeat=='y');
	FILE* fp;
	fp = fopen("ShoeReceipt.txt", "w");
	for(int i=0; i<x; i++){
		fprintf(fp,"Stock Number %d\n", list[i].Nstock);
		fprintf(fp,"Style Number %d\n", list[i].style_num);
		fprintf(fp,"Shoe Size    %d\n", list[i].Size);
		fprintf(fp,"Shoe Price   %0.2f\n\n", list[i].Nprice);
	}
	fclose(fp);
	MENU();
}

//CHANGE function - price change prompt
void CHANGE(){
	int stockIN, exist=0, temp;
	system("cls");
	printf("____________________________________________\n");
	printf("|-------Shoe Store Inventory Manager-------|\n");
	printf("|______________Change a Price______________|\n\n");
	printf("  Stock Number : "); scanf("%d", &stockIN);
	//Availability Checker
	for(int i=0; i<=x; i++){	
		if(stockIN==list[i].Nstock){
			exist=1;
			temp=i;
			break;
		}
		else{
			exist=0;
			continue;
		}
	}
	if (exist==1){
		printf("  Style No.%02d   Shoe Size %d\n", list[temp].style_num, list[temp].Size);
		printf("  Current Price: P%0.2f\n", list[temp].Nprice);
		printf("  New Price    : P"); scanf("%f", &list[temp].Nprice);
	}
	else {
		printf("\n > Stock no.%d is not Available:\n  Please Try Again\n", stockIN);
		Sleep(1500);
	}
	FILE* fp;
	fp=fopen("ShoeReceipt.txt", "w");
	for(int i=0; i<x; i++){
		fprintf(fp,"Stock Number %d\n", list[i].Nstock);
		fprintf(fp,"Style Number %d\n", list[i].style_num);
		fprintf(fp,"Shoe Size    %d\n", list[i].Size);
		fprintf(fp,"Shoe Price   %0.2f\n\n", list[i].Nprice);
	}
	fclose(fp);
	MENU();
}

//DISPLAY function - file output 
void DISPLAY(){
	char repeat;
	//PROGRAM output
	system("cls");
	printf("____________________________________________\n");
	printf("|-------Shoe Store Inventory Manager-------|\n");
	printf("|______________Display Record______________|\n");
	printf("    > Enter 'Y' to return to the MENU       \n\n");
	for(int i=0; i<x; i++){
		printf("         Stock Number: %d\n", list[i].Nstock);
		printf("         Style Number: %d\n", list[i].style_num);
		printf("         Shoe Size   : %d\n", list[i].Size);
		printf("         Shoe Price  : P%0.2f\n\n", list[i].Nprice);
	}
	repeat=getch();
	if(repeat=='Y'||repeat=='y'){
		MENU();
	}
}

//MENU function - user choice prompt
void MENU(){
	int invalid;
	do{
		int choice;
		invalid=0;
		system("cls");	
		printf("____________________________________________\n");
		printf("|-------Shoe Store Inventory Manager-------|\n");
		printf("|__________________________________________|\n\n");
		printf("          [1] Enter New Record              \n"); 
		printf("          [2] Change a Price                \n");
		printf("          [3] Display the Record            \n\n");
		printf("          [4] Exit Program                \n");
		
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



