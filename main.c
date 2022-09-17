/**********************************************
* Name: Riley Smith *
* Date: 9/18/2020 *
* Assignment: Project 3: Delete Node*
***********************************************
* This program uses the custom Node type that I
* created to insert, search for, traverse through,
* and free up space for binary tree Nodes. It does
* so using methods from the bst.c and io.c classes. *
***********************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "io.h"

int main() {
    struct Node* root = NULL;
    struct Node* start = NULL;
    int num = 0;
    int searchKey;
    int temp;
    int insertedZero = 0; // This variable prevents a bug in which the program says 0 is in the tree when it isn't.
    char option = 'i';
    char* inorder;
    int deletion = 1;
    int deleteKey;
    while (option != 'q') {
        printOptions();
        option = getOption();
        if (option == 'i') {
            num = insertOption(root);
            if (num == 0) {
                insertedZero = 1;
            }
            if (root == NULL) {
                root = insert(root, num);
                start = root;
            }
            else {
                insert(root, num);
            }
        }
        else if (option == 's'){
            searchKey = 0;
            temp = 0;
            searchKey = searchOption();
            temp = searchTree(root, searchKey);
            isInTree(searchKey, temp, insertedZero);
        }
        else if (option == 't') {
            if (root != NULL) {
                inorder = inorderTraversal(root);
                if (inorder != "empty") {
                    inorderTraversalOption(inorder); 
                }
            }
            else {
                emptyTree();
            }
        }
        else if (option == 'd') {
            searchKey = 0;
            temp = 0;
            deleteKey = deleteOption();
            searchKey = deleteKey;
            temp = searchTree(root, searchKey);
            int doDelete = canDelete(searchKey, temp, insertedZero);
            if (doDelete == 1) {
                if (root->key == deleteKey) {
                    deletion = deleteRoot(root);
                    if (deletion == 0) { // if root has no children
                        root = NULL;
                    }
                    else if (deletion == 1) {
                        if (root->rightNode != NULL) { // if root's only child is a right child
                            root = root->rightNode;
                        }
                        else { 
                            root = root->leftNode;
                        }
                    }
                }
                else {
                    deleteNode(root, deleteKey);
                }
            }
            else {
                cantDelete(deleteKey);
            }
        }
        else if (option == 'q') {
            option = 'q'; // I need this branch here so I can make an else branch where option != i, s, t or q.
        }
        else {
            notValidOption();
        }
    }
    if (root != NULL) {
        releaseMemory(start);
    }
}