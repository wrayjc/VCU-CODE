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
 * Description: [Linked Lists header file]
 *
 ******************************************************************/

#ifndef MONTH_H
#define MONTH_H

#define NUMBER_OF_MONTHS 12


struct monthly_rainfall{
    int month;                          // Number of the month, starting at 1
    int year;                           // Year
    float rainfall_inch;                // Rainfall in decimal inches

    struct monthly_rainfall *next;      // Self-referential member
};

// Display all the recorded data
void displayAll(struct monthly_rainfall *);

// Finds and changes the rainfall data for a given month and year. The return value should be 0 if it was able to find the entry and -1 if no entry could be found.
int changeEntry(struct monthly_rainfall *head, int year, int month, float rainfall);

// Find the entry with highest monthly rainfall in the logged data and return a pointer to this structure
struct monthly_rainfall *findHighestRainfall(struct monthly_rainfall *head);

// Find the entry with lowest monthly rainfall in the logged data and return a pointer to this structure
struct monthly_rainfall *findLowestRainfall(struct monthly_rainfall *head);

// Calculate the monthly average over all the logged data
float calcAverageRainfall(struct monthly_rainfall *head);


#endif

