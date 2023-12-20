#include<stdio.h>
#include<conio.h>
main(void){
	//Variable Declaration
	int i, answer[5], total=0;
	float average=0;
	char name[1000];
	
	//Student Name Input
	printf("Enter student name:  ");
	scanf("%s", &name);
	
	//Answer Input
	for (i=0; i < 5; i++){
		printf("Enter Answer #%d?  ", i+1);
		scanf("%d", &answer[i]);
		if (answer[i] <= 5 && answer[i] > 0){
			continue;
		}
		else {
			printf(" - OUT OF RANGE!\n");
			answer[i]=0; 
		}
	}
	
	//Computation
	for (i=0; i < 5; i++){
		total += answer[i];
	}
	average = total / 5.0;
	
	//Output
	printf("\n%s, your total score is %d and your average score is %f", name, total, average);
	
	return 0;
}




