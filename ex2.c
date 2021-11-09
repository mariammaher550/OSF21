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
            while(true) {
                ssize_t b = read(fd, &ev1, sizeof(ev1));
                //released
                if(ev1.value == 0 && ev1.type == EV_KEY)
                    printf("RELEASED 0x%04x (%d)\n", ev1.code, ev1.code);
                    //pressed
                else if (ev1.value == 1 && ev1.type == EV_KEY)
                    printf("PRESSED 0x%04x (%d)\n", ev1.code, ev1.code);
            }
    }
    fflush(stdout);
}
