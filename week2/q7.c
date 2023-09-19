// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.
    for (int x = 24; x < 42; x += 3) {
        printf("%d\n", x);
    }

    int x = 24;
    while (x < 42) {
        printf("%d\n", x);

        x += 3;
    }

    int y = 24;
loop_begin:
loop_condition:
    if (y >= 42)
        goto loop_end;
loop_body:
    printf("%d\n", y);
loop_step:
    y += 3;
    goto loop_begin;
loop_end:

    return 0;
}
