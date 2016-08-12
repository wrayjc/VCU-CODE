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
#include <cstdlib>  //exit()
#include "array.h"


//CONSTRUCTIONS AND DESTRUCTION: Costructor and Destructor Definitions
array::array(){this->elements = 0;}  //Default Constructor: sets member "elements" to zero.

array::array(int arg){               //Custom Constructor: uses new to allocate the number of elements and set the private memebers up.
  for(data = new double [arg], elements = 0; elements < arg; elements++) *(data + elements) = 0;
}

array::array(const array& arg){                //Copy Constructor: allocates correct number of elements, sets member elements correctly, and copies over all data determined by input argument. 
  for(data = new double [arg.elements], this->elements = 0; this->elements < int(arg.elements); (this->elements)++) data[this->elements] = arg.data[this->elements];
}

array::~array(){delete this->data;}      //Destructor


//Operators
array& array::operator=(const array& arg){
 if(elements == arg.elements){ 
 for(int i=0; &data[i] < &data[elements] && &arg.data[i] < &arg.data[arg.elements]; i++) *(data + i) = *(arg.data + i);    
 return *this;
 }
 else{
   std::cout << "ERROR: arrays are not equal size." << std::endl;     //reports error if array sizes do not match
   exit(1);
 }
}

array operator+ (double arg1, const array& arg2){                     //addition operator overload for constant added to array
 array addition_constant_matrix(arg2.elements); 
 for(int i = 0; (arg2.data + i) != (arg2.data + arg2.elements); i++)
   addition_constant_matrix[i] = arg1 + *(arg2.data + i);                    //pointer arithmetic to prevent unneccesssary calls to [] operator
  return addition_constant_matrix;
}

array operator+ (const array &arg1, const array& arg2){
 
 if(arg1.elements == arg2.elements){ 
  array two_matrix_addition(arg1.elements);
   for(int i = 0; i < int(arg1.elements); i++){
     two_matrix_addition[i] = *(arg1.data + i) + *(arg2.data + i);    //pointer arithmetic doesn't require operator [] to be called and increases speed?
  }
  return two_matrix_addition;
}else{
   std::cout << "ERROR: arrays are not equal size." << std::endl;
   exit(1);
}
}

array operator+(const array& arg1, double arg2){
  array addition_matrix_constant(arg1.elements);
  for(int i = 0; i < int(arg1.elements); i++)
   addition_matrix_constant[i] = *(arg1.data + i) + arg2;     //matrix added to constant operator
  return addition_matrix_constant;
}

//Other Function definitions
void array::print(void){                                 
for(int i = 0; (data + i) != &data[elements]; i++)
 if(*(data + i) < 10)                               //custom formatting algorithm to prevent the unneccessary demand when calling standard defined with extra checks to irrelevant procedures
  std::cout << " " << *(data + i) << " ";
 else
  std::cout << *(data + i) << " ";
  std::cout<<std::endl;
}
