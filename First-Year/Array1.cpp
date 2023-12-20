/*ACTIVITY 1
Almadrones, Charles Cedric
Felipe, Reiniel
Furagganan, Rein Andre*/
#include <stdio.h>

main(void){
	//Variable Declaration
	int size, n, BSIT[1000], positive=0, negative=0;
	char restart;
	
	printf("---------< ARRAYS - ACTIVITY 1 >---------\n\n");
	
	//do-while loop - Restart
	do{
		//Array Size Validation
		do{
			printf("> ENTER THE PREFERRED ARRAY SIZE: ");
			scanf("%d", &size);
			if(size > 0){
				break;
			}
			else {
				printf("\nAn invalid array size has been entered, please try again and\n");
			}
		} while(size <= 0);
		
		printf("-----------------------------------------");
		//Integer Inputs
		printf("\nEnter %d integer/s:\n", size);
		for(n=0; n < size; n++){
			scanf("%d", &BSIT[n]);
		}
		
		printf("-----------------------------------------\n");
		//Negative Counter
		for(n=0; n < size; n++){
			if(BSIT[n] < 0){
				printf("%d, ", BSIT[n]);
				negative += 1;
			}
			else
				continue;
		}
		printf("\nThere are %d negative integer/s\n\n", negative);
		
		//Positive Counter
		for(n=0; n < size; n++){
			if(BSIT[n] > 0){
				printf("%d, ", BSIT[n]);
				positive += 1;
			}
			else
				continue;
		}
		printf("\nThere are %d positive integer/s\n", positive);		
		
		//Restart Prompt
		printf("-----------------------------------------\n");
		printf("If you wish to try more values,\nplease enter Y. Otherwise, enter any key: ");
		scanf("%s", &restart);
		printf("=========================================\n\n\n");
	} while (restart=='Y' || restart=='y');
	
	printf("Thank you for using the program! :^)");
	
	return 0;
}
