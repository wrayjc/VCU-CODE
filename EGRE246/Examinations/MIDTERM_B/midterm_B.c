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

//INCLUDED LIBRARIES
  #include <stdio.h>
  #include <stdlib.h>
//END OF INCLUDED LIBRARIES


//STRUCTURE DECLARATIONS
  struct person{     //STRUCT PERSON TYPE-DECLARATION
    int age;         //AGE OF PERSON
    char name[50];   //NAME OF PERSON
  };
//END OF STRUCTURE DECLARATIONS


//FUNCTION PROTOTYPES
  void displayall(struct person **foo, int total_elements);  //PROTOTYPE FOR DISPLAY ALL FUNCTION
  void sort(struct person **foo, int n);                     //PROTOTYPE FOR SORT FUNCTION
  void swap(struct person **a, struct person **b);           //PROTOTYPE FOR SWAP FUNCTION
//END OF FUNCTION PROTOTYPES


int main(void){
  struct person **foo = NULL;    //DECLARES POINTER ARRAY **foo; AN ARRAY OF POINTERS POINTING TO PERSON STRUCTURES
  int total_elements = 0, i = 0; //DECLARES INTEGERS FOR STORING THE VALUE FOR TOTAL NUMBER OF PERSONS THAT USER WILL STORE DATA AND LOOP INDEX VARIABLE

  printf("Person total: ");        //PROMPTS USER TO ENTER VALUE FOR THE PERSON TOTAL IN WHICH DATA WILL BE INPUTTED
  scanf("%d", &total_elements);    //USER INPUT REQUEST: READS INTEGER VALUE INPUT FROM USER FOR TOTAL PERSON NUMBER IN WHICH DATA WILL BE STORED

  foo = (struct person **)malloc((total_elements) * sizeof(struct person *)); //DYNAMICALLY ALLOCATE MEMORY FOR ARRAY ELEMENT (i.e. EXPANDS POINTER ARRAY)
  for(i = 0; i < total_elements; i++){                  //LOOP STORING DATA FOR USER DEFINED NUMBER OF PERSONS IN STRUCTURES LINKED BY A POINTER ARRAY
    foo[i] = (struct person *)malloc((total_elements)*sizeof(struct person));  //DYNAMICALLY ALLOCATE MEMORY FOR CORRESPONDING STRUCTURE TO STORE DATA
    printf("Person Age:");            //PROMPT USER TO ENTER PERSON AGE
    scanf(" %d", &foo[i]->age);       //USER INPUT REQUEST: READS INTEGER INPUT STORES PERSON AGE IN PERSON STRUCTURE AND ASSIGNS POINTER IN ARRAY TO POINT TO IT
    printf("Person Name:");           //PROMPT USER TO ENTER PERSON NAME.
    scanf(" %s", foo[i]->name);       //USER INPUT REQUEST: READS CHAR INPUT & STORES PERSONS NAME IN PERSON STRUCTURE AND ASSIGNS POINTER IN ARRAY TO POINT TO IT
  }

//FUNCTION CALLS
  printf("\nThe Person Data inputed by USER:\n");  //DISPLAYS HEADING FOR UNSORTED USER INPUTTED DATA
  displayall(foo, total_elements);    //DISPLAYS ALL DATA IN ORIGINAL ORDER INPUTTED BY USER [BEFORE SORT::ORIGINAL ORDER]
  
  printf("\n::SORTING STORED DATA BY AGE FROM LOW TO HIGH::\n"); //DISPLAYS NOTIFICATION THAT DATA SORTING HAS STARTED
  sort(foo, total_elements);          //SORT INPUTTED DATA BASED ON PERSONS AGE FROM LOW TO HIGH
  
  printf("\nThe Person Data sorted by AGE:\n");  //DISPLAYS HEADING FOR SORTED DATA
  displayall(foo, total_elements);    //DISPLAYS ALL SORTED DATA [AFTER SORT::ORGANIZED DATA]
//END OF FUNCTION CALLS
  
  
  while(--total_elements >= 0) //FREE DYNAMICALLY ALLOCATED MEMORY BEFORE EXITING FOR ARRAY ELEMENTS foo[0] to foo[total_elements -1]
    free(foo[total_elements]); //FREE DYNAMICALLY ALLOCATED MEMORY BEFORE EXITING STARTS AT LAST ELEMENT foo[total_elements-1], AND ENDS AT FIRST ELEMENT, {foo[0]}
  free(foo);                   //FREE DYNAMICALLY ALLOCATED MEMORY BEFORE EXITING ENTIRE ARRAY OF POINTERS: SHRINKS THE ARRAY
  return 0;                    //EXIT OUT OF MAIN :: REPORTS 0 ERROR TO SYSTEM

}  //END OF MAIN


//FUNCTION DEFINITIONS
  void displayall(struct person **foo, int total_elements){              //DISPLAY ALL FUNCTION PRINTS ALL STORED DATA OF CORRESPONDING POINTER ARRAY
    int i = 0;                                                           //DECLARES INDEX FOR LOOP

    for(i = 0; i < total_elements; i++)                                  //LOOPS THROUGH ALL ELEMENTS OF POINTER ARRAY
     printf("[%2d]  The age of %s: %2d\n",i+1,foo[i]->name,foo[i]->age); //PRINTS PERSON DATA STORED IN EACH STRUCTURE CORRESPONDING TO A POINTER ARRAY ELEMENT

  }                                                                      //END OF DISPLAY ALL FUNCTION


  void sort(struct person **foo, int n){ //SORTS POINTER ARRAY NUMERICALLY ARRANGING PERSON'S AGE FROM LOW TO HIGH BY INTERNALLY CALLING SWAP FUNCTION
    int i = 0, j = 0;               //DECLARE INDEXS FOR LOOPS
  
    for(i = 0; i < n-1; i++)        //LOOPS THROUGH POINTER ARRAY ELEMENTS FROM FIRST ELEMENT TO SECOND-TO-LAST ELEMENTS (i.e. foo[0 to (n-2)) FOR COMPARISON
     for(j = i; j < n; j++)         //LOOPS THROUGH ALL ARRAY ELEMENTS FROM foo[i] TO LAST ELEMENT TO BE COMPARED TO [AGE] VALUE GIVEN BY THE CURRENT foo[i]
      if(foo[i]->age > foo[j]->age) //COMPARES INTEGER [AGE] VALUE OF AN ELEMENT IN POINTER ARRAY TO ALL OTHER ELEMENT VALUES WITHIN SAME ARRAY
       swap(&foo[i], &foo[j]);      //CALLS SWAP FUNCTION WHEN TWO UNSORTED (i.e. LARGER AGE VALUE COMES BEFORE SMALLER AGE VALUE) ELEMENTS ENCOUNTERED
    
  }                                 //END OF SORT FUNCTION



  void swap(struct person **a, struct person **b){ //SWAPS TWO ELEMENTS OF A POINTER ARRAY :: TO BE CALLED WITHIN SORT FUNCTION

    struct person **temp;                          //CREATE TEMP STRUCTURE OF SAME TYPE AS A AND B

    temp = (struct person **)malloc(sizeof(struct person *)); //ALLOCATES SPACE FOR TEMP POINTER ARRAY WHOSE ELEMENTS CONTAINS POINTERS TO STRUCTURES
    temp[0] = (struct person *)malloc(sizeof(struct person)); //ALLOCATES SPACE FOR THE STRUCTURE TEMP POINTER POINTS TO IN ITS FIRST ARRAY ELEMENT 0

    *temp[0] = *a[0];       //TEMP IS DUPLICATE OF A
    *a[0] = *b[0];          //A IS REPLACED BY B
    *b[0] = *temp[0];       //B IS NOW REPLACED BY ORIGINAL A

    free(temp[0]);          //FREE DYNAMICALLY ALLOCATED MEMORY BEFORE EXITING FUNCTION::PREVENTS MEMORY LEAKS
    free(temp);             //FREE DYNAMICALLY ALLOCATED MEMORY BEFORE EXITING FUNCTION::PREVENTS MEMORY LEAKS
  }                         //END OF SWAP FUNCTION

//END OF FUNCTION DEFINITIONS
