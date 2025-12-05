#include <stdio.h>
#include <pthread.h>

void* run(void* arg) {
    printf("Thread %d running\n", *(int*)arg);
}

int main() {
    pthread_t t[3];
    int id[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, run, &id[i]);
    for (int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);
    return 0;
}
