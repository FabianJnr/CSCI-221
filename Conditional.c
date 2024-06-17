#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>

int condition (int x, int y, int z) {
    x = (x!= 0);
    return ((-x & y) | (~x & z));
}


int main(){
    int res = condition(0,2,3);
    printf("%d\n", res);
    return 0;
}