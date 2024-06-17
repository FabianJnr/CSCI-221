#include <stdio.h>
#include <stdlib.h>

int* find_divisors(int array[], int size, int* dividents) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                continue;
            } else if (array[i] % array[j] == 0) {
                count++;
            }
        }
    }

    int* divisors = malloc(sizeof(int) * count);
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) continue;
            else if (array[i] % array[j] == 0) {
                dividents[index] = array[i];
                divisors[index] = array[j];
                index++;
            }
        }
    }
    return divisors;
}

int main() {
    int array[] = {2, 5, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int* dividents = malloc(sizeof(int) * size); 
    int* divisors = find_divisors(array, size, dividents);
    
    for (int idx = 0; idx < 2; idx++) {
        printf("%d -> %d\n", dividents[idx], divisors[idx]);
    }

    free(dividents);
    free(divisors);

    return 0;
}