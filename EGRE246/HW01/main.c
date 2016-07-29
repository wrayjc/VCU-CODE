/******************************************************************
 * Program #: [Homework #1]
 *
 * Programmer: []
 *
 * Due Date: [February 12, 2016 11:59 p.m]
 *
 * EGRE 246, Spring 2016      Instructor: Dr. George M. Cardwell
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: [Password Manager]
 *
 ******************************************************************/


#include <stdio.h>
#include "functions.h"
int main(void){
    struct data input[NUMBER_OF_ENTRIES];
    requestEntry(input);
    displaySummary(input);
    displayEntry(input);
    
    
    return 0;
}
