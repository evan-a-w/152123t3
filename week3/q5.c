// A simple program that will read 10 numbers into an array

#define N_SIZE 10

#include <stdio.h>

int numbers[N_SIZE] = {0};

int main(void) {
    int i;

    i = 0;
    while (i < N_SIZE) {
        scanf("%d", &numbers[i]);
        i++;

        for (int j = 0; j < i; j++) {
            printf("%d ", numbers[j]);
        }
	printf("\n");
    }
}
