
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
 * Description: [Pointers and Dynamic Memory Allocation main File]
 *
 ******************************************************************/
#include <stdio.h>     //Includes my standard input/output library
#include <stdlib.h>    //Allows for the malloc and free function to be used
#include "Homework2.h" //Includes my header file

int main(void)
{
    int i = 0, expectedinput = 0, errorcheck = 0;
    char *letters, userinput;
    
    printf("\aHow many letters do you want to enter (0..9): "); //Asks user how many inputs that user expects to enter and input must be 0 through 9
    scanf("%d", &expectedinput);                                //Request for number of expected inputs
    letters = (char *)malloc((expectedinput+1) * sizeof(char)); //Allocates memory according to user input for my pointer letters
    
    for(i = 0; i < expectedinput; i++)
    {
        printf("Please enter letter #%2d: ", (i+1));   //(i+1) because for loops begins at 0
        scanf(" %c", &userinput);                      //Reads in the user input
		
        while(1)                                       //This loops checks to make sure user input is valid
        {
          if((userinput >= 'A' && userinput <= 'Z') || (userinput >= 'a' && userinput <= 'z'))  //Checks to make sure that input is only alphabet
          {*(letters + i) = userinput; break;}       //stores valid userinput into *letters and then breaks out of error checking loop
          else                                     //initializes if user input is invalid
          {printf("\aInvalid letter, please enter a valid letter: "); scanf(" %c", &userinput);} //Notifies user that input is invalid and request valid input
        }
     }                                 // END OF FOR LOOP
	sort(letters, expectedinput);      //Scans and sorts user input
    printf("Sorted letters:\n");
    for(i = 0; i < expectedinput; i++) printf("%c  ", *(letters + i));     //Prints the sortted letters
	printf("\n");       //Breaks New line after sorted letters are printed
    
	free(letters);      //Frees any dynamic memory that was allocated before the program exits
    return 0;           //Communicates with the operating system 0 that everything functioned properly
}
