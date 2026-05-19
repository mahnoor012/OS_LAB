#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

void getFileType(char *filename, struct stat s) {

    printf("\nFile Type (OS Level): ");

    if (S_ISREG(s.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(s.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(s.st_mode))
        printf("Symbolic Link\n");
    else
        printf("Other\n");

    // extension based type
    printf("File Type (Extension Based): ");

    char *ext = strrchr(filename, '.');

    if (ext == NULL)
        printf("Unknown (No extension)\n");
    else if (strcmp(ext, ".txt") == 0)
        printf("Text File (.txt)\n");
    else if (strcmp(ext, ".c") == 0)
        printf("C Program File (.c)\n");
    else if (strcmp(ext, ".log") == 0)
        printf("Log File (.log)\n");
    else
        printf("Other (%s)\n", ext);
}

int main() {

    char filename[100];
    struct stat s;

    // user input
    printf("Enter file name: ");
    scanf("%s", filename);

    // stat check
    if (stat(filename, &s) == -1) {
        printf("Error: File not found!\n");
        return 1;
    }

    // file info
    printf("\n--- File Information ---\n");

    printf("File Size: %ld bytes\n", s.st_size);
    printf("Inode Number: %ld\n", s.st_ino);
    printf("Device ID: %ld\n", s.st_dev);
    printf("Number of Links: %ld\n", s.st_nlink);
    printf("User ID: %d\n", s.st_uid);
    printf("Group ID: %d\n", s.st_gid);
    printf("Block Size: %ld\n", s.st_blksize);
    printf("Number of Blocks: %ld\n", s.st_blocks);

    printf("Last Access Time: %s", ctime(&s.st_atime));
    printf("Last Modification Time: %s", ctime(&s.st_mtime));
    printf("Last Status Change Time: %s", ctime(&s.st_ctime));

    // permission check
    printf("\n--- Permissions ---\n");

    printf("Owner - Read: %s\n", (s.st_mode & S_IRUSR) ? "Yes" : "No");
    printf("Owner - Write: %s\n", (s.st_mode & S_IWUSR) ? "Yes" : "No");
    printf("Owner - Execute: %s\n", (s.st_mode & S_IXUSR) ? "Yes" : "No");

    // file type
    getFileType(filename, s);

    return 0;
}
