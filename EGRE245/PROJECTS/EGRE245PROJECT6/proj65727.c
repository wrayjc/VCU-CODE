/* 	Project #6 - Anlyzing Integer Lists
	EGRE245 Spring 2015
	JOHN C. WRAY
    APRIL 6, 2015
*/

#include <stdio.h>
#define NUM_PER_LINE 20
#define MAXINPUT 10000
#define POSSIBLEVALUES 52
#define ERROR 666
int main(void) {
double avg = 0, sumofvalues = 0;
int a[MAXINPUT] = {0}, i = 0, f = 0, g = 50, j = 0, lat = 0, lbt = 0, nlta = 0, nsta = 0, avg2 = 0;
  int b[POSSIBLEVALUES] = {0}, c[POSSIBLEVALUES] = {0}, d[POSSIBLEVALUES] = {0}, e[POSSIBLEVALUES] = {0};
  int errorcheck = 0;
  printf("EGRE245 Project #6 John C. Wray\n");
   for(i = 0; i < MAXINPUT; i++)
   {scanf("%d", &a[i]); sumofvalues += (double) a[i]; avg = (double) sumofvalues/(i + 1);
   if(i == 0) {f = a[i]; g = a[i];} else if(a[i] > f) f = a[i]; else if(a[i] < g) g = a[i];
   if(a[i] < 0 || a[i] > 50) {errorcheck = ERROR; break;}}
   if(errorcheck == ERROR) printf("\aFATAL ERROR USER INPUT OUTSIDE ACCEPTABLE BOUNDS OF 0 TO 50\n");
   
   else{
   for(j = (f - (int) avg), lat = j; j > 0; --j)
   {b[j] = (int) avg + j;for(i = 0; i < MAXINPUT; i++) if(b[j] == a[i]) {c[j]++; nlta++;} if(c[j] < c[lat] && c[j] != 0) lat = j;}
   
   avg2 = avg; if(avg - (double) avg2 > 0.00)
   {for(j = ((int) avg - g), lbt = j; j >= 0; --j)
   {d[j] = (int) avg - j; for(i = 0; i < MAXINPUT; i++) if(d[j] == a[i]) {e[j]++; nsta++;} if(e[j] < e[lbt] && e[lbt] > 0) lbt = j;}}
   
   else
   {for(j = ((int) avg - g), lbt = j; j > 0; --j)
   {d[j] = (int) avg - j; for(i = 0; i < MAXINPUT; i++) if(d[j] == a[i]) {e[j]++; nsta++;} if(e[j] < e[lbt] && e[lbt] > 0) lbt = j;}}
    
   printf("number of values %d \n", i == MAXINPUT? i : ERROR); printf("largest value %d \n", f);
   printf("sum of values %.2lf \n", sumofvalues); printf("average: %2.2lf \n", avg);
   printf("number larger than average: %d \n", nlta);
    
   if(nsta > 0) printf("smallest item that occurs the least (%d times): %d\n", e[lbt], d[lbt]);
   else printf("no items smaller than average\n");
   if(nlta > 0) printf("largest item that occurs the least (%d times): %d\n", c[lat], b[lat]);
   else printf("no items larger than average\n");}
   return 0;}
