#include <stdio.h>
#include <stdint.h>

int main() {
    // 16 1s
    int16_t x = -1;
    // 16 1s
    uint16_t z = x;
    // 32 1s
    // sign extension
    // - it fills the leftover space with whatever the sign is
    uint32_t y = x;
    printf("%u %u\n", y, z);

    int16_t a = 10;
    uint16_t b = a;
    uint32_t c = a;
    printf("%u %u\n", b, c);
    // BE CAREFUL OF THIS

    double fl = 1.501234013;
    int i = fl; // i == 1
}
