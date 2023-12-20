/*
ALGORITHM Area_RT
S -> ' ', B -> 0, H -> 0, A -> 0.0
INPUT "Please enter the first character of the desired shape", S
IF S == 'R' || 'r' THEN
	INPUT "Please enter the desired base and height", B, H
A -> B * H
OUTPUT "The area of rectangle is", A
 	ELSE IF S == 'T' || 't' THEN
		INPUT "Please enter the desired base and height", B, H
     		 A -> (0.5 * B) * H
         		OUTPUT "The area of triangle is", A
ELSE
OUTPUT "Input cannot be identified", A
END IF
END IF
END Area_RT */

#include <stdio.h>
#include <conio.h>

main (void){
	char S;
	float AR=0.0, AT=0.0, B=0, H=0;
	printf("Please enter the first character of the desired shape:\n");
	scanf("%c",&S);
	if (S=='R'||S=='r'){
		printf("Pleas enter the desired base and height:\n");
		scanf("%f %f",&B, &H);
		AR=(B*H);
		printf("The area of the rectangle is %f", AR);
	}
	else if (S=='T'||S=='t'){
		printf("Pleas enter the desired base and height:\n");
		scanf("%f %f",&B, &H);
		AT=(0.5*B*H);
		printf("The area of the triangle is %f", AT);
	}
	else {
		printf("Input cannot be identified");
	}
	getch();
}

