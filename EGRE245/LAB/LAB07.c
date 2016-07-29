//  LAB7.c
//
// John Wray
// 3/24/15
// Input positive integer n  and reports back (outputs) if it is prime or not
//

#include <stdio.h>
#define MAXIMUM 25

int main(void)
{
    int sum = 0, i = 0, j = 0, evensum = 0, oddsum = 0, sumdiagonal = 0, diagonalsum = 0, oppositediagonal = 0, MAXIMUMINPUT = 0;
    int a[MAXIMUM][MAXIMUM] = {0}, column[MAXIMUM] = {0}, row[MAXIMUM] = {0};
    printf("User please input integer for square matrix size:\n");
    scanf("%d", &MAXIMUMINPUT);
    
    printf("User please input integer:\n");
    for(i = 0; i < MAXIMUMINPUT; i++)
        for(j = 0; j < MAXIMUMINPUT; j++)
        {scanf("%d", &a[i][j]); sum += a[i][j];
            if(a[i][j]%2 != 0) oddsum += a[i][j];
            if(a[i][j]%2 == 0) evensum += a[i][j];
            if (i == j) diagonalsum += a[i][j];
            if ((i == 0 && j == (MAXIMUMINPUT - 1)) || (j == 0 && i == (MAXIMUMINPUT - 1)) || (j == (MAXIMUMINPUT - i) && (MAXIMUMINPUT - i) > 0)) oppositediagonal += a[i][j];
            row[i]+= a[i][j];
            column[j]+= a[i][j];}
    printf("The sum of all integers %d\n", sum);
    printf("The sum of all odd integers %d\n", oddsum);
    printf("The sum of all even integers %d\n", evensum);
    printf("The sum of all diagonal integers %d\n", diagonalsum);
    printf("The sum of all opposite diagonal integers %d \n", oppositediagonal);
    for(i = 0; i < MAXIMUMINPUT; i++) printf("The sum of row %d is %d \n", (i+1), row[i]);
    for(i = 0; i < MAXIMUMINPUT; i++) printf("The sum of column %d is %d \n", (i+1), column[i]);
    
    printf("\n\n");
    for(i = 0; i < MAXIMUMINPUT; i++)
        {for(j = 0; j < MAXIMUMINPUT; j++)
            printf("%d ", a[i][j]);
            printf("\n");}

    return 0;
}
