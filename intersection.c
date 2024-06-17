#include "Header.h"
#include <stdio.h>
#include <stdlib.h>


set* intersection(set* set1, set* set2){
    set* result = set_create();
    if (set1 == NULL|| set2 == NULL){
        return result;
    }
    
    while (!set_empty(set1)){
        int val = set_choose(set1);
        set_remove(set1, val);
        if (set_contains(set2, val)){
            set_insert(result, val);
        }
    }return result;
}














// set* intersection(set* set1, set* set2){
//     setNode* curr1 = set1->first;
//     while (curr1 != NULL){
//         setNode* curr2 = set2->first;
//         int check = 0;
//         while (curr2 != NULL){
//             if (curr1->value == curr2->value){
//                 check = 1;
//                 break;
//             }
//             curr2 = curr2->next;
//         }setNode* hold = curr1; curr1 = curr1->next;
//         if (check ==0){
//             set_remove(set1, hold->value);
//         } 
//     }
// return set1;
// }

// int main() {
//     set* set1 = set_create();
//     set1->first = NULL;
//     set1->last = NULL;
//     set1->size = 0;
//     for (int i = 1; i <15; i++){
//         set_insert(set1, i);

//     }
//     set* set2 = set_create();
//     set2->first = NULL;
//     set2->last = NULL;
//     set2->size = 0;
//      for (int i = 1; i <6; i++){
//         set_insert(set2, i);
//     }

//     set* res = intersection(set1, set2);
//     setNode* curr = res->first;
//     while (curr != NULL){
//         printf("%d", curr->value);
//         curr = curr->next;
//     }
//     return 0;
// }