#include <stdio.h>
#include <stdlib.h>

int* slice(int array[], int start, int end){
    int size = end - start;
    int* new_array = malloc(size * sizeof(int));
    for (int index = start; index < end; index++){
        new_array[index-start] = array[index];
    }
    return new_array;
}

int main(){
int array[] = {5, 2, 6, 1, 9, 4, 3};
int* hold = slice(array, 2, 5);
for (int idx = 0; idx < (5-2); idx++){
        printf("%d ", *(hold+idx));
        
        }
printf("\n");
return 0;
}
