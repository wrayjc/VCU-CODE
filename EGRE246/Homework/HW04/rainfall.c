/******************************************************************
 * Program #: [Homework #4]
 *
 * Programmer: [John C. Wray]
 *
 * Due Date: [October 9, 2015]
 *
 * EGRE 246, Fall 2015      Instructor: Dr. Tim Bakker
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: [Linked Lists functions file]
 *
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "rainfall.h"

//Find the entry with highest monthly rainfall in the logged data and return a pointer to this structure.
struct monthly_rainfall *findHighestRainfall(struct monthly_rainfall *head){
  struct monthly_rainfall *highest = head; //Create a structure pointer to header marking the structure containing largest current value known.
  if(head)                                 //Evaluates alignment requirements, executes arguments if a linked list of structures exists.
    while((head = head->next))             //Evaluates the existance of more structures initializing loop comparing values to determine highest value in linked list.
      highest = (highest->rainfall_inch < head->rainfall_inch) ? head : highest;  //Reset highest when less than current structure otherwise remain the same.
  else               //Control Flow statement that initializes in the event no existing linked lists can be located.
    return highest;  //Return NULL for nonexistant linked list, no existing structures located.
  return highest;    //Return pointer to structure containing highest value after all structures have been evaluated.
} //EITHER POINTER TO STRUCTURE CONTAINING HIGHEST VALUE OR NULL RETURNED.

//Find the entry with lowest monthly rainfall in the logged data and return a pointer to this structure.
struct monthly_rainfall *findLowestRainfall(struct monthly_rainfall *head){
  struct monthly_rainfall *lowest = head; //Create a structure pointer to header marking the structure containing smallest current value known.
  if(head)                                //Evaluates alignment requirements.
    while((head = head->next))            //Evaluates the existance of more structures initializing loop comparing values to determine lowest value in linked list.
      lowest = (lowest->rainfall_inch > head->rainfall_inch) ? head : lowest; //If lowest is larger than current structure reset lowest to current structure otherwise remain the same.
  else             //Control Flow statement that initializes in the event no existing linked lists can be located.
    return lowest; //Return NULL after all structures have been evaluated.
  return lowest;   //Return pointer to structure containing lowest value after all structures have been evaluated.
} //EITHER POINTER TO STRUCTURE CONTAINING LOWEST VALUE OR NULL RETURNED.

// Calculate the monthly average over all the logged data.
float calcAverageRainfall(struct monthly_rainfall *head){
  int months_rainfall = 1;                 //Declares an integer variable counting total structures involved in average calculationinitialized at 1 for first structure.
  float sum = head ? head->rainfall_inch : 0; //Declares a float variable that sums the values stored in each structure for the inches of rainfall.
  if(head)                        //Evaluates alignment requirements, executes arguments if a linked list of structures exists.
    while((head = head->next)){   //While another stucture exists, initialize loop involved in calculating average
      sum += head->rainfall_inch; //Adds the current value for rainfall data stored in structure to previously calculated sum.
      months_rainfall++;          //Increases count of total values by one for each structure that contains data that is added to sum
    }                             //Re-evaluate loop conditions involving average calculation for existing structures in an existant linked list.
  else                            //Control Flow statement that initializes in the event no existing linked lists can be located.
    return 0;                     //Return 0 for nonexistant linked list, no existing structures located; therefore, no data results in zero average.
  return (sum/((float) months_rainfall)); //Returns average as float calculated by dividing float sum by total calculated values coerced as type float to prevent truncation.
} //EITHER 0 AVERAGE RETURNED FOR NO EXISTING LINKED LISTS OR A CALCULATED AVERAGE RETURNED

//Finds and changes the rainfall data for a given month and year. The return value should be 0 if it was able to find the entry and -1 if no entry could be found.
int changeEntry(struct monthly_rainfall *head, int year, int month, float rainfall){
  while(head){                          //Initializes loop that spans each structures of the linked list starting at the first structure of the linked list.
    if(head->year == year)              //Control flow statement evaluating equality by cross-examining stored data set and user requested data set: the year.
      if(head->month == month){         //Control flow statement evaluating equalityby cross-examining stored data set and user requested data set: the month.
        head->rainfall_inch = rainfall; //Replaces value stored for rainfall data with rainfall data enter by user.
        return 0;                       //MATCH FOUND: Returns 0 reporting that function has completed operation without error.
      }                                 //Re-evaluate loop conditions for loop searching for existing structures in an existant linked list.
      else head = head->next;           //MATCH FAILURE: unable to find month updates head to point to next structure and begin re-examination process.
    else head = head->next;             //MATCH FAILUE: unable to find year updates head to point to the next structure in list and begin re-examination process.
  }                                     //Loop breaks when head position reaches NULL structure.
  return -1;                            //MATCH FAILURE: Returns -1 reporting operation error failure to locate unique record storing corresponding to requested data.
} //EITHER EXISTING DATA STRUCTURE UPDATED OR ERROR VALUE RETURNED REPORTING INVALID ENTRY.

//Display all the recorded data.
void displayAll(struct monthly_rainfall *head){
  if(head){                 //Control flow checking alignment requirements.
    printf("Year %4d, month: %2d, rainfall in inches %.2f\n", head->year, head->month, head->rainfall_inch); //Prints recorded rainfall data stored in data structures of link list.
    displayAll(head->next); //Recursive function call to the next structure in the linked list that reperforms preceeding arguments for the remaining structure.
  }
  else                      //Control flow checking alignment requirements initialized when linked list does not exist.
    return;                 //TERMINATE FUNCTION: NULL structure is encountered, linked list does not exist.
} //ALL EXISTING RECORDS OF STORED DATA PRINTED TO USER.

//Inserts a new entry/or adds to an existing entry into the rainfall data.
struct monthly_rainfall *insertEntry(struct monthly_rainfall *head, int year, int month, float rainfall){
  struct monthly_rainfall *current = head;            //Create a structure pointer initialized to head to act as position tracker.
  if(head)                                            //Control Flow Statement that examines alignment conditions and the existance of a linked list.
    if(changeEntry(head, year, month, rainfall) == 0) //Control Flow preventing structure duplication by examining existing linked list.
      return head;                                    //Function Terminated: Returns header to exisiting linked list with data replaced in existing structure.
    else if(year < head->year || (year == head->year && month < head->month)){    //Control Flow Statement maintains organization without duplicating stored data in existing linked list.
      head = (struct monthly_rainfall *) malloc(sizeof(struct monthly_rainfall)); //Returns a pointer that points to a reserved block of allocated memory then assigns to head its address.
      head->year = year;              //Assigns the value of year input to integer variable year at new beginning of linked list.
      head->month = month;            //Assigns the value of month input to integer variable month at new beginning of linked list.
      head->rainfall_inch = rainfall; //Assigns the value of rainfall input to float variable rainfall_inch at new beginning of linked list.
      head->next = current;           //Properly positions new header at beginning of linked list by assigning previous header address to self-reference pointer of new structure.
      return head;                    //Terminates Function: returns the header of the updated linked list that contains properly placed new structure.
      }
    else{                   //Control Flow Statement maintains organization without duplicating stored data in existing linked list.
      head->next = insertEntry(current->next, year, month, rainfall); //Recursive function call temporarily storing data structures while new data structure is properly positioned.
      return head;   //Terminates Function: returns the header of the updated linked list that contains properly placed new structure.
    }
  else{              //Control Flow statement initialized in the event no existing linked lists can be located or if new entry data is placed at end of the linked list.
    head = (struct monthly_rainfall *) malloc(sizeof(struct monthly_rainfall)); //Returns a pointer that points to a reserved block of allocated memory then assigns to head its address.
    head->year = year;              //Assigns the value of year input to integer variable year at beginning or end of linked list.
    head->month = month;            //Assigns the value of month input to integer variable month at beginning or end of linked list.
    head->rainfall_inch = rainfall; //Assigns the value of rainfall input to float variable rainfall_inch in the first or last structure.
    head->next = NULL;              //Assigns NULL to the last structure in the created or updated linked list.
    return head;                    //Returns the header of the structure of the newly created linked list that contains new data structure.
  }
}  //EITHER NEW DATA STRUCTURE INSERTED TO EXISITING LINKED LIST, CREATED NEW LINKED LIST WITH NEW DATA STRUCTURE INSERTED, OR EXISTING DATA STRUCTURE HAS BEEN UPDATED.
