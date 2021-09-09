#include <stdio.h>
#include  <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main (){
    for(int i = 0; i < 10; i++) {
        int x = fork();
        printf(x != 0 ? "Hello from parent %d\n" : "Hello from child %d\n", getpid());
    }
}