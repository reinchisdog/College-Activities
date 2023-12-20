//EXERCISE B
/*Members:
- Almadrones, Charles Cedric
- Felipe, Reiniel
- Furagganan, Rein Andre
*/
#include <stdio.h>

int main(void){
	//Variable Declaration
	int n, number,product;
	char restart;
	
	printf("|--------------------< EXERCISE B - Factorial Calculator >--------------------|\n");
	
	//do-while for Restart Sequence
	do{
		//do-while for Negative Validation
		do{
			//Input Sequence
			printf("\nPlease input a non-negative integer: ");
			scanf("%d", &number);
			//Negative Validation
			if (number>0){
				//Calculation Sequence
				for (n=1;n<=number;n++){
						product *= n;
				}
				//Output Sequence
				printf("Number %d's Factorial is %d", number, product);
				product=1; //to reset the value of product
			}
			else {
				printf("\nYou have entered a negative number, try again and");
			}
		} while (number<0);
		
	//Restart Sequence
	printf("\n\nPress 'y' to calculate more numbers, or enter any key to end the program: ");
	scanf("%s", &restart);
	} while (restart=='y' || restart=='Y');
	
	printf("Thank you for using the program");
	
	return 0;
}

