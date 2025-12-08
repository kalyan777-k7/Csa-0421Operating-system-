#include <stdio.h>
#include <string.h>

int main() {
    char user[10][20], files[10][10][20];
    int u, f, i, j;

    printf("Enter number of users: ");
    scanf("%d", &u);

    for(i = 0; i < u; i++) {
        printf("Enter user name: ");
        scanf("%s", user[i]);

        printf("Enter number of files for %s: ", user[i]);
        scanf("%d", &f);

        for(j = 0; j < f; j++) {
            printf("Enter file name: ");
            scanf("%s", files[i][j]);
        }
    }

    printf("\nTwo Level Directory:\n");
    for(i = 0; i < u; i++) {
        printf("User: %s\n", user[i]);
        for(j = 0; j < f; j++)
            printf("  %s\n", files[i][j]);
    }
    return 0;
}
