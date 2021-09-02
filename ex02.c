#include <string.h>
#include "stdio.h"
void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int *arr, int size){
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
}
int main (){
    int arr[100], size;
    printf("Enter size of your array\n");
    scanf("%d", &size);
     for(int i = 0; i < size; i++)
         scanf("%d", arr+i);

    bubble_sort(arr, size);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);


}