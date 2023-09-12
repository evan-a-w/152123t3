#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("argc=%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }

    // for (INITIALISATION; CONDITION; STEP) {
    //     BODY;
    // }
    // INITIALIZATION;
    // while (CONDITION) {
    //     BODY;
    //     step;
    // }

    int i = 0;
    while (i < argc) {
        printf("argv[%d]=%s\n", i, argv[i]);
      
	i++;
    }

    return 0;
}
