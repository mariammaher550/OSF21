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
    int keys[100] = {};
    if(fd < 0) {
        return EXIT_FAILURE;
    }
    else {

            struct input_event ev1;
            int cnt = 0;
            while(true) {
                ssize_t b = read(fd, &ev1, sizeof(ev1));
                if(ev1.type == EV_KEY) {
                    keys[ev1.code] = ev1.value;
                        if (keys[25] = 2 && keys[18] == 2 || keys[25] == 1 && keys[18] == 1 ) {
                            printf("I PASSED\n");
                        if (keys[46]==2&&keys[30]==2&&keys[25]==2||keys[46]==1&&keys[30]==1&& keys[25]==1) {
                            printf("I WANT COFFEE\n");
                        }
                    }
                }
            }
    }
    fflush(stdout);
}
