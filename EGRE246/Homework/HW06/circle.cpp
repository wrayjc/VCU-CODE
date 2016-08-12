/********************************************************************************
 * Program #: Homework #6                                                       *
 *                                                                              *
 * Programmer: John Wray                                                        *
 *                                                                              *
 * Due Date: Friday, November 6, 2015                                           *
 *                                                                              *
 * EGRE 246, Fall 2015      Instructor: Dr. Tim Bakker                          *
 *                                                                              *
 * Pledge: I have neither given nor received unauthorized aid on this program.  *
 *                                                                              *
 * Description: Given a main source file and the circle class definition file,  *
 *              this program implements a circle class.                         *
 *                                                                              *
 ********************************************************************************/

#include "circle.h"
#define Pi 3.1415926535897932384626433832795 //Constant Pi defined: value obtained from http://www.wolframaplha.com

circle::circle(){
 radius = 1;                          //Initialize a circle with no parameters passed into arguments as a unit circle
}

circle::circle(float r){
  radius = r;                          //Radius is a private member of class circle, so it can only be accessed by member functions
}

circle::circle(const circle &obj){
 radius =  obj.radius;
}

void circle::setRadius(float r){
 radius = r;
}

float circle::getRadius(void){
  return radius;
}

float circle::getArea(void){
  return Pi*radius*radius;             //Area of a circle: A = pi R^2
}

float circle::getCircumference(void){
  return 2*Pi*radius;                  //Circumference of a circle: C = 2 pi R
}

