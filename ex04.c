#include <stdio.h>
#include  <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

int MAX_CMDS = 100;
int main (){
    char *cmdLine;
    char **cmdArg;


    printf("Enter you commands. do not exceed 100 command");
    while (true) {
        for (int i = 0; i < MAX_CMDS; i++) {
            cmdLine[i] = '\0';
            cmdArg[i] = NULL;
        }


        fgets(cmdLine, sizeof(cmdLine), stdin);

        int w = 0;
        int c = 0;

        cmdLine[0] = (char *) malloc(MAX_CMDS);
        for (int i = 0; i < strlen(cmdLine) - 1; i++) {
            if (cmdLine[i] == ' ') {
                cmdArg[w++][c] = '\0';
                cmdArg[w] = (char *) malloc(MAX_CMDS);
                c = 0;
            } else {
                cmdArg[w][c++] = cmdLine[i];
            }
        }

        int x = fork();
        if (x == 0) {
            execvp(cmdArg[0], cmdArg);
        }
    }
}
