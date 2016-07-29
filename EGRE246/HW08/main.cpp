/******************************************************************
 * Program #8: Operator Overload
 *
 * Programmer: John C. Wray
 *
 * Due Date: Friday, November 20, 2015
 *
 * EGRE 246, Fall 2015      Instructor: Dr. Tim Bakker
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: Implement array class supports addition operator overload
 *              the assignement operator and the array [] subscript operator
 *
 ******************************************************************/

#include <iostream>
#include "array.h"

int main(void){

    
    array a(2), b(2);
   
    a[0] = 2;
    a[1] = 3;
    b[0] = a[1];
    b[1] = 10;

    array x = 6 + a;
    x.print();

    array y = a + b;
    y.print();

    array z = b + 10;
    z.print();

    array c(3);
    a + c;
  

  a.print();
  b.print();
}
