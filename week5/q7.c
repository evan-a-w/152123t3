#include <stdint.h>
#include <stdio.h>

#define NUM_BITS 32

uint32_t reverse_bits(uint32_t x) {
    uint32_t res = 0;

    // read ith bit and set <> in the result
    // 0  <->  31
    // 1  <->  30
    // i  <->  31 - i
    // i  <-> NUM_BITS - 1 - i
    for (uint32_t i = 0; i < NUM_BITS; i++) {
        uint32_t res_i = NUM_BITS - 1 - i;
        uint32_t curr_bit = x & (1 << i); // x & (1 and then i zeros)
	curr_bit >>= i; // curr_bit = 0 or 1 depending on the ith bit

	res = res | curr_bit << res_i;
    }

    return res;
}

int main(void) {
    uint32_t x = 0x01234567;
    printf("0x%x\n", reverse_bits(x));
}
