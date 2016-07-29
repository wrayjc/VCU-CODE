/* 	Lab #5
	EGRE245 Spring 2015
	JOHN C. WRAY */

#include <stdio.h>
#include <math.h>

int main(void) {
    int a,i;
    float x=2.5,c=2;
    printf("Enter an integer greater than 2 for approximation:\n");
    scanf("%d",&a);
        while(a<3)
        {
           printf("ERROR: enter integer greater than 2\n");
            scanf("%d",&a);
        }
    for(i = 3; i <= a; i++)
    {
        c=i*c;
        x = x+1/c;
        }
    printf("e from math.h = %.3f\n",x);
    return 0;
}
