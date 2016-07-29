/* 	Project #5 - Evaluating Voltages
	EGRE245 Spring 2015
	JOHN C. WRAY 
 A C program that generates a report from an electric power substation that measures voltages for 72 continuous hours.
 The program determines:
   1.) the mean voltages over the time period
   2.) the hours at which the recorded voltages varies from the mean by more than 10%
   3.) any adjacent hours when the change from one reading to the next was greater than 15% of the mean
   4.) the hours when a brownout occured (i.e. when voltage drops below 10.8% of 120V
 */
        //PROGRAM STARTS HERE
#include <stdio.h>
#define MAX 72
#define BROWNOUT (120.000*0.892)    //Brownout Threshold calculated

int main(void) {
  int voltage[MAX] = {0}, brownout_occurance[MAX] = {0};    //arrays defined
  int input = 0, hour = 0, sum = 0, brownout_count = 0, dev10 = 0, dev15 = 0, total10 = 0, total15 = 0, browncount = 0; //calculators and counters
  float mean = 0, mean_10per = 0, mean_15per;    //precision defined error boundary
    
  printf("\nEGRE245  PROJECT #5  SPRING 2015 - JOHN C. WRAY\n\n");
  printf("\aUser please input past 72 hourly voltages:\n");
    
  for(sum = 0, input = 0; input < MAX; input++) //Begins Reading in 72 integer voltage values from standard input
  { scanf("%d", &voltage[input]); sum += voltage[input];
    if(voltage[input] < BROWNOUT) {brownout_occurance[input] = 1; brownout_count++;} //Brownouts Recorded in brownout_occurance && counted
    if(input == 71) {mean = ((sum * 1000)/ MAX); mean *= 0.001; mean_10per = mean * 0.10; mean_15per = mean * 0.15;} }   //Means Voltages & Variance (10%,15%) Calculated
  
  printf("\nNumber of voltages: %.2d\nMean: %.2f (10%% of mean: %.2f; 15%% of mean: %.2f)\nBrownout threshold: %.2f\n\n\n", input, mean, mean_10per, mean_15per, BROWNOUT);
    //All Calculations Outputed (i.e. Number of Voltages, Mean Voltage, 10% && 15% of that mean, Brownout Voltage)
  printf("hours that vary >=10%% from mean:\n"); printf("  ");
    for(hour = 0; hour < MAX; hour++) if (voltage[hour] >= (mean + mean_10per) || voltage[hour] <= (mean - mean_10per)) total10++;
    if(total10 == 0) printf("[none]");   //only runs the next loop if it must
    else for(hour = 0; hour < MAX; hour++) if (voltage[hour] >= (mean + mean_10per) || voltage[hour] <= (mean - mean_10per)) {printf("%d", (hour+1)); dev10++; if(dev10 != total10) printf(",");}
  printf("\n");
    //10%% Variance Outputted and if none, then [none] outputted
  printf("hours of neighbors that vary >=15%% of mean:\n"); printf("  ");
    for(hour = 0; hour < MAX-1; hour++) if (voltage[(hour+1)] >= (voltage[hour] + mean_15per) || voltage[(hour+1)] <= (voltage[hour] - mean_15per)) total15++;
    if(total15 == 0) printf("[none]");    //only runs the next loop if it must
    else for(hour = 0; hour < (MAX-1); hour++) if (voltage[(hour+1)] >= (voltage[hour] + mean_15per) || voltage[(hour+1)] <= (voltage[hour] - mean_15per)) {printf("(%d,%d)", (hour + 1), (hour +2)); dev15++; if(dev15 != total15) printf(",");}
  printf("\n");
    //15%% Neighbor Variance Outputted and if none, then [none] outputted
  printf("hours brownout occured:\n");  printf("  "); if(brownout_count == 0) printf("[none]"); //only run the next loop if it must
  else for(hour = 0; hour < MAX; hour++) if(brownout_occurance[hour] == 1) {printf("%d", (hour+1)); browncount++; if(browncount < brownout_count) printf(",");} //COMMA PROBLEM
  printf("\n");
    //Brownouts Outputted and if none, then [none] outputted
  return 0;    //Communicate with operating system
}
        //PROGRAM ENDS HERE