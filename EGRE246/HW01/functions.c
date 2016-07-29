/******************************************************************
 * Program #: [Homework #1]
 *
 * Programmer: []
 *
 * Due Date: [September 4, 2015 11:59 p.m]
 *
 * EGRE 246, Fall 2015      Instructor: Dr. Tim Bakker
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: [Password Manager]
 *
 ******************************************************************/


#include <stdio.h>
#include "functions.h"

void requestEntry(struct data *input)
{
 for(int i = 0; i < 5; i++){
    printf("Please enter the following items:\n");
    printf("Website %d: ", i+1);
    scanf("%s",(input + i)->website);
    printf("Username: ");
    scanf("%s",(input + i)->username);
    printf("Password: ");
    scanf("%s",(input + i)->password);
    }
}

void displaySummary(struct data *input)
{
printf("Summary: \n");
for(int i = 0; i < NUMBER_OF_ENTRIES; i++)
    printf("%d - %s\n", (i + 1), (input + i)->website); //prints the website the user input
}

void displayEntry(struct data *input)
{
    int i = 1;
    while (i != 0){
    printf("\nType in a number from 1 to 5 to pull up the entry or type 0 to exit: ");
    scanf("%d", &i);
    if(i == 0) break;
    if (i > 5 || i < 0) 
     do{
      printf("ERROR: USER INPUT INVALID");
      printf("\nType in a number from 1 to 5 to pull up the entry or type 0 to exit: ");
      scanf("%d", &i);
    }while(i>5 || i < 0);
    
    printf("Website: %s \n", (input + (i-1))->website);
    printf("Username: %s \n", (input + (i-1))->username);
    printf("Password: %s \n", (input + (i-1))->password);
    }
    
}
