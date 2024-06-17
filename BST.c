#include <stdio.h>
#include <stdlib.h>


typedef struct BSTNode{
    int value;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef struct BST{
    struct BSTNode* root;
    int counts;
} BST;


    
void insert(BST* bst, int val){
    BSTNode* new = malloc(sizeof(BSTNode));
    new->value = val;
    new->left = NULL;
    new->right = NULL;
    
    BSTNode* current = bst->root;
    if (bst->root == NULL){
        bst->root = new;
    }
    else{
        while (1){
            if (val < current->value){
                if (current->left == NULL){
                    current->left = new;
                    // free(new);
                    break;
                }
                current = current->left;
            }
            else if (val > current->value){
                if (current->right == NULL){
                    current->right = new;
                    // free(new);
                    break;
                }
                current = current->right;
            }
        else{
            return;
        }
        }}

    bst->counts++;
}


BSTNode* create_bst(int* array, int size){

    BST* new_tree = malloc(sizeof(BST));
    new_tree->counts = 0;

    for (int index = 0; index < size; index++){
        insert(new_tree, array[index]);
    }
return new_tree->root;
}

BSTNode* helper(BSTNode* node){
    if (node->left == NULL){
        return node;
    }
    return helper(node->left);
}


BSTNode* find_min(BSTNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

int remove_helper(BSTNode** node_ptr, int value) {
BSTNode* node = *node_ptr;
    if (node ==NULL) {
    return 0;
    }
    if (value <node->value) {
    return remove_helper(&(node->left), value);
    } else if (value > node->value) {
    return remove_helper(&(node->right), value);
    } else {
    if (node->left==NULL&&node->right==NULL) {
    // free(node);
    *node_ptr =NULL;
    } else if (node->left == NULL) {
    BSTNode* temp = node->right;
    // free(node);
    *node_ptr = temp;
    } else if (node->right == NULL) {
    BSTNode* temp = node->left;
    // free(node);
    *node_ptr = temp;
    } else {
    BSTNode* temp = find_min(node->right);
    node->value=temp->value;
    return remove_helper(&(node->right), temp->value);
    }
    return 1;
    }
}


int remove_(BST* tree, int value) {
if (tree ==NULL||tree->root==NULL) {
return 0;
}
return remove_helper(&(tree->root), value);
}


void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}


int main(){

    BSTNode two;
    BSTNode  sev;
    BSTNode four;
    two.left = NULL;
    two.right = NULL;
    sev.left = NULL;
    sev.right = NULL;

    two.value = 2;
    sev.value = 7;
    four.value = 4;
    four.left = &two;
    four.right = &sev;

    BST* tree = malloc(sizeof(BST));
    tree->root = &four;
    tree->counts = 3;

    int values[] = {3,6,9,11,20,21,23,24,25};

    for (int i = 0; i < 8; i++) {
        insert(tree, values[i]);
        tree->counts++;
    }
    insert(tree, 10);

    printf("Before removal: ");
    inorderTraversal(tree->root);
    printf("\n");
// inorderTraversal(tree->root);/
    remove_(tree, 2);
    remove_(tree,10);
    remove_(tree, 3);
    remove_(tree, 7);
    remove_(tree, 4);
    remove_(tree, 9);
    int test1 = remove_(tree, 100);
    int test2 = remove_(tree, 24);
    printf("%d\n%d\n", test1, test2);

    
    inorderTraversal(tree->root);
    // printf("->%d\n", g);
    return 0;
}