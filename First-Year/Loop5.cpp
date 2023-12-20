//EXERCISE A 
/*Members:
- Almadrones, Charles Cedric
- Felipe, Reiniel
- Furagganan, Rein Andre
*/
#include <stdio.h>

int main(void){
	//Variable Declaration
	int number, checker=1, factor;
	char restart;
	
	printf("|--------------------< EXERCISE A - Prime Number Identifier >--------------------|\n");
	
	//do-while for Restart Sequence
	do{
		//do-while for Negative Validation
		do{
			//Input Sequence
				printf("\nPlease enter the desired number to check if it is prime: ");
				scanf("%d", &number);
			if (number>0){
			
				//Calculation Sequence // Checks if input has factors
		    	for (factor = 2; factor < number; factor++){
			    	if(number % factor == 0){
			        checker=0;
			        break;
	    		}}	
	    		//Output Sequences     
	   			if (checker == 1)
	        	printf("Your input [%d] is a PRIME NUMBER", number);
	   	 		else 
	        	printf("Your input [%d] is NOT a PRIME NUMBER", number);
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

