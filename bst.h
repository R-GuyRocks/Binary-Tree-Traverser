/**********************************************
* bst.h
***********************************************
* This header file contains method declarations
* for all of the methods in the bst.c class.
***********************************************/

#ifndef SMITHR_P2_BST_H
#define SMITHR_P2_BST_H

typedef struct Node {
    int key;
    struct Node *rightNode;
    struct Node *leftNode;
} node;

struct Node* makeNode (int key);

struct Node* insert(struct Node* nodePtr, int key);

int searchTree(struct Node* root, int key);

void releaseMemory(struct Node* root);

char* inorderTraversal(struct Node* root);

int findSmallest(struct Node* node);

void deleteNode(struct Node* root, int num);

int deleteRoot(struct Node* root);

#endif //SMITHR_P2_BST_H