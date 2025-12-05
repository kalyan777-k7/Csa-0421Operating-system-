#include <stdio.h>

int main() {
    int files[100] = {0}, start, length, i, flag;

    while (1) {
        scanf("%d", &start);
        scanf("%d", &length);
        flag = 1;

        for (i = start; i < start + length; i++)
            if (files[i] == 1) flag = 0;

        if (flag) {
            for (i = start; i < start + length; i++)
                files[i] = 1;
            printf("Allocated\n");
        } else {
            printf("Not Allocated\n");
        }
    }
}
