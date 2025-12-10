#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLower(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int main() {
    char filename[50], pattern[50], line[500], copy[500];
    FILE *fp;
    int line_no = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter text to search: ");
    scanf("%s", pattern);

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Unable to open file!\n");
        return 1;
    }

    // Convert pattern to lowercase
    char patternLower[50];
    strcpy(patternLower, pattern);
    toLower(patternLower);

    while (fgets(line, sizeof(line), fp)) {
        line_no++;

        strcpy(copy, line);
        toLower(copy);  // case-insensitive

        if (strstr(copy, patternLower)) {
            printf("%d: %s", line_no, line);
        }
    }

    fclose(fp);
    return 0;
}
