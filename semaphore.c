#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct __counter_t {
    int value;
    sem_t semaphore;
} counter_t;

unsigned int loop_cnt;
counter_t counter;

void init(counter_t *c) {
    c->value = 0;
    sem_init(&c->semaphore, 0, 1);
}

void increment(counter_t *c) {
    sem_wait(&c->semaphore);
    c->value++;
    sem_post(&c->semaphore);
}

void decrement(counter_t *c) {
    sem_wait(&c->semaphore);
    c->value--;
    sem_post(&c->semaphore);
}

int get(counter_t *c) {
    sem_wait(&c->semaphore);
    int rc = c->value;
    sem_post(&c->semaphore);
    return rc;
}

void *mythread(void *arg)
{
    char *letter = arg;
    int i;

    printf("%s: begin\n", letter);
    for (i = 0; i < loop_cnt; i++) {
        increment(&counter);
    } 
    printf("%s: done\n", letter);
    return NULL;
}
                                                                             
int main(int argc, char *argv[])
{                    
    loop_cnt = atoi(argv[1]);

    init(&counter);

    pthread_t p1, p2;
    printf("main: begin [counter = %d]\n", get(&counter));
    pthread_create(&p1, NULL, mythread, "A"); 
    pthread_create(&p2, NULL, mythread, "B");
    // join waits for the threads to finish
    pthread_join(p1, NULL); 
    pthread_join(p2, NULL);
    printf("main: done [counter: %d] [should be: %d]\n", get(&counter), loop_cnt * 2);

    return 0;
}
