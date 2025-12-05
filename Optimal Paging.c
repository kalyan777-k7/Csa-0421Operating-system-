#include <stdio.h>

int main() {
    int pages[20], frame[10], n, f, i, j, k, faults = 0, found, far, pos;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);
    scanf("%d", &f);

    for (i = 0; i < f; i++) frame[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < f; j++)
            if (frame[j] == pages[i]) found = 1;

        if (!found) {
            if (i < f) frame[i] = pages[i];
            else {
                far = -1; pos = 0;
                for (j = 0; j < f; j++) {
                    for (k = i + 1; k < n; k++)
                        if (frame[j] == pages[k]) break;
                    if (k > far) {
                        far = k;
                        pos = j;
                    }
                }
                frame[pos] = pages[i];
            }
            faults++;
        }
    }
    printf("%d\n", faults);
    return 0;
}
