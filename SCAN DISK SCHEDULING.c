#include <stdio.h>

int main() {
    int queue[20], n, head, i, j, temp, distance = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter requests:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    // Sort requests
    for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }

    // SCAN
    for(i = 0; i < n; i++)
        if(queue[i] >= head) break;

    for(j = i; j < n; j++) {
        distance += abs(head - queue[j]);
        head = queue[j];
    }

    for(j = i-1; j >= 0; j--) {
        distance += abs(head - queue[j]);
        head = queue[j];
    }

    printf("Total head movement = %d\n", distance);
    return 0;
}
