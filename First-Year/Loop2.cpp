/*TWELVE DAYS
Almadrones, Charles Cedric
Felipe, Reiniel
Furagganan, Rein Andre*/
#include <stdio.h>

int main(void) {
	//Variable Declaration
	int days, input, gifts, total_gifts=0;
	char restart;

	printf("-----------------<< 12 DAYS OF CHRISTMAS >>----------------\n\n");
	
	//do-while loop - Restart Sequence
	do {
		//do-while loop - Invalid Input Restart Sequence
		do{
			//Input Sequence
			printf("Please enter the preferred number of days in Christmas: ");
			scanf("%d", &input);
			gifts=0;
			total_gifts=0;
			if (input > 0 && input <= 12 ){
				printf("___________________________________________________________\n");
				printf("|      DAYS      |      GIFTS      |      TOTAL GIFTS     |\n");
					
				//For loop - Calculation Sequence
				for (days=1; days <= input; days++){
					gifts += days;
					total_gifts += gifts;
					printf("|\t%02d\t |\t %02d\t   |\t     = %03d\t  |\n", days, gifts, total_gifts);
				}
				//Output Sequence
				printf("-----------------------------------------------------------\n");
				printf("| The total of gift/s on day %d: %d \n", input, total_gifts);
				printf("-----------------------------------------------------------\n");
			}
			//Invalid Input Restart prompts
			else if(input<0){
				printf("\n~~ You have entered a negative integer, Try again and\n");
			}
			else {
				printf("\n~~ You have entered a number more than 12, Try again and\n");
			}
		} while (input < 0 || input > 12);
		
		//Restart Sequence prompt
		printf("\nEnter Y if you wish to restart the program,\nor enter any other key to stop: ");
		scanf("%s", &restart);
		printf("\n===========================================================\n");
	} while(restart=='Y'||restart=='y');
	
	//End-program Output
	printf("Thank you for using the program!  :^)");
	return 0;
}
