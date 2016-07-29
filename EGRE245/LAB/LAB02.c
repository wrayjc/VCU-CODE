/* 	LAB #2

	JOHN C. WRAY */

#include <stdio.h>

int main(void) {
    double result;
    double result2;
    float x;
    
    printf("enter a value for x:\n");
    scanf("%f",&x);
    
    result = ((3*(x*x*x*x*x)) + (2*(x*x*x*x)) - (5*(x*x*x)) - (x*x) + 7*x - 6);
    result2 = (((((3*x+2)*x-5)*x-1)*x+7)*x-6);
    printf("result = %lf \n", result);
    printf("result2 = %lf\n", result2);
    return 0;
    
    
//LAB2 PART 2
    
    double a,b,c,d,e,g;
    double result;
    float x;
    
    printf("enter a polynomial (max degree 5:))\n");
    printf("x^5 coefficient:");
    scanf("%lf",&a);
    printf("x^4 coefficient:");
    scanf("%lf",&b);
    printf("x^3 coefficient:");
    scanf("%lf",&c);
    printf("x^2 coefficient:");
    scanf("%lf",&d);
    printf("x^1 coefficient:");
    scanf("%lf",&e);
    printf("x^0 coefficient:");
    scanf("%lf",&g);
    printf("Enter a value for x:");
    scanf("%f",&x);
    
    result = ((2*(x*x*x*x*x)) - (2*(x*x)) + 4);
    printf("result = %lf \n", result);
    return 0;
}

