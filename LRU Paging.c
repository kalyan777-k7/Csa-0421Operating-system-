#include <stdio.h>

int main() {
    int pages[20], frame[10], count[10], n, f, i, j, faults = 0, min, pos, found;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);
    scanf("%d", &f);

    for (i = 0; i < f; i++) frame[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < f; j++)
            if (frame[j] == pages[i]) {
                found = 1;
                count[j] = i;
            }
        if (!found) {
            if (i < f) frame[i] = pages[i];
            else {
                min = count[0]; pos = 0;
                for (j = 1; j < f; j++)
                    if (count[j] < min) {
                        min = count[j];
                        pos = j;
                    }
                frame[pos] = pages[i];
            }
            count[pos] = i;
            faults++;
        }
    }
    printf("%d\n", faults);
    return 0;
}
