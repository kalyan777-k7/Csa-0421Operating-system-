#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("Before fork\n");

    pid = fork(); // create new process

    if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
