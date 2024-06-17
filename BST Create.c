#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
  int value;
  struct BSTNode* left;
  struct BSTNode* right;
} BSTNode;

typedef struct BST {
  int size;
  struct BSTNode* root;
} BST;

/*  I first compiled the file with these flags on: -Wall -Wextra -Werror, and found a bug which was about uninitialized variable.
    So it was basically the tree in createBST that was not initialized. Also, by logically analyzing the while loop statment, I see it will
    break, using the ||, when either of the conditions becomes True. So I replaced it with &&   */

void addnode(BST* inputTree, int value) {
  
  if (inputTree->root == NULL) {
    BSTNode* newnode = malloc(sizeof(BSTNode));
    newnode->value = value;
    newnode->left = NULL; 
    newnode->right = NULL;
    inputTree->root = newnode;
  } else {
    BSTNode* ptr = inputTree->root;
    while (ptr != NULL && ptr->value != value){
      if (value > ptr->value){
        if (ptr->right == NULL){
          BSTNode* newnode = malloc(sizeof(BSTNode));
          newnode->value = value;
          newnode->left = NULL; 
          newnode->right = NULL;
          ptr->right = newnode;
          break;
        }
        ptr = ptr->right;
      } else if (value < ptr->value) {
        if (ptr->left == NULL){
          BSTNode* newnode = malloc(sizeof(BSTNode));
          newnode->value = value;
          newnode->left = NULL; 
          newnode->right = NULL;
          ptr->left = newnode;
          break;
        }
        ptr = ptr->left;
      } else {
        return;
      }
    }
  }
  inputTree->size++;
}

BST* createBST(int array[], int size){
  BST* tree = malloc(sizeof(BST));
  tree->root = NULL;
  tree->size = 0;
  for (int i=0; i < size; i++) {
    addnode(tree, array[i]);
  }
  return tree;
}

void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d,", root->value);
        inorderTraversal(root->right);
    }
}

int main(){
    
    int array[] = {11,1,12,2,10,3,4,13,5,6,15,7,8,14,9};
    BST* res = createBST(array, 15);
    inorderTraversal(res->root);
    
    printf("\n");
    printf("%d\n", res->size);
    return 0;
}