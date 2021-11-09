#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <linux/input.h>
#include <fcntl.h>
#include <error.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

int main(){
    char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fd = open(dev, 0,O_RDONLY);
    if(fd < 0) {
        return EXIT_FAILURE;
    }
    else {

            struct input_event ev1;
            int seq[3] = {};
            int cnt = 0;
            while(true) {
                ssize_t b = read(fd, &ev1, sizeof(ev1));
                //released
                if((ev1.value == 0 || ev1.value == 1) && ev1.type == EV_KEY )
                {
                    seq[cnt] = ev1.code;
                    cnt++;
                }
                if(cnt == 2)
                {
                    if(seq[0] == 80 && seq[1] == 69)
                    {
                        printf("I PASSED\n");
                    }
                }
                else if (cnt == 3)
                {
                    if(seq[0] == 67 && seq[1] == 65 && seq[2] == 80)
                    {
                        cnt = 0;
                        memset(seq, 0, sizeof (seq));
                        printf("I WANT COFFEE\n");
                    }
                }
            }
    }
    fflush(stdout);
}


