/*send to:
 
SEND TO: devensja@vcu.edu before 2359
 
JOHN C. WRAY
EGRE 245 LAB
02/04/2015

ASSIGNMENT 1:SOLUTION ONE
WRITE A COMPLETE C PROGRAM THAT ASKS THE USER TO ENTER A 3-DIGIT INTEGER AND THEN PRINTS THE NUMBER WITH ITS DIGITS REVERSED.
 YOU ARE TO WRITE TWO DIFFERENT VERSIONS OF YOUR PROGRAM.
 INPUT EACH DIGIT ONE-AT-A-TIME INTO SEPARATE VARIABLES, THEN OUTPUT THEM IN REVERSE ORDER.
 */

#include<stdio.h>
int main(void){
    int a,b,c;
    printf("INTEGER REVERSAL V1 INITIALIZED\n");
    printf("ENTER ONLY A THREE-DIGIT INTEGER:");
    scanf("%1d%1d%1d",&a,&b,&c);
    
    printf("The reversal is ");
    printf("%1.d",c);
    printf("%1.d",b);
    printf("%1.d\n",a);
    
    
    
     //LAB #3 V2
     //ASSIGNMENT 1:SOLUTION TWO
     //WRITE A COMPLETE C PROGRAM THAT ASKS THE USER TO ENTER A 3-DIGIT INTEGER AND THEN PRINTS THE NUMBER WITH ITS DIGITS REVERSED.
     //YOU ARE TO WRITE TWO DIFFERENT VERSIONS OF YOUR PROGRAM.
     //INPUT EACH DIGIT ONE-AT-A-TIME INTO SEPARATE VARIABLES, THEN OUTPUT THEM IN REVERSE ORDER.
    
    int d,e;
    a = b = c = d = e = 000;
    printf("ARITHMETIC INTEGER REVERSAL V2 INITIALIZED\n");
    printf("ENTER ONLY A THREE-DIGIT INTEGER:");
    scanf("%d",&d);
    b = d;
    c = 0.100*b;
    e = 0.010*b;
    
    b = b-10*c;
    c = c-10*e;
    
    printf("The reversal is ");
    printf("%3d\n",100*b+10*c+e);
    
    
     //LAB #3
     //ASSIGNMENT 2:OCTAL (this program needs to be corrected.)
     //WRITE A COMPLETE C PROGRAM THAT READS AN INTEGER ENTERED BY THE USER AND DISPLAYS IT IT OCTAL (BASE 8)
     //THE OUTPUT SHOULD BE DISPLAY USING 5 DIGITS EVEN IF FEWER DIGITS ARE SUFFICIENT
int userinput, digit5 = 0, digit4 = 0, digit3 = 0, digit2 = 0, digit1 = 0, octal = 0;

    printf("ENTER A INTEGER BETWEEN 0 and 32767:");
    scanf("%d",&userinput);
    while(octal <= userinput)
    {
        if(octal == userinput)
            break;
        digit1++;
        if (digit1 == 7)
        {
            digit1 = 0;
            digit2++;
        }
        if (digit2 == 7)
        {
            digit2 = 0;
            digit3++;
        }
        if (digit3 == 7)
        {
            digit3 = 0;
            digit4++;
        }
        if (digit4 == 7)
        {
            digit4 = 0;
            digit5++;
        }
        octal = digit5 * (8 * 8 * 8 * 8) + digit4 * (8 * 8 * 8) + digit3 * (8 * 8) + digit2 * 8 + digit1;
    }
    printf("In, octal your number is: %d%d%d%d%d \n\n",digit5, digit4, digit3, digit2, digit1);

    return 0;
}