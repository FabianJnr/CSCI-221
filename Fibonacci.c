#include <stdio.h>
#include <stdlib.h>

int fibonacci(int target){
    if (target == 1){
        return 1;
    }
    else if (target == 0){
        return 0;
    }
    return fibonacci(target-2) + fibonacci(target-1);
return 0;
}


int main(int argc, char *argv[]){
    int target;
    target = atoi(argv[1]);
    printf("%d\n", fibonacci(target));
    return 0;
}