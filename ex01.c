#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* job(void* id){
    printf("Hello from thread %d \n", *(int*) id);
    pthread_exit(NULL);
}
int main(){
 for(int i = 0; i < 6; i++)
 {
     pthread_t thread_id;
     pthread_create(&thread_id, NULL, job, &i);
     printf("Thread number %d has been created\n" ,i);
     pthread_join(thread_id, NULL);
 }
}
