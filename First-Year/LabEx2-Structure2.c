// Laboratory Exercise 2 - Part 2

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

//Structure Declaration: Parking Info
struct ParkingInfo {
     int type;
     char model[100], color[100], plate[100];
     //Structure Declaration: Customer Info
     struct Customer {
          char name[100], address[100];
     } cust;
     //Structure Declaration: Time Info
     struct Time {
          int in, out, hours, fee;
     }time;
} info[100];

//Structure Declaration: Limiter
struct Limit {
     int x;
} limit;

//Function Declaration: KOMPUTE (includes computation for vehicle type, hours, and fee)
void KOMPUTE(struct ParkingInfo *i){
     for(int y=0; y <= limit.x; y++){
          if (i[y].type==1){
               i[y].type=25;
          }
          else if (i[y].type==2){
               i[y].type=50;
          }
          else if (i[y].type==3){
               i[y].type=75;
          }

          i[y].time.in = ((i[y].time.in/100)*60) + (i[y].time.in - ((i[y].time.in/100)*100));
          i[y].time.out = ((i[y].time.out/100)*60) + (i[y].time.out - ((i[y].time.out/100)*100));
          if(i[y].time.in>i[y].time.out){
               i[y].time.hours = (i[y].time.out + 1440 - i[y].time.in)/60; 
          }
          else{
               i[y].time.hours = (i[y].time.out - i[y].time.in)/60;
          }
          i[y].time.fee = i[y].time.hours*i[y].type;
     }
     return;
}

//Main Function
int main(){
     int repeat, again, temp[100];
     limit.x=0;
     //do-while statement: to repeat all questions 
      do{
          //Input Prompt
          printf("CUSTOMER VEHICLE INFORMATION\n");
          printf("Customer Name: "); gets(info[limit.x].cust.name);
          printf("Customer Address: "); gets(info[limit.x].cust.address);
          do{ //do-while statement: for appropriate input
               again=0;
               printf("Vehicle Type: [1] Car | [2] Bus | [3] Truck\n"); info[limit.x].type = getch()-'0';
               if(info[limit.x].type!=1&&info[limit.x].type!=2&&info[limit.x].type!=3){
                    printf("::INVALID INPUT, please try again\n\n");
                    Sleep(2000);
                    again=1;
               }
          } while(again==1);
          printf("Make and Model: "); gets(info[limit.x].model);
          printf("Vehicle Color: "); gets(info[limit.x].color);
          printf("Plate Number: "); gets(info[limit.x].plate);
          printf("\nPARKING HOURS\n");
          printf("Kindly enter in this format - HHMM\n");
          do{ //do-while statement: for appropriate input
               again=0;
               printf("Time-in: "); scanf("%d", &info[limit.x].time.in);
               temp[limit.x]=(info[limit.x].time.in - ((info[limit.x].time.in/100)*100));
               if(info[limit.x].time.in < 0000 || info[limit.x].time.in > 2400 || temp[limit.x] < 00 || temp[limit.x] > 59){
                    printf("::INVALID INPUT, please try again\n\n");
                    Sleep(2000);
                    again=1;
               }
          } while(again==1);
          do{ //do-while statement: for appropriate input
               again=0;
               printf("Time-out: "); scanf("%d", &info[limit.x].time.out); getchar();
                temp[limit.x]=(info[limit.x].time.out - ((info[limit.x].time.out/100)*100));
               if(info[limit.x].time.out < 0000 || info[limit.x].time.out > 2400 || temp[limit.x] < 00 || temp[limit.x] > 59){
                    printf("::INVALID INPUT, please try again\n\n");
                    Sleep(2000);
                    again=1;
               }
          } while(again==1);

          printf("\n\n::Input another parking information entry?\n(Enter 'Y' to continue, or press any key to end)");
          repeat=getch();
          limit.x++;
          system("cls");
      } while(repeat=='Y'||repeat=='y');

     //Calling function KOMPUTE
     KOMPUTE(info);
     
     //Output Prompt
     for (int y=0; y < limit.x; y++){
          printf("-------------- Customer #%d --------------\n", y+1);
          printf("Customer Name: %s\n", info[y].cust.name);
          printf("Address: %s\n", info[y].cust.address);
          if (info[y].type==25)
               printf("Vehicle Type: Car\n");
          else if (info[y].type==50)
               printf("Vehicle Type: Bus\n");
          else if (info[y].type==75)
               printf("Vehicle Type: Truck\n");
          printf("Make & Model: %s\n", info[y].model);
          printf("Vehicle Color: %s\n", info[y].color);
          printf("Plate Number: %s\n", info[y].plate);
          printf("Parked Hours: %d Hours\n", info[y].time.hours);
          printf("Parking Fee: P%d.00\n\n", info[y].time.fee);
     }

     printf("------------------ END ------------------\n");
     return 0;
}