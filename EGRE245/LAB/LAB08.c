
#include <stdio.h>
#define MAX 6

double solvePoly(double x)
{
    return (3*x*x*x*x*x+2*x*x*x*x-5*x*x*x-x*x+7*x-6);
    
}

double solvePoly2(double x, double a[])
{
    return (a[0]+a[1]*x+a[2]*x*x+a[3]*x*x*x+a[4]*x*x*x*x+a[5]*x*x*x*x*x);
}
double solvePoly3(double x, double a[])
{
    int k, t;
    for(k = 1, t=a[0]; k < MAX; k++)
        t += a[k]*x;
    return t;
    
}
int main(void)
{
    int j = 0;
    double x, a[MAX] = {0};
    
    printf("Please enter a value for x:");
    scanf("%lf", &x);
    printf("The evaluated function is %.2lf \n", solvePoly(x));
    
    for(j = 0; j < MAX; j++)
    {
        printf("User enter coefficient %d:", j);
        scanf("%lf", &a[j]);
        
    }
    printf("\n");
    
    printf("The evaluated function is %lf \n", solvePoly2(x, a));
    printf("The evaluated function is %lf \n", solvePoly3(x,a));
    return 0;
}
