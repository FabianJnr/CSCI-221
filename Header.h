#ifndef _HEADER_H_3_
#define _HEADER_H_3_

/*This is a substring function that copies a part of a string and returns it*/
char* copy_substring(char* string, int start, int end);

/*Sets implementations*/

/*this creates a node for an element in a set*/
// typedef struct setNode setNode;
typedef struct setNode{
    int value;
    struct setNode* next;
    struct setNode* prev;
}setNode;

/*this creates a whole set*/
// typedef struct set set;

typedef struct set{
    int size;
    struct setNode* first;
    struct setNode* last;
}set;


/*this function creates a new_set*/
set* set_create();

/*this function deletes a set*/
void set_delete(set* set);

/*this function adds a new element to a set*/
void set_insert(set* set, int value);

/*this function removes an element from a set*/
void set_remove(set* set, int value);

/*this function returns an arbitrary number from a set*/
int set_choose(set* set);

/*this function checks whether a set is empty or not*/
int set_empty(set* set);

/*this function checks whether an element is in a set*/
int set_contains(set* set, int value);

/*this function returns the intersection of two sets*/
set* intersection(set* set1, set* set2);

#endif 