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


BSTNode* find_min(BSTNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

int remove_helper(BSTNode** node_ptr, int value) {
    BSTNode* node = *node_ptr;
    if (node == NULL) {
        return 0;
    }

    if (value < node->value) {
        return remove_helper(&(node->left), value);
    } else if (value > node->value) {
        return remove_helper(&(node->right), value);
    } else {
        if (node->left == NULL && node->right == NULL) {
            // free(node);
            *node_ptr = NULL;
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
            node->value = temp->value;
            return remove_helper(&(node->right), temp->value);
        }
        return 1;
    }
}

int remove_(BST* tree, int value) {
    if (tree == NULL || tree->root == NULL) {
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

/*White-Box Testing

1.  TEST_1: This first test is to check the first if block in the remove helper function for the remove function. The input is an empty tree
            and an integer. I chose it because it is checking how the function behaves when an empty tree is passed in as an input. 
            It should output zero as an indicator that the value was not found and most importantly not removed, since the tree itself was 
            empty.

            BST* test_1 = malloc(sizeof(BST));
            test_1->root = NULL;
            test_1->counts = 0;
            int res = remove_(test_1, 4);
            printf("%d\n", res);
            inorderTraversal(test_1->root);

2.  TEST_2: This test is specifically for the second if block in the remove helper function. The inputs is a fully filled tree with it's 
            root having both right and left subtrees and an integer which is the value of the root of the tree. 
            I chose this to check how the function behaves when the value to be removed is the the root of the tree. 
            I want to see if does maintain the right structure of the tree after remving it. 
            The output should be 1, indicating the value was found removed successfully. And I would also like to see the structure of the 
            tree been maintained after that deletion.
            
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
            int res = remove_(tree, 4);  printf("%d\n", res);inorderTraversal(tree->root);

3.  TEST_3: This is to test removing a root node, with no children, when the value giving is equal to its value. The input is a tree with 
            a single node containing the value to be removed, which is equal to the root node's value.
            After deletion, the root should be set to NULL and the function should return 1.
            I chose this to test if the function correctly handles removing the root node when it has no children.
            This covers the second else if block in the else block of the remove helper function.

            BSTNode two;
            two.left = NULL;
            two.right = NULL;
            two.value = 2;
            BST* test_1 = malloc(sizeof(BST));
            test_1->root = &two;
            test_1->counts = 1;
            int res = remove_(test_1, 2);
            printf("%d\n", res);
            inorderTraversal(test_1->root);

4. TEST_4:  This tests removing a leaf node, whose value is the one to be removed. The input is a tree with multiple nodes and the value to 
            be removed is a leaf node. The expected output is 1, indicating that vlaue's node is succesfully removed from the tree. 
            I chose tohis to test if the function correctly handles removing a leaf node.

5. TEST_5:  This test checks for removing a value's node with only a right child. This checks the if block in the else block of the 
            remove helper function. The input is a tree with multiple nodes, and the value to be removed is a node with only a right child.
            The output should be 1 and the right child of the node should become the child of the node's parent.
            I chose this to test if the function correctly handles removing a node with only a right child.

6. TEST_6:  This is to test removing a value's node with only left child. This is also checkig the first else if block in the else block of
            remove helper function. The input is a tree with multiple nodes, and the value to be removed is a node with only a left child.
            The expected output is 1 and the left child of the node should become the child of the node's parent.
            This is testing if the function correctly handles removing a node with only a left child. 

7. TEST_7:  This is a test for checking when removing a node with both children. This is also checking the else block in the else block of 
            the remove function. The input is a tree with multiple nodes, and the value to be removed is a node with both left and right 
            children. The expected output is 1 and the right subtree should become the subtree of the node's parent, with the left subtree 
            attached to the leftmost leaf node of the right subtree. I chose this to test if the function correctly handles removing a 
            node with both left and right children.

8. TEST_8:  This test checks when removing a value that is not in the tree. The input is a tree with multiple nodes, and the value to be 
            removed does not exist in the tree. The function should return 0, indicating that the value was not found in the tree.
            I chose this to test how the function handles the case where the value to be removed does not exist in the tree.

            */


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

    // BST* test_1 = malloc(sizeof(BST));
    // test_1->root = &two;
    // test_1->counts = 1;
    // int res = remove_(test_1, 2);
    // printf("%d\n", res);
    // inorderTraversal(test_1->root);

    // int values[] = {3,6,9,13,23,34,35,36,37,38,39,40,41,42,43};

    // for (int i = 0; i < 15; i++) {
    //     insert(tree, values[i]);
    // }
    // insert(tree, 10);
    // insert(tree, 1);
    // insert(tree, 5);
    // insert(tree, 8);

    // printf("Before removal: ");
    // inorderTraversal(tree->root);
    // printf("\n");

    // remove_(tree, 2);
    // remove_(tree,10);
    // remove_(tree, 3);
    // remove_(tree, 7);
    // remove_(tree, 4);
    // remove_(tree, 9);
    // printf("\nAfter removal: ");
    // inorderTraversal(tree->root);
    // printf("\n");

    int value[] = {3,6,9,11,20,21,23,24,25};

    for (int i = 0; i < 8; i++) {
        insert(tree, value[i]);
    }
    insert(tree, 10);

    printf("Before removal: ");
    inorderTraversal(tree->root);
    printf("\n");

    int test = remove_(tree, 2);
    int tes1 = remove_(tree, 100);
    printf("%d\n", tes1);
    remove_(tree,10);
    remove_(tree, 3);
    remove_(tree, 7);
    remove_(tree, 4);
    remove_(tree, 9);
    remove_(tree, 23);
    remove_(tree, 6);
    remove_(tree, 21);
    remove_(tree, 11);
    remove_(tree, 24);
    // remove_(tree, 20);
    printf("%d\n", test);
    inorderTraversal(tree->root);
    printf("\n");
    return 0;
}