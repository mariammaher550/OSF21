#include <stdio.h>
#include  <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>

int main (){
    int n = 5;
    for(int i = 0; i < 3; i++) {
        int x = fork();
        sleep(5);
        if (x != 0) {
            printf("Hello from parent [%d - %d]\n", getpid(), n);
        } else {
            printf("Hello from child [%d - %d]\n", getpid(), n);
        }
    }

}
