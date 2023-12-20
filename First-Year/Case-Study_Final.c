//CASE STUDY FINALS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

//Structure order for menu information
struct order {
     char code[10];
     char desc[20];
     float price;
     int qty;
     float amount;
};
//Structure customer for customer information
struct customer {
     float t_bill;
     float discount;
     float n_bill;
     float amount_t;
     float change; 
     int table;
     char date [9];
     struct order order[100];
};
//Assigned Structures for menu information
struct order p_rice = {"PR001", "Plain Rice", 20.00, 0, 0.00};
struct order r_coke = {"RC002", "Regular Coke", 35.00, 0, 0.00};
struct order b_steak = {"BS003", "Burger Steak", 60.00, 0, 0.00};
struct order c_hotdog = {"CH004", "Classic Hotdog", 85.00, 0, 0.00};
struct order pack_1 = {"P1101", "Package 1", 120.00, 0, 0.00};
struct order pack_2 = {"P2102", "Package 2", 135.00, 0, 0.00};
struct order pack_3 = {"P3103", "Package 3", 150.00, 0, 0.00};
struct order group_1 = {"GFM201", "Family Meal", 550.00, 0, 0.00};
struct order group_2 = {"GBK202", "Barkada Meal", 350.00, 0, 0.00};
struct order group_3 = {"GFS203", "Fiesta Meal", 1125.00, 0, 0.00};

//Function BILLING for computaton
void BILLING(struct customer *cust, int a, int b){
    for(int i=0; i<a; i++){
          for(int j=0; j<b; j++){
               cust[i].order[j].amount = cust[i].order[j].price * cust[i].order[j].qty;
               cust[i].t_bill += cust[i].order[j].amount;
          }
          if(cust[i].t_bill>=0 && cust[i].t_bill<=1000.00)
               cust[i].discount = cust[i].t_bill * 0.02;
          else if(cust[i].t_bill>=1001.00 && cust[i].t_bill<=2000.00)
               cust[i].discount = cust[i].t_bill * 0.03;
          else 
               cust[i].discount = cust[i].t_bill * 0.05;
          
          cust[i].n_bill = cust[i].t_bill - cust[i].discount;
          cust[i].change = cust[i].amount_t - cust[i].n_bill;
     }
     return;
}
//Function main
int main (){
     struct customer customer[100];
     int x=0, y=0, invalid, option;
     char repeat_order, repeat_cust;
     //do-while for repitition of customer input
     do{  
          system("cls");
          repeat_cust=0;
          printf("BSIT ONE1 - G11 RESTAURANT CASHIER\n\n");
          printf("Date (MM/DD/YY): "); gets(customer[x].date);
          printf("Table Number: "); scanf("%d", &customer[x].table); getchar();
          //do-while for repitition of order input
          do{
               repeat_order=0;
               //do-while for repitition if INVALID INPUT
               do{
                    system("cls");
                    printf("For Table #%d\n\n", customer[x].table);
                    invalid=0;
                    //Menu Printing
                    printf("BSIT ONE1 - G11 RESTAURANT MENU\n\n");
                    printf(":: Single Serving Options\n");
                    printf("[1] Plain Rice\n[2] Regular Coke\n[3] Burger Steak\n[4] Classic Hotdog\n");
                    printf(":: Packaged Serving Options\n");
                    printf("[5] Package 1\n[6] Package 2\n[7] Package 3\n");
                    printf(":: Group Serving Options\n");
                    printf("[8] Family Meal\n[9] Barkada Meal\n[0] Fiesta Meal\n");
                    //Switch-Case for Order Entry Input
                    option = getch()-'0';
                    printf("\nChosen Order Entry: ");
                    switch (option){
                    case 1:
                         customer[x].order[y]=p_rice;
                         printf("Plain Rice\n");
                         break;
                    case 2:
                         customer[x].order[y]=r_coke;
                         printf("Regular Coke\n");
                         break;
                    case 3:
                         customer[x].order[y]=b_steak;
                         printf("Burger Steak\n");
                         break;
                    case 4:
                         customer[x].order[y]=c_hotdog;
                         printf("Classic Hotdog\n");
                         break;
                    case 5:
                         customer[x].order[y]=pack_1;
                         printf("Package 1\n");
                         break;
                    case 6:
                         customer[x].order[y]=pack_2;
                         printf("Package 2\n");
                         break;
                    case 7:
                         customer[x].order[y]=pack_3;
                         printf("Package 3\n");
                         break;
                    case 8:
                         customer[x].order[y]=group_1;
                         printf("Family Meal\n");
                         break;
                    case 9:
                         customer[x].order[y]=group_2;
                         printf("Barkada Meal\n");
                         break;
                    case 0:
                         customer[x].order[y]=group_3;
                         printf("Fiesta Meal\n");
                         break;
                    default:
                         printf("INVALID INPUT");
                         getchar();
                         invalid=1;
                         break;
                    }
               }while(invalid==1);

               printf("Quantity: ");
               scanf("%d", &customer[x].order[y].qty); getchar();

               ++y;
               printf("\nEnter another ORDER?\n");
               printf("(Press 'Y' if yes, or press any other key to end or cater more customers)\n\n");
               repeat_order = getch();
          }while(repeat_order=='Y'||repeat_order=='y');

          printf("Paid Amount: ");
          scanf("%f", &customer[x].amount_t); getchar();

          ++x;
          printf("\nBill more CUSTOMER?\n");
          printf("(Press 'Y' if yes, or press any other key to end)\n\n");
          repeat_cust = getch();
     }while(repeat_cust=='Y'||repeat_cust=='y');

     //Calling Function for computation of inputs
     BILLING(customer, x, y);
     //Printing of Results
     system("cls");
     printf("%55s\n", "BSIT ONE1 - G11 RESTAURANT");
     printf("%52s\n\n", "PUP Sta.Mesa, Manila");
     for(int i=0; i<x; i++){
          printf("%51s\n", "BILLING STATEMENT");
          printf("DATE: %s\n", customer[i].date);
          printf("TABLE NO. %d\n\n", customer[i].table);
          printf("%9s%25s%12s%19s%15s\n", "ITEM CODE", "ITEM DESCRIPTION", "QTY", "UNIT PRICE", "AMOUNT");
          for(int j=0; j<y; j++){
               if(customer[i].order[j].qty==0)
                    continue;
               else
                    printf("%9s%25s%12d%19.2f%15.2f\n", customer[i].order[j].code, customer[i].order[j].desc, customer[i].order[j].qty, customer[i].order[j].price, customer[i].order[j].amount);
          }
          printf("\n%65s%15.2f\n", "TOTAL BILL:", customer[i].t_bill);
          printf("%65s%15.2f\n", "DISCOUNT:", customer[i].discount);
          printf("%65s%15.2f\n\n", "NET BILL:", customer[i].n_bill);
          printf("%65s%15.2f\n\n", "AMOUNT TENDERED:", customer[i].amount_t);
          printf("%65s%15.2f\n", "CHANGE:", customer[i].change);
          printf("--------------------------------------------------------------------------------\n");
     }
     return 0;
}
