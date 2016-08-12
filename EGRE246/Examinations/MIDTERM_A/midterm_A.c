/******************************************************************
 * Program #: [MIDTERM_B]
 *
 * Programmer: [John C. Wray]
 *
 * Due Date: [October 15, 2015]
 *
 * EGRE 246, Fall 2015      Instructor: Dr. Tim Bakker
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: [Midterm_B]
 *
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct contestants{
  char Last_Name[32];
  struct contestants *next;
};

struct contestants *create_list(struct contestants *head, int total_contestants);
void displayall(struct contestants *head);

int main(void) {
    struct contestants *head = NULL, *current = NULL;
    int n, total_contestants = 0;
    time_t t;
    
    printf("How many contestants: "); //Displays prompt to user asking total number of contestants
    scanf("%d", &total_contestants);  //Reads in total number of contestants
    
    
    srand((unsigned) time(&t));   //Ultimately rand()%(32767+1); sets the upper bound to 32767
    
    head = create_list(head, total_contestants); //Creates Linked List
    current = head;                              //Sets current to head
    displayall(head);                            //Displays the last names of all contestants
    
    for(n = rand()%32768; n != 0; current = current->next, n--) //iterates through the linked list a randomn number of times
     if(current == NULL)                //The linked list is initially linear; therefore, the first time through the list make it circular
       current = head;                  //Causes the linked list to become circular

    printf("The lucky winner is %s \n", current->Last_Name); //Prints the name of the Lucky Winner
    
    for(current = head; total_contestants; total_contestants--, current = head){ //Initializes loop that begins freeing existant, reserved blocks of allocated data returned by malloc function.
          head = current->next; //Moves header to next structure to track information as data is being free.
          free(current);          //Frees data for reserved block of allocated memory for the first structure to the last structure in linked list.
        }
    
    
    return 0;
}

struct contestants *create_list(struct contestants *head, int total_contestants){  //function that creates a linked list with contestant names
  static int i = 0;

  if(i < total_contestants){
    head = (struct contestants *) malloc(sizeof(struct contestants)); //Assigns head a pointer to allocated
    printf("Last name of contestant [%d]: ", (i++ + 1));
    scanf("%s", head->Last_Name);                             //Reads in the Last Name of the Contestant from User input
    head->next = create_list(head->next, total_contestants);  //Add Last Names by recursion
  }

  return head;

}

void displayall(struct contestants *head){  //function that displays all of the contestant names
  static int i = 1;
  if(head){
    printf("Contestant [%2d]: %s\n", i++, head->Last_Name);  //prints the last name of the contestant in the linked list
    displayall(head->next);                 //Recursively display all the names in the linked list
  }
  else
   return;
}