#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void reallocate(int* ptr, int size){
    if(ptr==NULL){
        ptr= malloc(size* sizeof(int));
        return;
    }
    if(size==0){
        free(ptr);
        return;
    }
    int* temp= malloc(sizeof(ptr));
    memcpy(temp, ptr, sizeof(ptr));
    ptr= malloc(size*sizeof(int));
    memcpy(ptr, temp, sizeof(ptr));
    return;
}
int main(){
    int size, newSize;
    printf("Kindly enter the size of your array \n");
    scanf("%d",&size);
    int* arr = malloc(size*sizeof(int));
    printf("Your array is\n");
    // initialize with 1 to make sure everything works
    for(int i = 0; i < size; i++) {
        arr[i] = 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Kindly enter the new size of your array:\n");
    scanf("%d",&newSize);
    reallocate(arr,newSize);
    //initialize with 1 if the new size is bigger than the previous size
    if(newSize > size)
        for(int i = size; i < newSize; i++)
             arr[i] = 1;

    for(int i = 0;i < newSize; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
