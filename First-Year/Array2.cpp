/*ACTIVITY 2
Almadrones, Charles Cedric
Felipe, Reiniel
Furagganan, Rein Andre*/
#include <stdio.h>

main(void){
	//Variable Declaration
	int n, m, integer, N[10], B[10], COMBINE[10];
	char restart;
	
	printf("---------< ARRAYS - ACTIVITY 2 >---------\n");
	
	//do-while loop - Restart
	do{	
		//Input Sequences
		do{//Array-N
			printf("\nENTER 5 INTEGERS FOR ARRAY-N:\n"); 
			for(n=0; n < 5; n++)
				scanf("%d", &N[n]);	
			
			integer=0;
			for (n=0; n < 5; n++){
				for (m=0; m < n; m++){
					if (N[n]==N[m])
						integer++;
				}
			}
			if (integer==0)
				break;
			else
				printf("\nYou have entered repeated values.\nCreate new list of unique integers-");
		} while(integer>=1);
		printf("-----------------------------------------");
		
		do{//Array-B
			printf("\nENTER 5 INTEGERS FOR ARRAY-B:\n"); 
			for(n=0; n < 5; n++)
				scanf("%d", &B[n]);	
			
			integer=0;
			for (n=0; n < 5; n++){
				for (m=0; m < n; m++){
					if (B[n]==B[m])
						integer++;
				}
			}
			if (integer==0)
				break;
			else
				printf("\nYou have entered repeated values.\nCreate new list of unique integers-");
		} while(integer>=1);
		printf("-----------------------------------------");
		
		//Combine Sequences (Transfers content of Array B to Array N, then transfers Array N to Array COMBINE)
		for(n=0; n < 5; n++)
			N[5+n]=B[n];
			//Skips value if negative
		for (n=0; n < 10; n++){
			if(N[n]<0)
				continue;
			else
				COMBINE[n]=N[n];
		}
		
		//Unique Values Output
		printf("\nARRAY-COMBINE VALUES:\n");
		for (n=0; n < 10; n++){
			for (m=0; m < n; m++)
				if (COMBINE[n]==COMBINE[m])
					break;
			if (n==m)
				printf("%d ", COMBINE[n]);
		}
		
		//Restart Prompt
		printf("\n-----------------------------------------\n");
		printf("If you wish to try more values,\nplease enter Y. Otherwise, enter any key: ");
		scanf("%s", &restart);
		printf("=========================================\n\n");
	} while (restart=='Y' || restart=='y');
	
	printf("Thank you for using the program! :^)");
		
	return 0;
}
