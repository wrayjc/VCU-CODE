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

#ifndef ARRAY_H
#define ARRAY_H
  
#include <stdlib.h>

class array{
    public:
        array();
        array(int);
        array(const array&);
        ~array();

   array& operator=(const array&);
   friend array operator+(double, const array&);
   friend array operator+(const array&, const array&); 
   friend array operator+(const array&, double);
 
 double& operator[](int index){return this->data[index];};
   void print(void);
 
 private:
   double *data;
   int elements;
};  

#endif //ARRAY_H
