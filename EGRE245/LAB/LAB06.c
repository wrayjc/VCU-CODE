//  LAB6.c
//
// John Wray
// 3/3/15
// Input positive integer n  and reports back (outputs) if it is prime or not
//

#include <stdio.h>

int main(void)
{
    int userinput, maxcheck = 1, divisable = 0, notdivisable = 0, check, primecheck = 0, version, count = 0, count2 = 0;
    printf("Enter 1 for Part 1 or Enter 2 for Part 2:");
    scanf("%d", &version);
    switch(version)
    {
case 1:
    {
    printf("Request for User to Input positive integer:\n");
    scanf("%d",&userinput);
    while(userinput<0)
    {
        printf("Input Requires Positive Integer:/n");
        scanf("%d",&userinput);
    }
    for(maxcheck = 1 ; maxcheck <= userinput ; maxcheck++)
    {
        check = userinput % maxcheck;
        if(check > 0)
            notdivisable++;
            if(check==0)
                divisable++;
    }
    if(divisable != 2)
        printf("Input integer %d not prime\n", userinput);
        else
            printf("Input integer %d prime\n", userinput);
    }
    break;

    
case 2:
    {
    printf("Request for User to Input positive interger R to specify Range for");
    printf(" program to list all prime integers within range from [0,R]\n\n");
    scanf("%d",&userinput);
    while(userinput<0)
    {
        printf("Input Requires Positive Integer:\n");
        scanf("%d",&userinput);
    }
    if(userinput>1)
    {
    printf("Prime Numbers between 2 and %d\n", userinput);
    
    while(primecheck < userinput)
    {
        primecheck++;
        divisable = 0;
      for(maxcheck = 1 ; maxcheck <= primecheck ; maxcheck++)
    {
        if(maxcheck>primecheck)
            break;
        check = primecheck % maxcheck;
        if(check==0)
            divisable++;
        
    }
        if(divisable == 2)
        {
            printf("%d", primecheck);
            count++;
            count2++;
            if(count == 10)
            {
                printf("\n");
                count = 0;
            }
            else
                printf("\t");
        }
    }
    }
    else
        printf("No prime numbers by definition in Range from 0 to %d", userinput);
    }
            printf("\nTotal Prime Numbers: %d\n\n", count2);
    break;
            
default:
    printf("ERROR: USER INPUT INCORRECT: PROGRAM TERMINATED \n");
    break;
    }
    
    return 0;
}
