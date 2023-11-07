#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_and_print(FILE *stream, char *search_string) {
    char *line = NULL;
    size_t line_sz = 0;

    size_t line_no = 1;
    while (getline(&line, &line_sz, stream) != -1) {
        // printf line iff search string is in line
        // line = hello my name is evan
        // search_string = my
        // print in this case

        if (strstr(line, search_string) != NULL) {
            printf("line %lu at offset %ld: %s", line_no, ftell(stream), line);
        }

	// fseek(stream, 0, SEEK_END);
	// ftell(stream); // size of file

        line_no++;
    }

    free(line);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <search_string> [filename ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *search_string = argv[1];

    if (argc == 2) {
        search_and_print(stdin, search_string);
        return 0;
    }

    for (int i = 2; i < argc; i++) {
        char *curr_path = argv[i];
        // ALWAYS NEED TO CHECK FOPEN
        FILE *stream = fopen(curr_path, "r");
        if (stream == NULL) {
            perror(curr_path);
	    exit(1);
        }

        printf("Searching %s\n", curr_path);
        search_and_print(stream, search_string);
        fclose(stream);
    }

    return 0;
}
