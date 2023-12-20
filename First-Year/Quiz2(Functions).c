#include <stdio.h>
#include <conio.h>

void KOMPUTE (int a, float b, float *c){
     if (a == 1 && b <= 1.00)
          *c = 2.00;
     else if (a == 2 && b <= 1.00)
          *c = 10.00;
     else if (a == 1 && b > 1.00)
          *c = (1*2.00) + ((b-1)*5.00);
     else if (a == 2 && b > 1.00)
          *c = (1*10.00) + ((b-1)*15.00);
     printf ("Cost: %0.2f", *c);
}

main (){
     int l_code;
     float weight, cost=0;
     printf("Letter Code: ");
     scanf("%d", &l_code);
     printf("Weight (g): ");
     scanf ("%f", &weight);
     KOMPUTE (l_code, weight, &cost);
}
