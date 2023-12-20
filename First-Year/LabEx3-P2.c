//LABORATORY EXERCISE 3 - Part 2
// BSIT 1-1: Almadrones, Felipe, Furagganan
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int x=0;

//Structure Declaration
struct video{
	int VideoNo;
	char VD_Type[20];
	char VD_Class[20];
	char VD_Title[50];
	float Rprice;
}list[100];

void MENU();
void RECORD();
void DISPLAY();

//Main Function
int main(){
	//FILE access to keep track of existing records
	FILE* fp;
	fp = fopen("VideoReceipt.txt", "r");
	while(fscanf(fp, "V-No %d %s \nVideo Type   %s \nVideo Class  %s \nRetail Price %f\n", &list[x].VideoNo, list[x].VD_Title, list[x].VD_Type, list[x].VD_Class, &list[x].Rprice)==5){
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
	int invalid, temp;
	char repeat;
	char baseType[2][20]={"foreign", "local"};
	char baseClass[4][20]={"drama", "action", "comedy", "suspense"};

	do{
		system("cls");
		printf("____________________________________________\n");
		printf("|----ABC Video Rental Inventory Manager----|\n");
		printf("|____________Enter a New Record____________|\n\n");
		do{		//do-while - Invalid Number
			invalid = 0;
			list[x].VideoNo = 0;
			printf("  Video Number: "); scanf("%d", &list[x].VideoNo); getchar();
			for (int i = 0; i < x; i++) {
				if (list[x].VideoNo == list[i].VideoNo) {
				printf("> Vid No. already taken. Please try again.\n");
				invalid = 1;
				break;
		        	}
		    	}
		} while(invalid == 1);

		do{		//do-while - Invalid Type
			invalid = 0;
			temp = 0;
			printf("  Video Type  : "); gets(list[x].VD_Type); strlwr(list[x].VD_Type);
			for (int i=0; i<2; i++){
				if(strcmp(list[x].VD_Type, baseType[i])==0){
					temp = 1;
					break;
				}
			}
			if (temp == 0){
				printf("> Unavailable Video Type: Please Try Again\n");
				invalid=1;
			}
		} while(invalid == 1);
		
		do{		//do-while - Invalid Class
			invalid = 0;
			temp = 0;
			printf("  Video Class : "); gets(list[x].VD_Class); strlwr(list[x].VD_Class);
			for (int i=0; i<4; i++){
				if(strcmp(list[x].VD_Class, baseClass[i])==0){
					temp = 1;
					break;
				}
			}
			if (temp == 0){
				printf("> Unavailable Video Class: Please Try Again\n");
				invalid=1;
			}
		} while(invalid == 1);

		printf("  Video Title : "); gets(list[x].VD_Title);
		printf("  Rental Price: PHP"); scanf("%f", &list[x].Rprice);

		++x;
		printf("\n\n> Enter 'Y' to enter a new record.\nOtherwise, press any other key to return to the MENU");
		repeat=getch();
	}while(repeat=='Y'||repeat=='y');
	FILE* fp;
	fp = fopen("VideoReceipt.txt", "w");
	for (int i=0; i<x; i++){
		fprintf(fp, "V-No %d %s \n", list[i].VideoNo, list[i].VD_Title);
		fprintf(fp, "Video Type   %s \n", list[i].VD_Type);
		fprintf(fp, "Video Class  %s \n", list[i].VD_Class);
		fprintf(fp, "Retail Price %0.2f \n\n", list[i].Rprice);
	}
	fclose(fp);
	MENU();
}

void DISPLAY(){
	int temp, exist, days, input;
	char repeat;
	//PROGRAM output
	do{
		float Bill;
		system("cls");
		printf("____________________________________________\n");
		printf("|----ABC Video Rental Inventory Manager----|\n");
		printf("|______________Display Record______________|\n\n");
		for(int i=0; i<x; i++){
			printf("         V-No. %d %s \n", list[i].VideoNo, list[i].VD_Title);
			printf("         Video Type  : %s \n", list[i].VD_Type);
			printf("         Video Class : %s \n", list[i].VD_Class);
			printf("         Retail Price: P%0.2f \n\n", list[i].Rprice);
		}
		printf("|___________Billing Information____________|\n\n");
		printf("         Video Number:"); scanf("%d", &input);
		for(int i=0; i<=x; i++){	
			if(input==list[i].VideoNo){
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
			printf("         Title: %s\n", list[temp].VD_Title);
			printf("         %s - %s\n", list[temp].VD_Type, list[temp].VD_Class);
			printf("         Retail Price : P%0.2f\n\n", list[temp].Rprice);
			printf("         Renting Days : "); scanf("%d", &days);
			Bill = list[temp].Rprice + (days-3)*50.00;
			printf("         Total Billing: P%0.2f\n", Bill);

			printf("\n\n> Enter 'Y' to compute more bill.\nOtherwise, press any other key to return to the MENU");
			repeat=getch();
		}
		else {
			printf("\n > Video no.%d is not Available:\n  Please Try Again\n", input);
			Sleep(1500);
		}
	} while(repeat=='Y'||repeat=='y');
	MENU();
}

//MENU function - user choice prompt
void MENU(){
	int invalid;
	do{
		int choice;
		invalid=0;
		system("cls");
		printf("____________________________________________\n");
		printf("|--------ABC Video Retail Shop List--------|\n");
		printf("|__________________________________________|\n\n");
		printf("          [1] Enter New Record              \n"); 
		printf("          [2] Display the Record            \n\n");
		printf("          [3] Exit Program                  \n");
		
		choice = getch()-'0';
		switch(choice){
			case 1:
				RECORD();
				break;
			case 2:
				DISPLAY();
				break;
			case 3:
				return;
				break;
			default:
				printf("\n > Invalid Input: Please Try Again...");
				Sleep(1500);
				invalid=1;
		}
	} while(invalid==1);
}
