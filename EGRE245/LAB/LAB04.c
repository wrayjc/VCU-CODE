#include<stdio.h>
#include<math.h>
int main(void){
    /*
    float a,b,c, d, e, f,g,h,i;
    printf("ENTER A NUMBER:");
    scanf("%f",&a);
    printf("ENTER A NUMBER:");
    scanf("%f",&b);
    printf("ENTER A NUMBER:");
    scanf("%f",&c);
    printf("ENTER A NUMBER:");
    scanf("%f",&d);
    printf("ENTER A NUMBER:");
    scanf("%f",&e);
    printf("ENTER A NUMBER:");
    scanf("%f",&f);
    printf("ENTER A NUMBER:");
    scanf("%f",&g);
    printf("ENTER A NUMBER:");
    scanf("%f",&h);
    printf("ENTER A NUMBER:");
    scanf("%f",&i);

    if(a > b && a > c && a > d && a > e && a > f && a > g && a > h && a > i)
    printf("The largest number entered: %.1f\n", a);
    
    if(b > a && b > c && b > d && b > e && b > f && b > g && b > h && b > i)
        printf("The largest number entered: %.1f\n", b);
    
    if(c > a && c > b && c > d && c > e && c > f && c > g && c > h && c > i)
        printf("The largest number entered: %.1f\n", c);
            
    if(d > a && d > b && d > c && d > e && d > f && d > g && d > h && d > i)
    printf("The largest number entered: %.1f\n", d);
    if(e > a && e > b && e > c && e > d && e > f && e > g && e > h && e > i)
    printf("The largest number entered: %.1f\n", e);
    if(f > a && f > b && f > c && f > d && f > e && f > g && f > h && f > i)
    printf("The largest number entered: %.1f\n", f);
    if(g > a && g > b && g > c && g > d && g > e && g > f && g > h && g > i)
    printf("The largest number entered: %.1f\n", g);
    if(h > a && h > b && h > c && h > d && h > e && h > f && h > g && h > i)
    printf("The largest number entered: %.1f\n", h);
    if(i > a && i > b && i > c && i > d && i > e && i > f && i > g && i > h)
    printf("The largest number entered: %.1f\n", i);
    
    */
    
    int n, MAX, i, squares, even;
    printf("Please enter an integer n:\n");
    scanf("%d",&n);
    MAX = sqrt(n);
    for(i = 0; i <= MAX; i++)
    {
        even = 2*i;
        squares = even * even;
        if(squares > n)
            break;
        printf("%d\n", squares);
        
    }

    return 0;
}