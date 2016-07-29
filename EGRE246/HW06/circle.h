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
#ifndef CIRCLE_H
#define CIRCLE_H

class circle{

    private:
	float radius;

    public:
        circle();
	circle(float r);
	circle(const circle &obj);

        void setRadius(float r);
        float getRadius(void);

        float getArea(void);
	float getCircumference(void);
};

#endif
