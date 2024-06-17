#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"


set* set_create(){
    set* new_set = malloc(sizeof(set));
    new_set->size = 0;
    new_set->first = NULL;
    new_set->last = NULL;
    return new_set;
}

void set_delete(set* set){
    if (set == NULL){
        return;
    }
    setNode* curr = set->first;
    while (curr != NULL){
        setNode* hold = curr;
        curr = curr->next;
        free(hold);
     }free(set);
}

void set_insert(set* set, int value){
    setNode* new = malloc(sizeof(setNode));
    new->value = value;
    new->prev = NULL;
    new->next = NULL;

    if (set->first == NULL){
        set->first = new;
        set->last = new;
        set->size++;
    }
    else if (set->first->value > value){
        set->first->prev = new;
        new->next = set->first;
        set->first = new;
        set->size++;
    }
    else{
        setNode* current = set->first;
        setNode* prev = NULL;
        while (current != NULL){
            if (current->value == value){
                break;
            }
            else if (value < current->value){
                prev->next = new;
                new->next = current;
                new->prev = prev;
                set->size++;
                break;
            }
            else if (current->next == NULL){
                current->next = new;
                new->prev = current;
                set->last = new;
                set->size++;
            }
            prev = current;
            current = current->next;
        }
    }
}

void set_remove(set* set, int value){
    if (set->first == NULL){
        return;
    }else if (set->first->value == value){
        setNode* hold = set->first;
        set->first = set->first->next;
        set->size--;
        free(hold);
    }else{
        setNode* current = set->first;
        setNode* prev = NULL;

        while (current!= NULL){
            if (current->value == value){
                setNode* hold = current;
                prev->next = current->next;

                if (prev->next != NULL){
                    prev->next->prev = prev;
                    if (prev->next->next == NULL){
                        set->last = prev->next;
                    }
                }     
                set->size--;
                break;
                free(hold);
            }
            prev = current;
            current = current->next;
        }
    }
}

int set_choose(set* set){
    if (set->first == NULL){
        return -1;
    }else{
        int random_number;
        int minimum = 1;
        int maximum = set->size;
        random_number = rand() % (maximum - minimum+1) + minimum;
        int count =1;

        setNode* current = set->first;
        while (count <= random_number && current != NULL){
        if (count == random_number){
            return current->value;
        }
        count++;
        current = current->next;
        }
    }return 0;
}

int set_empty(set* set){
    if (set->first == NULL){
        return 1;
    }else return 0;
}

int set_contains(set* set, int value){
    setNode* current = set->first;
    while (current != NULL){
        if(current->value == value){;
        return 1;}
        current = current->next;
    }return 0;
}

// int main() {
//   set* a = set_create();
//   printf("%d\n", set_choose(a));
//   set_insert(a, 2);
//   set_insert(a, 2);
//   printf("%d\n", set_choose(a));
//   printf("%d\n", set_empty(a));
//   printf("%d\n", set_contains(a, 2));
//   printf("%d\n", set_contains(a, 3));
//   set_remove(a, 2);
//   printf("%d\n", set_empty(a));
//   set_delete(a);
//   return 0;
// }