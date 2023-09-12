#include <stdio.h>

char s1[10] = "def";

int main(void) {
    char *s2 = "def";
    char s3[] = "def";
    s3[0] = 'a';
}
