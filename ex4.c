#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <memory.h>
#include <sys/resource.h>

int main(){
    int *memory ;
    struct rusage usage;
    for(int i = 0; i < 10; i++)
    {
        memory = malloc(8e7);
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory Used: %ld\n", usage.ru_maxrss );
        memset(memory, 0, sizeof (memory));
        sleep(1);
    }
}
