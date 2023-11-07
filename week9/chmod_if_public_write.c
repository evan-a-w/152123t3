#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

void chmod_if_public_write(char *path) {
    // assess if the file is publically writeable
    struct stat stat_buf;
    if (stat(path, &stat_buf) != 0) {
        perror(path);
        exit(EXIT_FAILURE);
    }

    if ((stat_buf.st_mode & 0b10) == 0) {
        printf("%s is not publically writable\n", path);
        return;
    }

    // mask should be all 1s EXCEPT the 1st (0 indexed) bit
    unsigned int mode = stat_buf.st_mode & ~0b10;

    // 0 ^ 1 1
    // 1 ^ 1 0
    mode_t _mode = stat_buf.st_mode ^ 0b10;

    if (chmod(path, mode) != 0) {
        perror(path);
        exit(EXIT_FAILURE);
    }

    printf("removing public write from %s which is a %s\n", path,
           (S_ISDIR(mode) ? "directory" : "regular_file"));
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        chmod_if_public_write(argv[i]);
    }

    return 0;
}
