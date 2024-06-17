#include <stdio.h>
#include "Header.h"
// #include "sets.c"

int main(){
char* test_1 = copy_substring("string", 1, 3);
// char* test_2 = copy_substring("hello", 0, 3);
// char* test_3 = copy_substring("hello", 4, 5);
for (int i = 0; i<=5; i++){
        printf("%c", *(test_1+i));
    }printf("\n");


set* a = set_create();
printf("%d\n", set_choose(a));
set_insert(a, 2);
set_insert(a, 2);
printf("%d\n", set_choose(a));
printf("%d\n", set_empty(a));
printf("%d\n", set_contains(a, 2));
printf("%d\n", set_contains(a, 3));
set_remove(a, 2);
printf("%d\n", set_empty(a));
set_delete(a);

set* set1 = set_create();
    // set1->first = NULL;
    // set1->last = NULL;
    // set1->size = 0;
    for (int i = 1; i <20; i++){
        set_insert(set1, i);

    }
set_delete(NULL);
// setNode* cur = set1->first;

// while (cur != NULL){
//         printf("%d\n", cur->value);
//         cur = cur->next;
//     }
    set* set2 = set_create();
    // set2->first = NULL;
    // set2->last = NULL;
    // set2->size = 0;
     for (int i = 1; i <15; i++){
        set_insert(set2, i);
    }

    set* res = intersection(set1, set2);
    // intersection(set1, set2);
    setNode* curr = res->first;
    while (curr != NULL){
        printf("%d ", curr->value);
        curr = curr->next;
    }
// set_delete(set1);
setNode* cur = set1->first;
while (cur != NULL){
        printf("%d \n", cur->value);
        cur = cur->next;
    }
return 0;
}