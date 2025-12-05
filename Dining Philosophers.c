#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t chopstick[5];

void *philosopher(void *n) {
    int i = *(int *)n;
    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i + 1) % 5]);
    printf("Philosopher %d eating\n", i);
    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i + 1) % 5]);
    printf("Philosopher %d done\n", i);
}

int main() {
    pthread_t t[5];
    int i, n[5];

    for (i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);

    for (i = 0; i < 5; i++) {
        n[i] = i;
        pthread_create(&t[i], NULL, philosopher, &n[i]);
    }

    for (i = 0; i < 5; i++)
        pthread_join(t[i], NULL);

    return 0;
}
