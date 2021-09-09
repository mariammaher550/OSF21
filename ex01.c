#include <stdio.h>
#include  <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
int main (){
    int n = 5;
    for(int i = 0; i < 10; i++) {
        int x = fork();
      //  wait(NULL);
        if (x != 0) {
            printf("Hello from parent [%d - %d]\n", getpid(), n);
        } else {
            printf("Hello from child [%d - %d]\n", getpid(), n);
        }
    }
}
