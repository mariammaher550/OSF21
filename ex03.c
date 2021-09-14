#include <stdio.h>
#include  <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>

int main (){
    char *cmd ;
    while(true){
        scanf("%s", cmd);
        system(cmd);
    }
    }
