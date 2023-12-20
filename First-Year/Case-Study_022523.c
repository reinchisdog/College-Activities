/*FINAL CASE STUDY for 1st SEMESTER- Group 11
- Almadrones, Charles Cedric
- Felipe, Reiniel
- Furagganan, Rein Andre*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void CASE1();
void CASE2();
void CASE3();
void MENU();
void KOMPUTE(int N);
int FIBO (int R[], int m);

//Password Function
int main(){
	int i = 0, result=0, attempts=0;
    char input[1000], password[7]="BSIT11", hidden;

    while (attempts < 3){
        system("cls");
        printf(":::::::::::::::::: CASE STUDY LOG-IN ::::::::::::::::::\n\n");
        //Input Prompt
        printf(">> Please enter the correct password: ");

        //Password Hider
        for (i = 0; i < 1000; i++){
            hidden = getch();
            if(hidden == 13)
                break;
            input[i] = hidden;
            hidden = '*';
            printf("%c", hidden);
        }
        input[i] = '\0';
        
        //Password correctness identifier
        result = strcmp(input, password);
        if(result!=0){
            printf("\n\nThe password you entered was incorrect\n");
            Sleep (3000);
            attempts++;
            continue;
        }
        else{
            MENU();
        }
    }
    //Max password limit
    printf("\n:: You Have surpassed the maximum amount of attempts\n   The program will now end in 3 seconds. Thank you");
    Sleep (3000);
    printf("\n");
	
    return 0;
}

//Menu Function
void MENU(){
    int options; 
    system("cls");
    //Input Prompt
    printf(":::::::::::::::::::::: MAIN MENU :::::::::::::::::::::\n\n");
    printf("        >> Please Choose Any Option to perform\n\n");
    printf("        [1] Dwarf\n        [2] Perfect Abundant Deficient\n        [3] Fibonacci\n\n        [4] Quit Program\n");
    printf("        --------------------------------------\n");
    printf("        Enter your choice: ");
    scanf("%d", &options);    
    //Options using Switch-Case
    switch (options) {
        case 1:{
            CASE1();
            break;
        }
        case 2:{
            CASE2();
            break;
        }
        case 3:{
            CASE3();
            break;
        }
        case 4:{
            printf("\n        :: The Program will now end, Thank you!\n\n");
            abort();
        }
        default:{
            printf("\n        Invalid Input. Please try again.\n\n");
            Sleep (2500);
            return MENU();
        }
    }
}

//CASE STUDY #1
void CASE1(){
    int number, a, sum=0;
    float half;
    char restart;
    system("cls");
    do {   
        do {
            printf(":::::::::::::::::::: CASE STUDY #1 :::::::::::::::::::\n\n");
            //Input Prompt
            printf(">> Enter non-negative integer: ");
            scanf("%d", &number);

            //Factor Generator with Sum
            if (number > 0){
                printf("\nIts factor/s is/are: ");
                for (a=1; a<number; a++){
                    if (number % a == 0){
                        printf("%d ", a);
                        sum+=a;
                    }
                }

                //Output Display
                printf("\n\n:: The sum of factors is %d,", sum);
                half = number/2.00;
                printf("\n   while the half of %d is %.2f", number, half);
                if(sum < half)
                    printf("\n   Therefore, the number [%d] is not a DWARF", number);
                else
                    printf("\n   Therefore, the number [%d] is a DWARF", number);
            }
            else {
                printf("\nYou've entered a Negative Integer!\n");
                Sleep (3000);
                system("cls");
            } 

        } while (number < 0);
            printf("\n\n------------------------------------------------------");
            printf("\nDo you wish to restart the program? [Y/N]: ");
            scanf("%s", &restart); number = 0, a = 0, sum=0, half=0;
            system("cls");
    } while (restart == 'Y' || restart == 'y');    
    MENU();
}

//CASE STUDY #2
void CASE2(){
    int number;
    char restart;
    system("cls");
    do
    {
        do
        {   
            printf(":::::::::::::::::::: CASE STUDY #2 :::::::::::::::::::\n\n");
            //Input Prompt
            printf(">> Enter non-negative integer: ");
            scanf("%d", &number);
            if (number > 0)
            {
            KOMPUTE(number);
            }
            else{
                printf("\nYou've entered a Negative Integer!\n");
                Sleep (3000);
                system("cls");
            }
        } while (number < 0);
            printf("\n\n------------------------------------------------------");
            printf("\nDo you wish to restart the program? [Y/N]: ");
            scanf("%s", &restart); number = 0;
            system("cls");
    } while (restart == 'Y' || restart == 'y');

    MENU();
}

//Function for Divisor Generator for function CASE2()
void KOMPUTE(int N){
    int a, sum=0;
    printf("\nIts divisor/s is/are: ");
    for (a=1; a < N; a++)
    {
        if (N % a == 0)
        {
            printf("%d ", a);
            sum+=a;
        }
    }
    printf("\n\n:: The total of the divisors of [%d] is: %d", N, sum);
    if (sum < N)
        printf("\n\n:: Since %d < %d, then, [%d] is DEFICIENT", sum, N, N);
    else if (sum > N)
        printf("\n\n:: Since %d > %d, then, [%d] is ABUNDANT", sum, N, N);
    else 
        printf("\n\n:: Since %d = %d, then, [%d] is PERFECT", sum, N, N);
}

//CASE STUDY #3
void CASE3(){
	int n, RABBIT[1000]={1,0}, months, f_months, years, total_rabbit;
	char restart;
    system("cls");

    do{
        do{
            printf(":::::::::::::::::::: CASE STUDY #3 :::::::::::::::::::\n\n");
            //Input Prompt
            printf(">> Please enter desired month: ");
            scanf("%d", &months);

            //Input for RABBIT array
            for (n = 0; n < months; n++){
                RABBIT[n + 2]= RABBIT[n] + RABBIT[n+1];
            }
            total_rabbit = FIBO(RABBIT, months);

            //Output Display that is divided into 3 statements to divided the display of months and years.
            if (months > 0){
                printf("\nMonths\tNew Pairs of Rabbits");
                for (n = 1; n < months+1; n++){
                    printf("\n%d\t%d", n, RABBIT[n-1]);
                }
                if (months < 12){ //if less than 1 year
                    printf("\n\n:: In %d month/s,\n   there are total of %d rabbits with %d pairs", months, 2*total_rabbit, total_rabbit);
                }
                else{
                    years = months/12;
                    if (months % 12 == 0){ //if only in years
                        printf("\n\n:: In %d year/s,\n   there are total of %d rabbits with %d pairs", years, 2*total_rabbit, total_rabbit);
                    }
                    else{ //if years and months
                        f_months = months - (years * 12);
                        printf("\n\n:: In %d years and %d months,\n   there are total of %d rabbits with %d pairs", years, f_months, 2*total_rabbit, total_rabbit);
                    }
                }
            }
            else{
                printf("\nInvalid input of month!\n");
                Sleep (3000);
                system("cls");
            } 

        } while (months < 0);
            printf("\n\n------------------------------------------------------");
            printf("\nDo you wish to restart the program? [Y/N]: ");
            scanf("%s", &restart);
            system("cls");
    } while (restart == 'Y' || restart == 'y');
    
    MENU();
}

//Function for New Rabbits per month
int FIBO (int R[], int m)
{
    int n, total_rabbit=0;

    for (n=0; n < m; n++)
    {
        total_rabbit += R[n];
    }
    return total_rabbit;
}
