#include <stdio.h>
#include  <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main (){
    printf("before fork()\n");
    int x = fork();
    printf("After fork()");
}