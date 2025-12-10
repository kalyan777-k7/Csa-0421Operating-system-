#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int choice, fd;
    char fname[30], data[200];
    ssize_t n;

    while(1) {
        printf("\n--- FILE MANAGEMENT USING SYSTEM CALLS ---\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read File\n");
        printf("4. Append to File\n");
        printf("5. Delete File\n");
        printf("6. File Size Info\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 7) break;

        printf("Enter file name: ");
        scanf("%s", fname);

        switch(choice) {

            case 1:  // Create file
                fd = open(fname, O_CREAT | O_EXCL, 0644);
                if(fd < 0) printf("File already exists!\n");
                else printf("File created.\n");
                close(fd);
                break;

            case 2:  // Write
                fd = open(fname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
                printf("Enter text: ");
                scanf(" %[^\n]", data);
                write(fd, data, strlen(data));
                close(fd);
                printf("Write complete.\n");
                break;

            case 3:  // Read
                fd = open(fname, O_RDONLY);
                if(fd < 0) { printf("Cannot open file!\n"); break; }
                n = read(fd, data, sizeof(data)-1);
                data[n] = '\0';
                printf("File Content:\n%s\n", data);
                close(fd);
                break;

            case 4:  // Append
                fd = open(fname, O_WRONLY | O_APPEND);
                if(fd < 0) { printf("Cannot open file!\n"); break; }
                printf("Enter text to append: ");
                scanf(" %[^\n]", data);
                write(fd, data, strlen(data));
                close(fd);
                printf("Append complete.\n");
                break;

            case 5:  // Delete
                if(unlink(fname) == 0)
                    printf("File deleted.\n");
                else
                    printf("Error deleting file.\n");
                break;

            case 6:  // File size
                fd = open(fname, O_RDONLY);
                if(fd < 0) { printf("Cannot open file!\n"); break; }
                off_t size = lseek(fd, 0, SEEK_END);
                printf("File size = %ld bytes\n", size);
                close(fd);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
