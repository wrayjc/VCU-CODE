/******************************************************************
 * Program #: [Homework #3]
 *
 * Programmer: [John C. Wray]
 *
 * Due Date: [October 2, 2015]
 *
 * EGRE 246, Fall 2015      Instructor: Dr. Tim Bakker
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: [Linked Lists main file]
 *
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "rainfall.h"

int main(void){
    //typedef is used to parameterize a program against portability problems, provide better documentation, and to improve aesthetics.
  typedef struct monthly_rainfall *Rainfall_Struct; //Declares Rainfall_Struct a synonym for type definition struct monthly_rainfall *.
  typedef struct monthly_rainfall Rainfall_Data;    //Declares Rainfall_Data a synonym for type definition struct monthly_rainfall.
  int input = 0, month = 0, year = 0;                        //Declares an integer variable initialized at 0 (for no data) that records input requested from user.
  float rainfall_inch = 0.00;
  Rainfall_Struct header = NULL, current = NULL;    //Declares two variables as pointers used as reference record that points to the beginning of the linked list.
    
    printf("How many months of data should be entered: "); //Displays prompt to user requesting the number of months of data that will be recored.
  do{                  //Post-operation checking, verifys that controls flow after following arguments have been performed.
  scanf("%d", &input); //Reads integer from user and assigns the value to integer variable totaldata.
  }while(input < 0);   //Control flow statement that verifys that input is an appropriate value in D:[0,infinity).
  
  if(input){           //Control flow statement executes arguments for nonzero inputs from user.
    header = (struct monthly_rainfall *) malloc(sizeof(struct monthly_rainfall)); //Assigns header to address of returned pointer to a reserved block of allocated memory.
    
    do{               //Post-operation checking, verifys that controls flow after following arguments have been performed.
      printf("What is the starting year: "); //Displays prompt to user requesting the starting that rainfall data will be recorded.
      scanf("%d",&(header->year));           //Reads integer from user and assigns the value to integer variable year at beginning of linked list.
    }while(header->year < 0);                //Control flow statement that verifys that year is an appropriate value (i.e. existent year must be greater than zero).
    
    do{                                               //Post-operation checking, verifys that controls flow after following arguments have been performed.
      printf("What is the starting month (1..12): "); //Displays prompt to user requesting the starting month that rainfall data that will be recorded.
      scanf("%d",&(header->month));                   //Reads integer from user and assigns the value to integer variable month at beginning of linked list.
    }while(header->month < 1 || header->month > 12);  //Control flow statement that checks to verify user input for month is within the appropriate bounds of 1 to 12.
    
    printf("Enter rainfall in inches for month %2d and year %4d: ", header->month, header->year); //Displays prompt to user requesting rainfall data for corresponding month and year.
    scanf("%f",&(header->rainfall_inch));  //Reads float from user and assigns the value to float variable rainfall_inch in the first structure.
    current = header;                      //Assigns current to point to header.
    
    for(--input; input; input--){          //Initialized loop that creates remaining structures based on the users initial input.
      current->next = (struct monthly_rainfall *) malloc(sizeof(struct monthly_rainfall)); //Returns pointer to reserved block of allocated memory then assigns address to current self-reference.
      
      current->next->year = (current->month == 12)?current->year + 1 : current->year; //Increments year by 1 after 12 month cycle.
      current->next->month = (current->month == 12)? 1 : current->month + 1;          //Increments month by 1 for each structure or sets month equal to 1 after month 12.
      current = current->next;                                                        //Assigns current to point to the next structure in list.
      
      printf("Enter rainfall in inches for month %2d and year %4d: ", current->month, current->year); //Display prompt: requests rainfall data corresponding to month and year.
      scanf("%f", &current->rainfall_inch); //Reads float from user and assigns the value to float variable rainfall_inch in the current structure.
      
      current->next = NULL; //Assigns NULL to the last structure in the list.
    }                       //Terminate Loop after created user-defined total number of structures with stored rainfall data in linked lists.
    do{                                                         //Post-operation checking, verifys that controls flow after following arguments have been performed.
      printf("Enter option:\n");                                //Displays prompt to user requesting input of one of the following options.
      printf("%8c(0) - Exit\n",' ');                            //Displays prompt informing user option 0 Exits program.
      printf("%8c(1) - Find highest monthly rainfall\n",' ');   //Displays user informing user option 1 finds highest monthly rainfall.
      printf("%8c(2) - Find lowest monthly rainfall\n",' ');    //Displays prompt informing user option 2 finds lowest monthly rainfall.
      printf("%8c(3) - Calculate total average rainfall\n",' ');//Displays prompt informing user option 3 calculates total average monthly rainfall.
      printf("%8c(4) - Display all rainfall data\n",' ');       //Displays prompt informing user option 4 displays all rainfall data.
      printf("%8c(5) - Change rainfall entry\n",' ');           //Displays prompt informing user option 5 allows user to change a rainfall entry.
      printf("%8cChoice? ",' ');                                //Displays prompt to user requesting the user choice of the preceeding options.
      scanf("%d", &input);                                      //Reads integer from user and performs operation based on user's choice.
      
      if(input == 0){                                           //Begins exiting process when user inputs 0 for choice.
        for(current = header; current; current = header){       //Initializes loop that begins freeing allocated data reserved malloc function
          header = current->next;                               //Moves header to next structure to track information as data is being free
          free(current);                                        //Frees data for reserved block of allocated memory for the first structure to the last structure in linked list.
        }
        return 0;                                               //Exits program after allocated memory has been free'd, and communicate with operating system 0 for no errors
      }
      else if(input == 1){                                      //Begins desired process for when user inputs 1 for choice.
        current = findHighestRainfall(header);                  // Find the entry with highest monthly rainfall in the logged data and return a pointer to this structure
        printf("Highest rainfall recorded in year %4d, month %2d, total rainfall in inches %2.2f\n", current->year, current->month, current->rainfall_inch);
      }
      else if(input == 2){                                      //Begins desired process for when user inputs 2 for choice.
        current = findLowestRainfall(header);                   // Find the entry with highest monthly rainfall in the logged data and return a pointer to this structure
        printf("Lowest rainfall recorded in year %4d, month %2d, total rainfall in inches %2.2f\n", current->year, current->month, current->rainfall_inch);
      }
      else if(input == 3)                                       //Begins desired process for when user inputs 3 for choice.
        printf("Average total rainfall %.3f\n", calcAverageRainfall(header)); // Calculate the monthly average over all the logged data.
      else if(input == 4)                                       //Begins desired process for when user inputs 4 for choice.
        displayAll(header);                                     // Display all the recorded data
      else if(input == 5){                                      //Begins desired process for when user inputs 5 for choice.
        printf("Year of entry to be changed: ");    //Displays prompt to user requesting the year of the entry being updated.
        scanf("%d", &year);                         //Reads integer from user and assigns the value to integer variable used to lookup corresponding lists.
        printf("Month of entry to be changed: ");   //Displays prompt to user requesting the month of the entry being updated.
        scanf("%d", &month);                        //Reads integer from user and assigns the value to integer variable used to lookup lists and crosslink with month.
        printf("Rainfall in inches: ");             //Displays prompt to user requesting the rainfall data for the entry being updated.
        scanf("%f", &rainfall_inch);                //Reads float from user and assigns the value to float variable used to replace rainfall data of corresponding structure.
        if(changeEntry(header, year, month, rainfall_inch) == -1) //Checks function return value -1 for Replacement Failure and 0 for Replacement Successful.
          printf("Cannot find year and month entry!\n");          //Displays error to user that the year and month was unable to be located to complete change of rainfall data.
        }
      }while(input);                                //While the user input is not 0, reperforms do loop (i.e. redisplays preceeding prompt and requests user's choice).
  }                         //Control flow statement that occurs when user initially inputs nonzero for number of months of data that should be entered.
else                                                //Control flow statement that occurs when user initially inputs 0 for number of months of data that should be entered.
  return 0;                                         //If user intially inputs 0 months of entry program exits immediately
}
