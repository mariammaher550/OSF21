#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

int MAXBUF = 100000;

int buf = 0;
bool consumer_sleep = false, producer_sleep = false;

void *producer(void *arg)
{
    printf("producer\n");

    while(1)
    {

        if(producer_sleep && consumer_sleep)
        {
            printf("Fatal race condition(\n");
            exit(1);
        }

        if(buf == MAXBUF)
        {
            producer_sleep = true;
            consumer_sleep = false;
        }

        if(!producer_sleep)
        {
            buf++;
            if(buf == rand() % MAXBUF) // Printing messages at random moments
                printf("Producing\n");
        }
    }
}

void *consumer(void *arg)
{
    printf("consumer\n");

    while(true)
    {

        if(producer_sleep && consumer_sleep)
        {
            printf("Fatal race condition(\n");
            exit(1);
        }

        if(!buf)
        {
            consumer_sleep = true;
            producer_sleep = false;
        }

        if(!consumer_sleep)
        {
            buf--;
            if(buf == rand() % MAXBUF) // Printing messages at random moments
                printf("Consuming\n");
        }
    }
}

int main()
{
    pthread_t p, c;

    pthread_create(&p, NULL, producer, &p);
    pthread_create(&c, NULL, consumer, &c);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
}
