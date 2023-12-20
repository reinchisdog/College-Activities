#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>

//Struct-Declaration: Customer with variable cust[100]
struct Customer {
	char CustomerName[30], Cust_Address[30];
	float bill;
	//Struct-Declaration: Product with variable prod[100]
     struct Product {
		char Prod_code[8], Prod_desc[100];
		float up;
		int qty;
	} prod[100];
} cust[100];

//Function: RECORD for accepting input
void RECORD(struct Customer *c, int *a){
	int i, repeat, legible, temp;
     //do-while for repetition of input
	do{  
		repeat=0;		
          //do-while for 3 Product per week Limit
          do{
               temp=1, legible=0;
               system("cls");
               printf("Customer Name: "); gets(c[*a].CustomerName);
               for(i=0; i<*a; i++){
                    temp=strcmpi(c[*a].CustomerName, c[i].CustomerName);
                    if(temp==0){
                         printf("EXCEEDED WEEKLY PRODUCT LIMIT");
                         Sleep(2500);
                         legible=1;
                         break;
                    }
                    else
                         continue;
               }
          }while(legible==1);

		printf("Customer Address: "); gets(c[*a].Cust_Address);
		for(i=0; i<100; i++){
			printf("\tProduct Code: "); gets(c[*a].prod[i].Prod_code);
			printf("\tProduct Description: "); gets(c[*a].prod[i].Prod_desc); 
			printf("\tUnit Price: P"); scanf("%f", &c[*a].prod[i].up);
			printf("\tNumber Quantity: "); scanf("%d", &c[*a].prod[i].qty);
			getchar();
			printf("\n");
               if(i==2) break;
		}

		++*a;
		printf("Enter 'Y' to add more Customer Information, or press any other key to print all information");
		repeat=getch();
	} while(repeat=='Y'||repeat=='y');

	return;
}

//Function: KOMPUTE for computing bill
void KOMPUTE(struct Customer *c, int *a){
     int i, j;
     for (i=0; i<*a; i++){
          for(j=0; j<3; j++){
               c[i].bill+=(c[i].prod[j].qty*c[i].prod[j].up);
          }
     }
     return;
}

//Function: main
int main(){
     struct Customer cust[100];
	int x=0, i, j;
	RECORD(cust, &x);
     KOMPUTE(cust, &x);
     system("cls");
     //Printing Output
     for(i=0; i<x; i++){
          printf("Receipt for Customer: %s\n", cust[i].CustomerName);
          printf("Customer Address: %s\n", cust[i].Cust_Address);
          printf("\n%-15s %-40s %-15s %-8s\n", "Product Code", "Product Description", "Unit Price", "Quantity");
          for(j=0; j<3; j++){
               printf("%-15s %-40s %-15.2f %-8d\n", cust[i].prod[j].Prod_code, cust[i].prod[j].Prod_desc, cust[i].prod[j].up, cust[i].prod[j].qty);
          }
          printf("\t\t\t\t\t\t\tTotal billing: Php. %0.2f\n\n", cust[i].bill);
     }
     return 0;
}
