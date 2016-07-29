/* 	Project #2
	EGRE245 Spring 2015
	JOHN C. WRAY */

#include <stdio.h>
#include <math.h>

int main(void) {
    float x1, x2, x3, x4, y1, y2, y3, y4, perimeter;
	printf("Proj. #2 - JOHN C. WRAY\n");
    printf("Enter 2 values representing (x,y) coordinates for each point.\n");
    
    printf("point #1: ");
    scanf("%f %f", &x1, &y1);
    printf("  [point #1 is (%.3f,%.3f)] \n",x1,y1);
    
    printf("point #2: ");
    scanf("%f %f", &x2, &y2);
    printf("  [point #2 is (%.3f,%.3f)] \n",x2,y2);
    
    printf("point #3: ");
    scanf("%f %f", &x3, &y3);
    printf("  [point #3 is (%.3f,%.3f)] \n",x3,y3);
    
    printf("point #4: ");
    scanf("%f %f", &x4, &y4);
    printf("  [point #4 is (%.3f,%.3f)] \n",x4,y4);
    
    perimeter = (sqrt(((x4-x3)*(x4-x3))+((y4-y3)*(y4-y3)))+(sqrt((((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)))))+(sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1))))+(sqrt(((x1-x4)*(x1-x4))+((y1-y4)*(y1-y4)))));
    
    printf("perimeter of paddock = %.2f\n", perimeter);
    
    return 0;
}
