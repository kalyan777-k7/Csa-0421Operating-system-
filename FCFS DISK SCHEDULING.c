#include <stdio.h>

int main() {
    int queue[20], n, head, i, distance = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++) {
        distance += abs(head - queue[i]);
        head = queue[i];
    }

    printf("Total head movement = %d\n", distance);
    return 0;
}
