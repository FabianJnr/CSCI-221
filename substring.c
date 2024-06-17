#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

char* copy_substring(char* string, int start, int end){
    char* new_string = malloc((end-start-1) * sizeof(int));
    int count = 0;
    for (int i = start; i <= end; i++){
        if (i == end){
            new_string[count] = '\0';
            break;
        }
        new_string[count] = string[i];
        count++;
    }
return new_string;
}

// int main(){
// // char* test_1 = copy_substring("string", 1, 3);
// // char* test_2 = copy_substring("hello", 0, 3);
// char* test_3 = copy_substring("hello", 4, 5);
// for (int i = 0; i<=5; i++){
//         printf("%c", *(test_3+i));
//     }printf("\n");
// return 0;
// }