/*JD WINE
Almadrones, Charles Cedric
Felipe, Reiniel
Furagganan, Rein Andre*/
#include <stdio.h>

int main(void){
	//Variable Declarations
	int bucket=0, cat=0,i ;
	
	printf("|        << JD WINE COMPANY >>        |");
	printf("\n| HOUR | DROPS OF WINE PER HOUR | CAT |\n");
	
	/*Loops that will start at 1st hour
	and will stop if bucket is filled with 2452 drops of wine*/
	for(i=1; bucket<2452; i++){
		bucket += 162;
		
		//basic command for every hour
		if (i%3!=0){
		printf("|  %02d  |          %04d          |     |\n",i, bucket);
		}
		
		//command for every 3 hours
		else{
		bucket-=28;
		cat+=28;
		printf("|  %02d  |          %04d          | %03d |\n", i, bucket, cat);
		}
	}
	
	//Concluding output
	printf("\nThe bucket was filled at %d hours", i-1);
	printf("\nCat drunk %d drops of wine", cat);
	
	return 0;
}
