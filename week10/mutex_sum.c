#include <stdio.h>
#include <pthread.h>

pthread_mutex_t global_total_lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t global_total_lock2 = PTHREAD_MUTEX_INITIALIZER;
int global_total = 0;

void *add_5000_to_counter(void *data) {
    for (int i = 0; i < 50000; i++) {
        pthread_mutex_lock(&global_total_lock1);
        // pthread_mutex_lock(&global_total_lock2);

        // nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);

        // increment the global total by 1
        global_total++;


        pthread_mutex_unlock(&global_total_lock1);
        // pthread_mutex_unlock(&global_total_lock2);
    }

    return NULL;
}

void *add_5000_to_counter2(void *data) {
    for (int i = 0; i < 50000; i++) {
      // pthread_mutex_lock(&global_total_lock2);
        pthread_mutex_lock(&global_total_lock1);

        // nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);

        // increment the global total by 1
        global_total++;


        pthread_mutex_unlock(&global_total_lock1);
        // pthread_mutex_unlock(&global_total_lock2);
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_5000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_5000_to_counter2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // if program works correctly, should print 10000
    printf("Final total: %d\n", global_total);
}
