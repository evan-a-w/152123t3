#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *run_thread(void *data) {
    char *string = (char *)data;

    for (;;) {
        printf("%s", string);
    }

    return "Return string";
}

int main(void) {
    pthread_t thread_id1;
    if (pthread_create(&thread_id1, NULL, run_thread, "Hello ") != 0) {
        fprintf(stderr, "pthread_create failed\n");
        exit(1);
    }

    for (;;) {
        printf("there\n");
    }

    void *retval;
    if (pthread_join(thread_id1, &retval) != 0) {
        fprintf(stderr, "pthread_join failed\n");
        exit(1);
    }

    char *str = (char *)retval;
    printf("%s\n", str);
}
