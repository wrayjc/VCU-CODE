//Lab #10 UPGRADED
//

#include <stdio.h>
void  printArray(int list[],int x, int n);

int main(void){
    int i = 0, n = 0;
    
    printf("How many numbers do you wish to enter:");
    scanf("%d", &n);
    int list[n];
    
    printf("Please Enter %d Numbers:", n);
    for(i=0; i < n; i++)
        scanf("%d",&list[i]);
    
    printf("The numbers entered are: ");
    printArray(list, 0, n);
    return 0;
}

void printArray(int list[],int y, int n)
{
    int *p;
    p = list;
    printf("%d ", *(p+y));
    if((p+y) < &list[n-1])
    printArray(list, ++y, n);
    else printf("\n");

}

