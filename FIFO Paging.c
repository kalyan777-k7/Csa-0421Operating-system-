#include <stdio.h>

int main() {
    int pages[20], frame[10], n, f, i, j, k = 0, faults = 0, found;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);
    scanf("%d", &f);

    for (i = 0; i < f; i++) frame[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < f; j++)
            if (frame[j] == pages[i]) found = 1;

        if (!found) {
            frame[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }
    }
    printf("%d\n", faults);
    return 0;
}
