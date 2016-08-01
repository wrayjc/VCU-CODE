#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_PER_LINE 20
int main(void) {
    FILE *fp;
    char fileName[30];
    int n,i,upper;
    time_t t;
    printf("data file to create? ");
    scanf("%s",fileName);
    printf("how many random numbers? ");
    scanf("%d",&n);
    printf("upper bound? ");
    scanf("%d",&upper);
    fp = fopen(fileName,"w");
    srand((unsigned) time(&t));
    for(i = 1 ; i <= n ; i++ ) {
        fprintf(fp,"%d ", rand()%(upper+1));
        if (i % NUM_PER_LINE == 0) fprintf(fp,"\n");
    }
    fclose(fp);
    return 0; }