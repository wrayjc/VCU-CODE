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


#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define NUMBER_OF_ENTRIES 5
#include <stdio.h>
struct data{
        char website[32];   //Name of the first website
        char username[32];  //Username for the first website
        char password[32];  //Password for the first website
    };

void requestEntry(struct data *);
void displaySummary(struct data *);
void displayEntry(struct data *);


#endif /* defined(FUNCTIONS_H) */
