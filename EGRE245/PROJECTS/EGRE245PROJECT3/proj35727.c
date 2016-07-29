/* 	Project #3
	EGRE245 Spring 2015
	JOHN C. WRAY
 */

#include <stdio.h>
#include <math.h>


int main(void) {
    printf("Proj. #3\tJohn C. Wray\tEGRE245\n\n");
    
    float dollartotal, d, cents;
    int ten,five,one,quarter,dime,nickle,penny,dollar;
    double userinput;
    
    printf("\aEnter ($) Amount: ");
    scanf("%lf",&userinput);
    
    cents = userinput * 100;
    one = userinput;
    penny = (cents - (100*one));
    userinput = cents * 0.01;
    printf("  Amount Entered: %.4f\n\n",userinput);
    
    
    
    
    if(userinput >= 0.00)
    {
        for(ten = 0; one >= 10; one -= 10)
        {
            ten++;
            if(10 > one)
                break;
        }
        for(five = 0; one >= 5; one-=5)
        {
            five++;
            if(one < 5)
                break;
        }
        for(quarter = 0; penny >= 25; penny -= 25)
        {
            quarter++;
            if(penny < 25)
                break;
        }
        
        for(dime = 0; penny >= 10; penny -= 10)
        {
            dime++;
            if(penny < 10)
                break;
        }
        
        for(nickle = 0; penny >= 5; penny -= 5)
        {
            nickle++;
            if(penny < 5)
            break;
        }
        
        dollartotal = d;
        printf("Total: $%.2f\n",userinput);
            printf("  %2d\tten dollar bill(s)\n",ten);
            printf("  %2d\tfive dollar bill(s)\n",five);
            printf("  %2d\tone dollar bill(s)\n",one);
            printf("  %2d\tquarter(s)\n",quarter);
            printf("  %2d\tdime(s)\n",dime);
            printf("  %2d\tnickle(s)\n",nickle);
            printf("  %2d\tpenny(s)\n",penny);
    }
    
        else
        {
            printf("MACHINE REQUESTS USER TRY AGAIN WITH POSITIVE NUMBER!\n");
        }
    
    return 0;
}
