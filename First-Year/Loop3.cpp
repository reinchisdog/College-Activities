/*ACTIVITY 2A and 2B
Almadrones, Charles Cedric
Felipe, Reiniel
Furagganan, Rein Andre*/
#include <stdio.h>

int main (void){
	//Variable Declaration
    int n, number, factor, checker=1;
    char restart;

    printf("------<< FACTORS and PRIME FACTORS >>------\n");
    
    //Do-while for restarting the program
    do{
        //Do-while for negative integer input
        do{
        	printf("\nPlease Enter Positive Integer: ");
        	scanf("%d", &number);
            
        	//If-else statement for checking if it is a positive or negative integer
            if (number > 0){
            	printf("-------------------------------------------\n");
            	printf("_______________________________");
                printf("\n|  FACTORS  |  PRIME FACTORS  |", number);
                //while loop for checking the factors and prime factors
                while (n < number){
                    n++;
                    //If-else statement for getting the factors
                    if (number % n == 0){
                        printf("\n   %d ", n);

                        //Prime factor checking
                        checker = 1;
                        for (factor = 2; factor < n; factor++){
                            if(n % factor == 0){
                                checker=0;
                                break;
                            }
                        }
                        if (checker == 1)
                            printf("\t       %d",n);
                    }
                }
            }
            else
                printf("\nYou've entered Negative Integer!\n\n");
        } while (number < 0);
        
        //Restart Prompt
        printf("\n\n-------------------------------------------\n");
        printf("Do you want to restart the Program (Y/N)?: ");
        scanf("%s", &restart); n=0, number=0, checker=1;
        printf("-------------------------------------------\n");
    } while (restart == 'Y' || restart == 'y');
    
    return 0;
}
