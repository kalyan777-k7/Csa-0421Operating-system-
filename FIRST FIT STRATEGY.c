#include <stdio.h>

int main() {
    int blocks[10], process[10], nb, np, i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter block sizes:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &blocks[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter process sizes:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &process[i]);

    for(i = 0; i < np; i++) {
        for(j = 0; j < nb; j++) {
            if(blocks[j] >= process[i]) {
                printf("Process %d allocated in block %d\n", i+1, j+1);
                blocks[j] -= process[i];
                break;
            }
        }
        if(j == nb)
            printf("Process %d not allocated\n", i+1);
    }
    return 0;
}
