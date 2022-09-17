/**********************************************
* bst.c
***********************************************
* This class contains methods that represent
* the behavior of a binary search tree. It provides
* implementation for allocating space to new nodes,
* inserting a node into the tree, searching for a node
* in the tree, freeing up memory in the tree, and doing
* an inorder traversal through the tree. *
***********************************************/

#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

/**********************************************
* Input: The key which the user wants to put into the node. *
* Output: The newly created node. *
* Pre-condition: The user must enter 'i' when prompted to enter an option, and the node
* of the tree when iterating through the insert function must be null. *
* Post-condition: The newly created node must not be null. *
***********************************************/
struct Node* makeNode (int key) {
    struct Node *newNode;
    newNode = malloc(sizeof(node));
    newNode->key = key;
    newNode->rightNode = NULL;
    newNode->leftNode = NULL;
    return newNode;
}

/**********************************************
* Input: A pointer pointing to the root node of the tree, and a number that
* the user wants to insert into the tree. *
* Output: The root of the tree, or the other nodes in the tree if the program
* isn't on the first iteration. *
* Pre-condition: The user must enter 'i' when prompted to enter an option. *
* Post-condition: The number must be inserted into the tree. *
***********************************************/
struct Node* insert(struct Node* nodePtr, int key) {
    if (nodePtr == NULL) {
        nodePtr = makeNode(key);
        return nodePtr;
    }
    else {
        if (key < nodePtr->key) {
            nodePtr->leftNode = insert(nodePtr->leftNode, key);
        }
        else if (key > nodePtr->key) {
            nodePtr->rightNode = insert(nodePtr->rightNode, key);
        }
        return nodePtr;
    }
}

/**********************************************
* Input: A node which represents the root of the tree upon the first iteration,
* and the integer the user wants to search the tree for. *
* Output: The number the user wants search the tree for, or 0 if that number
* wasn't found. *
* Pre-condition: The user must enter 's' when prompted to enter an option. *
* Post-condition: The number must be searched for in the tree. *
***********************************************/
int searchTree(struct Node* root, int key)
{
    if (root == NULL) {
        return 0;
    }
    else if (root->key == key) {
        return root->key;
    }
    else if (root->key > key) {
        return searchTree(root->leftNode, key);
    }
    else {
        return searchTree(root->rightNode, key);
    }
}

/**********************************************
* Input: A node which represents the root of the tree upon the first iteration. *
* Output: There is no output. The memory for each node in the tree is freed. *
* Pre-condition: The user must enter 'q' when prompted to enter an option. *
* Post-condition: The memory for each node must be freed. *
***********************************************/
void releaseMemory(struct Node* root) {
    if (root->leftNode != NULL) {
        releaseMemory(root->leftNode);
    }
    if (root->rightNode != NULL) {
        releaseMemory(root->rightNode);
    }
    free(root);
    root = NULL;
}

/**********************************************
* Input: A node which represents the root of the tree upon the first iteration. *
* Output: A character pointer which represents the result of doing an inorder traversal
* on the tree. *
* Pre-condition: The user must enter 't' when prompted to enter an option. *
* Post-condition: An inorder traversal of the tree must be shown to the user. *
***********************************************/
char* inorderTraversal(struct Node* root) {
  if (root == NULL) {
      return "empty";
  }
  char *inorder = malloc(20*sizeof(char));
  char *treeNodeValue;
  char *top = inorder;
  int i = 0;
  while (i < 15) {
    *inorder = NULL;
    inorder++;
    i++;
  }
  inorder = top;
  char num[3];
  if (root->leftNode != NULL) {
    treeNodeValue = inorderTraversal(root->leftNode);
    while (*treeNodeValue) {
      *inorder = *treeNodeValue;
      inorder++;
      treeNodeValue++;
    }
  }
  sprintf(num, "%d", root->key);
  treeNodeValue = num;
  while (*treeNodeValue) {
    *inorder = *treeNodeValue;
    inorder++;
    treeNodeValue++;
  }
  *inorder = ' ';
  inorder++;
  if (root->rightNode != NULL) {
    treeNodeValue = inorderTraversal(root->rightNode);
    while (*treeNodeValue) {
      *inorder = *treeNodeValue;
      inorder++;
      treeNodeValue++;
    }
  }
  return top;
}

/**********************************************
* Input: The character 'd' telling the user to delete a node from the tree and
* a number to delete from the tree. Also takes an int representing the result
* of calling searchTree on searchkey, and an int representing if zero is in the tree.
* Output: A 1 if the number is in the tree and a 0 if not.
* Pre-condition: The user must enter 'd' when prompted to enter an option. *
* Post-condition: The number must be deleted from the tree if it's in the tree,
* otherwise it must not be deleted. *
***********************************************/
int canDelete(int searchKey, int temp, int insertedZero) {
    if (searchKey != 0) {
        if (searchKey == temp) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (insertedZero == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

/***********************************************
* Input: The root of the tree and the number to delete.
* Output: No output but a node is deleted from the tree.
* Pre-condition: The user must enter 'd' when prompted to enter an option. *
* Post-condition: The number must be deleted from the tree if it's in the tree,
* otherwise it must not be deleted. *
***********************************************/
void deleteNode(struct Node* root, int num) {
    if (root == NULL) {
        return;
    }
    struct Node* prev; // the node before the node being deleted
    struct Node* smallest = root; // the smallest node in the right subbranch
    struct Node* temp = root; // keep reference to the top
    while (root->key != num) { // iterate until at the number to delete
        prev = root; // sets the previous node
        if (root->key < num) { // if num is greater than current node's value
            root = root->rightNode; // make node the right node
        }
        else { // if num is less than the current node's value
            root = root->leftNode; // make node the left node
        }
    }
    int children = 0;
    if (root->leftNode != NULL) { // if the node to delete has a left child
        children++;
    }
    if (root->rightNode != NULL) { // if the node to delete has a right child
        children++;
    }
    if (children == 0) { // if node to delete has no children
      /*  if (isRoot == 1) { // if the node to delete is the root
            root = NULL;
            free(root);
            return;
        }*/
        if (prev->key < root->key) { // if the node to delete is a right child
            prev->rightNode = NULL; // delete the reference
        } 
        else { // if the node to delete is a left child
            prev->leftNode = NULL; // delete the reference
        }
    }
    else if (children == 1) { // if the node to delete has one child
        if (prev->key < root->key) { // if the node to delete is a right child
            if (root->leftNode == NULL) { // if the node to delete doesn't have a left child
                prev->rightNode = root->rightNode; // previous node's new right child is the node to delete's right child
            }
            else { // if the node to delete doesn't have a right child
                prev->rightNode = root->leftNode; // previous node's new left child is the node to delete's left child
            }
        }
        else { // if the node to delete is a left child
            if (root->leftNode == NULL) { // if the node to delete doesn't have a left child
                prev->leftNode = root->rightNode; // previous node's new right child is the node to delete's right child
            }
            else { // if the node to delete doesn't have a right child
                prev->leftNode = root->leftNode; // previous node's new left child is the node to delete's left child
            }
        }
    }
    else { // if the node to delete has 2 children
        smallest = root->rightNode; // initialize smallest value in right subbranch
        struct Node* prevSmallest; // the previous node of the smallest value in the right subbranch
        while (smallest->leftNode != NULL) { // iterate until the smallest value in the right subbranch is found
            prevSmallest = smallest; // sets the previous smallest
            smallest = smallest->leftNode; // make the new smallest the left child
        }
        // smallest is 19 from example
        int smallestKey = smallest->key; // hold value of smallest key in right subbranch
        deleteNode(root, smallest->key); // delete smallest value from right subbranch out of tree
                                                 // in the case of the example, remove the original node containing 19
        root->key = smallestKey; // replace node to delete's key with smallest value in right subbranch's key
                                   // in the case of the example, take node who's key is 12, and make it 19
    }
}

/***********************************************
* Input: The root of the tree.
* Output: A 0 if the root has no children, 1 if it has 1 child, and 2 if it has 2 children.
* Pre-condition: The user must enter 'd' when prompted to enter an option, and they must
* choose to delete the root. *
* Post-condition: The root must be deleted from the tree.
***********************************************/
int deleteRoot(struct Node* root) { // method for deleting root
    int children = 0;
    struct Node* smallest = root;
    if (root->leftNode != NULL) {
        children++;
    }
    if (root->rightNode != NULL) {
        children++;
    }
    if (children == 0) {
        return 0;
    }
    else if (children == 1) {
        return 1;
    }
    else {
        if (root->rightNode != NULL) {
            smallest = root->rightNode;
            while(smallest->leftNode != NULL) {
                smallest = smallest->rightNode;
            }
            smallest->leftNode = root->leftNode;
            root->key = 0;
            root->leftNode = NULL;
        }
        return 2;
    }
}