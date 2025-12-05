#include <stdio.h>

int main() {
    int alloc[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    int max[5][3]   = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int avail[3]    = {3,3,2};
    int finish[5] = {0}, need[5][3], safe[5];
    int i, j, k, count = 0, flag;

    for (i = 0; i < 5; i++)
        for (j = 0; j < 3; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    while (count < 5) {
        for (i = 0; i < 5; i++) {
            if (!finish[i]) {
                flag = 1;
                for (j = 0; j < 3; j++)
                    if (need[i][j] > avail[j])
                        flag = 0;
                if (flag) {
                    for (k = 0; k < 3; k++)
                        avail[k] += alloc[i][k];
                    safe[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    for (i = 0; i < 5; i++)
        printf("P%d ", safe[i]);

    return 0;
}
