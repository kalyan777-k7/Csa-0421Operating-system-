#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void print_permissions(mode_t m) {
    printf( (m & S_IRUSR) ? "r" : "-");
    printf( (m & S_IWUSR) ? "w" : "-");
    printf( (m & S_IXUSR) ? "x" : "-");
    printf( (m & S_IRGRP) ? "r" : "-");
    printf( (m & S_IWGRP) ? "w" : "-");
    printf( (m & S_IXGRP) ? "x" : "-");
    printf( (m & S_IROTH) ? "r" : "-");
    printf( (m & S_IWOTH) ? "w" : "-");
    printf( (m & S_IXOTH) ? "x" : "-");
}

int main() {
    DIR *d;
    struct dirent *de;
    struct stat st;

    d = opendir(".");
    if (!d) return 1;

    while ((de = readdir(d)) != NULL) {
        stat(de->d_name, &st);

        // file type
        printf(S_ISDIR(st.st_mode) ? "DIR " : "FILE ");

        // permissions
        print_permissions(st.st_mode);
        printf(" ");

        // size
        printf("%5ld ", st.st_size);

        // file name
        printf("%s\n", de->d_name);
    }

    closedir(d);
    return 0;
}
