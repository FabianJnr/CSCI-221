#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void multiply_overflow(uint32_t x, uint32_t y, uint32_t* result_upper, uint32_t* result_lower) {
uint16_t x_left = x & 0xFFFF;
uint16_t x_right = (x >> 16) & 0xFFFF;
uint16_t y_left = y & 0xFFFF;
uint16_t y_right = (y >> 16) & 0xFFFF;
uint32_t left_product = x_left * y_left;
uint32_t middle_product = x_left * y_right + x_right * y_left;
uint32_t right_product = x_right * y_right;
middle_product += left_product >> 16;
right_product += middle_product >> 16;
*result_lower = (left_product & 0xFFFF) | ((middle_product & 0xFFFF) << 16);
*result_upper = right_product;
}

int main(){

    uint32_t ru , rl;
    multiply_overflow(0x05D2, 0x720AF4E0, &ru, &rl);
    printf("%x\n", (ru));
    printf("%x\n", rl);
    return 0;
}