//LAB 11 EGRE 245 SPRING 2015

#include <stdio.h>
#define T 100000       

void find_two_largest(int *a, int n, int *largest, int *second_largest);

int main(void){
    int numbers[T + 2] = {0}, *a;
    printf("User Enter %d Array Values:", T);
    for(a = &numbers[0]; a <= &numbers[T - 1]; a++) {scanf("%d", a);}
    find_two_largest(&numbers[0], T, &numbers[T], &numbers[T+1]);
    return 0;
}
void find_two_largest(int *a, int n, int *largest, int *second_largest)
{
  for(*largest = *second_largest = *a; a < largest; a++) if(*a > *largest) *largest = *a;
  for(;a >= (largest - T); a--) if(*a > *second_largest && *a < *largest) *second_largest = *a;
  printf("\nThe largest value is %d and the second largest value is %d \n", *largest, *second_largest);
}
