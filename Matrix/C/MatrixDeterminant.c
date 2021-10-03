/** 
------------------------------------------------------------------------------------------------
DESCRIPTION: PROGRAM TO FIND THE DETERMINANT OF A 2X2 MATRIX 
------------------------------------------------------------------------------------------------
**/

#include <stdio.h>
#define MATRIX_SIZE 2 

int main()
{
    int A[MATRIX_SIZE][MATRIX_SIZE];
    int row, column;
    long determinant;

    /* Input elements in matrix A from user */
    printf("Enter elements in matrix of size 2x2: \n");
    for(row=0; row<MATRIX_SIZE; row++)
    {
        for(column=0; column<MATRIX_SIZE; column++)
        {
            scanf("%d", &A[row][column]);
        }
    }


    determinant = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);

    printf("Determinant of matrix A = %ld", determinant);

    return 0;
}
