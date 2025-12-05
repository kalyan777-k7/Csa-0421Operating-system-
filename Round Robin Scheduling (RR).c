#include <stdio.h>

int main() {
    int n, bt[20], rem[20], tq, time = 0, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    printf("\nGantt Chart: ");

    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0;

                if (rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    rem[i] = 0;
                }

                printf(" P%d ", i + 1);
            }
        }
        if (done) break;
    }

    printf("\nTotal Time = %d\n", time);
    return 0;
}
