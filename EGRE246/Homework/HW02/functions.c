
/******************************************************************
 * Program #: [Project #2]
 *
 * Programmer: [John Wray]
 *
 * Due Date: [9/11/2015]
 *
 * EGRE 246, Fall 2015      Instructor: Dr. Tim Bakker
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: [Pointers and Dynamic Memory Allocation Functions File]
 *
 ******************************************************************/
#include<stdio.h>
#include "Homework2.h"

void swap(char *x, char *y)     //Swap function from online code example using pass by reference
{
	char temp = *x;             //Defines a char temp and sets it equal to what is stored in *x
    *x = *y;                    //Sets what is stored in *y and stores it in *x replacing what is already store
	*y = temp;                  //stores what was originally in *x in *y by setting *y equal to temp
}

void sort(char *a, int size)        //Sort function that sorts the letters the user inputs
{
	int i = 0, j = 0;                       //Defines two integers i and j that can be used in my for loops
	for(i = 0; i < size - 1; i++)   //Scan through characters passed into *a
	   for(j = i+1;j < size; j++)
           if( *(a+i) > *(a+j)) swap(a+i, a+j);    //Calls function swap in order to sort characters stored in *a
}
