#include <stdio.h>
#include <string.h>

int main() {
    char dir[10][20], name[20];
    int n, i, flag;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter file name: ");
        scanf("%s", name);
        flag = 0;

        for(int j=0; j<i; j++)
            if(strcmp(dir[j], name) == 0)
                flag = 1;

        if(flag)
            printf("File already exists!\n");
        else
            strcpy(dir[i], name);
    }

    printf("\nDirectory Files:\n");
    for(i=0; i<n; i++)
        printf("%s\n", dir[i]);

    return 0;
}
