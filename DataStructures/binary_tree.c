#include <stdio.h>
#include <stdlib.h>

// Representing a Node in the Binary Tree.
struct Node {
    int data;
    // Pointers to the left and right Nodes.
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    // Heap allocating the Node because Node data needs to exists outside of this function.
    struct Node* node = malloc(sizeof(struct Node));
    
    // Setting the required data and other Nodes to NULL.
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main() {
    // Initializing the Binary Tree and setting the required data in it.
    struct Node* root = newNode(100);
    root->left = newNode(2);
    root->right = newNode(50);
    root->right->left = newNode(2);
    root->right->right = newNode(25);
    root->right->right->left = newNode(5);
    root->right->right->right = newNode(5);

    // Printing out the Binary Tree.
    printf("Sample factor tree of 100 stored in a Binary Tree:\n");
    printf("Root     : %9d\n", root->data);
    printf("Branch[1]: %5d %5d\n", root->left->data, root->right->data);
    printf("Branch[2]: %8d %5d\n", root->right->left->data, root->right->right->data);
    printf("Branch[3]: %11d %5d\n", root->right->right->left->data, root->right->right->right->data);

    // Freeing the heap allocated memory. Not necessary for Binary Tree but is a good practice in C.
    // Freeing the Nodes from downwards so that Child Nodes are not lost.
    free(root->right->right->left);
    free(root->right->right->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
