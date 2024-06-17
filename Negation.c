#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t negation(int32_t value){
    return ~value + 1;
}

int main(){
    int32_t res = negation(234);
    printf("%d\n", res);
    return 0;
} 