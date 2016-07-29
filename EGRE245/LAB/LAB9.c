//
//  Lab9.c
//  Created by John Wray on 4/7/15.
//
//

#include <stdio.h>
#define SIZE 20

int analyze(int list[],int x,int counts[]);


int main(void){
    int k = 0, list[SIZE] = {0}, counts[11] = {0}, i;
    for(k = 0; k < SIZE; k++)
        scanf("%d", &list[k]);
    analyze(list, SIZE, counts);
    printf("Counts:\n");
    printf("----- -----\n");
    for(i = 0; i <= 10; i++)
        printf("%4d %4d\n", i, counts[i]);

    return 0;
    
}

int analyze(int list[],int x,int counts[])
{
    int i = 0, k = 0;
    for(i = 0; i < 11; i++)
        for(k = 0; k < x; k++)
            if(list[k] == i) counts[i]++;
        return *counts;
}