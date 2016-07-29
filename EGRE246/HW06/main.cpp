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
 *              This is the given circle class definition file.                 *
 *                                                                              *
 ********************************************************************************/

#include <iostream>

#include "circle.h"

using namespace std;

int main(void){

    // Create circle objects
    circle c1(2.0);
    circle c2(4.0);
    circle c3;

    c3.setRadius(10.0);
    circle c4(c3);

    std::cout << "Area of c1: " << c1.getArea() << std::endl;
    std::cout << "Circumference of c2: " << c2.getCircumference() << std::endl;
    std::cout << "Radius of c3: " << c3.getRadius() << std::endl;
    std::cout << "Radius of c4: " << c4.getRadius() << std::endl;
    
    return 0;
}
