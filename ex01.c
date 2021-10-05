#include <stdio.h>
#include <malloc.h>
int main() {
    int  N;
    printf("Kindly enter the size of your array");
    scanf("%d", &N);
    //dynamically allocating the array
    int *array = malloc(N * sizeof (int));
    // filling the array with incremented  values
    for(int i = 0; i < N; i++)
    {
        array[i] = i;
    }
    // printing array
    for(int i = 0; i < N ; i++)
        printf("%d ", array[i]);

    // freeing memory of the array
    free(array);
    return 0;
}
