#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    char *home = getenv("HOME");
    if (home == NULL) {
        fprintf(stderr, "$HOME does not exist\n");
        return 1;
    }

    int size = strlen("/.diary") + strlen(home) + 1;
    char *path = malloc(size);
    sprintf(path, "%s/.diary", home);

    // find some information about the diary
    struct stat stat_buf;
    if (stat(path, &stat_buf) != 0) {
        perror(path);
    }

    printf("Size of diary: %lu\n", stat_buf.st_size);

    FILE *f = fopen(path, "r");
    if (f == NULL) {
        perror(path);
        return 1;
    }

    int c;
    while ((c = fgetc(f)) != EOF) {
        fputc(c, stdout);
    }

    free(path);
    return 0;
}
