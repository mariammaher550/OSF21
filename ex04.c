#include <string.h>
#include "stdio.h"
int N = 1e5+5;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
   int a,b;
    printf("Kindly enter 2 numbers\n");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("The first number is %d, while the second number is %d", a, b);
}