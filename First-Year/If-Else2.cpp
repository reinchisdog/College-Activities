/*
ALGORITHM Damage
	N -> 0.0
	INPUT "Please enter the number in the Richter scale", N
	IF N < 5.0 THEN
		OUTPUT "LITTLE or NO DAMAGE"
	ELSE IF N >= 5.0 && N < 5.5 THEN
		OUTPUT "THERE ARE SOME DAMAGES"
	ELSE IF N >= 5.5 && N < 6.5 THEN
		OUTPUT "THERE ARE SERIOUS DAMAGE!"
	ELSE IF N >= 6.5 && N < 7.5 THEN
		OUTPUT "DISASTER! HOUSE AND BUILDINGS MAY COLLAPSE!"
	ELSE IF N >= 7.5
		OUTPUT "CATASTROPE!"	 
	END IF
	END IF
	END IF
	END IF
	END IF
END Damage */

#include<stdio.h>
#include<conio.h>

main (void){
	float N=0.0;
	printf("Please enter the number in the Richter Scale:\t");
	scanf("%f", &N);
	if (N<5.0){
		printf("LITTLE or NO DAMAGE");
	}
	else if (N>=5.0 && N<5.5){
		printf("THERE ARE SOME DAMAGES");
	}
	else if (N>=5.5 && N<6.5){
		printf("THERE ARE SERIOUS DAMAGES!");
	}
	else if (N>=6.5 && N<7.5){
		printf("DISASTER! HOUSE AND BUILDINGS MAY COLLAPSE");
	}
		else if (N>=6.5 && N<7.5){
		printf("CATASTROPHE!");
	}
	getch();
}
