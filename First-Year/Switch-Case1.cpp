#include<stdio.h>
#include<conio.h>

main(void){
	int Month=0;
	printf("Please enter the number of the desired month:\t");
	scanf("%d", &Month);
	switch (Month){
		case 1: 
			printf("January\n");
			printf("New Year's Day / My Birthday (January 6) / Feast of the Black Nazarene");
		break;
		case 2: 
			printf("February\n");
			printf("Valentine's Day / Chinese New Year / Black History Month");
		break;
		case 3: 
			printf("March\n");
			printf("Semana Santa(Holy Week) / Easter Sunday / St. Patrick's Day");
		break;
		case 4: 
			printf("April\n");
			printf("Araw ng Kagitingan (Day of Valor) / Earth Day / April Fool's Day");
		break;
		case 5: 
			printf("May\n");
			printf("Labor Day / National Flag Day / Mothers' Day");
		break;
		case 6: 
			printf("June\n");
			printf("Independence Day / Pride Month / Fathers' Day");
		break;
		case 7: 
			printf("July\n");
			printf("Sandugo Festival / Banana Festival / T'nalak Festival");
		break;
		case 8: 
			printf("August\n");
			printf("Cabibi Festival / Tigawon Festival / Coron Festival");
		break;
		case 9: 
			printf("September\n");
			printf("Sarakiki Festival / Megayon Festival / Busig-on Festival");
		break;
		case 10: 
			printf("October\n");
			printf("Halloween / Banana Festival / T'nalak Festival");
		break;
		case 11: 
			printf("November\n");
			printf("Undas / Higantes Festival / Bonifacio Day");
		break;
		case 12: 
			printf("December\n");
			printf("Christmas / Simbang Gabi / New Year's Eve");
		break;
		default: printf("Not a month");
	}
	getch();
}
