#include <stdio.h>
#include <conio.h>
#include <windows.h>
int i, j;
int COMPUTE(int A[3], int B[3][3], int C[3]);
int DISPLAY(int A[3], int B[3][3], int C[3]);

int COMPUTE(int A[3], int B[3][3], int C[3]){
     for (i=0; i<3; i++){ 
          for (j=0; j<3; j++){
               C[i] += (A[j] * B[i][j]);
          }
     }
}

int DISPLAY(int A[3], int B[3][3], int C[3]){
     printf(":: MULTI-DIMENSIONAL ARRAYS\n  Submitted by: Rein Furagganan BSIT 1-1\n");
     printf("\n< ARRAY A >\n"); //Array A display output
     for (i=0; i<3; i++)
          printf(" %d  ", A[i]);
     printf("\n");

     printf("\n< ARRAY B >\n"); //Array B display output
     for (i=0; i<3; i++){
          for (j=0; j<3; j++)
               printf(" %d  ", B[i][j]);
          printf("\n");
     }

     printf("\n< ARRAY C >\n"); //Array C display output
     for (i=0; i<3; i++)
          printf(" %d  ", C[i]);
}

int main(){
     int A[3]={1, 2, 3}, B[3][3]={{4, 5, 6},{7, 8, 9},{10, 11, 12}}, C[3]; //Assigns Value to Arrays
     COMPUTE(A, B, C); //Brings Assigned Values to COMPUTE function
     DISPLAY(A, B, C); //Brings COMPUTE values for display
}