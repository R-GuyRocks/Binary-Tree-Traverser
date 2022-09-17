/**********************************************
* io.c
***********************************************
* This class contains methods that print out the
* results of operating on a binary search tree.
* It tells the user when to and what to input,
* if a number is in the tree, and prints the result
* of performing an inorder traversal on the tree. *
***********************************************/

#include<stdio.h>
#include<stdlib.h>

#include "io.h"

/**********************************************
* Input: This method runs while the user hasn't pressed 'q'. *
* Output: The user is shown a print statement telling them to enter
* a character representing a binary search tree operation. *
* Pre-condition: If the user is past their first iteration, they need to
* enter a character that isn't a 'q'. *
* Post-condition: The user must gain the ability to insert a number, search
* for a number, or do an inorder traversal. If they choose not to do any of
* those, than the program must stop running. *
***********************************************/
void printOptions() {
     printf("Enter (i)nsert, (s)earch, inorder (t)raversal, (d)elete, or (q)uit: ");
}

/**********************************************
* Input: This method recieves a character from the user representing a binary
* search tree operation. *
* Output: This method returns the option the user entered. *
* Pre-condition: This method will be called as long as the user doesn't enter 'q'
* as an option. *
* Post-condition: The user must not enter an option that isn't 'i', 's', or 't'. *
***********************************************/
char getOption() {
    char option;
    scanf(" %c", &option); // Space prevents options from being printed twice.
    return option;
}

/**********************************************
* Input: The number the user inputs. *
* Output: The number the user wants to insert into the tree. *
* Pre-condition: The user must enter 'i' when prompted to enter an option. *
* Post-condition: The number must be inserted into the tree. *
***********************************************/
int insertOption() {
    int num = 0;
    printf("Enter a number to insert: ");
    scanf(" %d", &num);
    return num;
} 

/**********************************************
* Input: The character 's' entered by a user who wants to search the tree. *
* Output: The number the user wants search the tree for. *
* Pre-condition: The user must enter 's' when prompted to enter an option. *
* Post-condition: The number must be searched for in the tree. *
***********************************************/
int searchOption() {
    int num = 0;
    printf("Enter a number to search for: ");
    scanf(" %d", &num);
    return num;
}

/**********************************************
* Input: The character 's' entered by a user who wants to search the tree. *
* Output: A message telling the user if their number is in the tree. *
* Pre-condition: The user must enter 's' when prompted to enter an option. *
* Post-condition: The number must be told whether or not their number is in
* the tree. *
***********************************************/
void isInTree(int searchKey, int temp, int insertedZero) {
    if (searchKey != 0) {
        if (searchKey == temp) {
            printf("%d is in the tree.\n", searchKey);
        }
        else {
            printf("%d is not in the tree.\n", searchKey);
        }
    }
    else {
        if (insertedZero == 1) {
            printf("0 is in the tree.\n");
        }
        else {
            printf("0 is not in the tree.\n");
        }
    }
}

/**********************************************
* Input: A character pointer which points to the beginning of a list of the
* integers in order from the tree. *
* Output: The result of doing an inorder traversal on the tree. *
* Pre-condition: The user must enter 't' when prompted to enter an option. *
* Post-condition: An inorder traversal of the tree must be shown to the user. *
***********************************************/
void inorderTraversalOption(char* inorder) {
    printf("%s\n", inorder);
}

/**********************************************
* Input: The character 'd' telling the user to delete a node from the tree.
* Output: The number to delete from the tree. *
* Pre-condition: The user must enter 't' when prompted to enter an option. *
* Post-condition: The number must be deleted from the tree. *
***********************************************/
int deleteOption() {
    int num = 0;
    printf("Enter a number to delete: ");
    scanf(" %d", &num);
    return num;
}

/**********************************************
* Input: The character 'd' telling the user to delete a node from the tree.
* Output: A message telling the user that they can't delete the number from the tree. *
* Pre-condition: The user must enter 't' when prompted to enter an option. *
* Post-condition: The number must be told that they can't delete the number from the tree. *
***********************************************/
void cantDelete(int num) {
    printf("%d can't be deleted as it's not in the tree!\n", num);
}


/**********************************************
* Input: The character 't' entered by a user who wants to do an inorder traversal. *
* Output: A message telling the user that the tree is empty. *
* Pre-condition: The binary search tree must not have any numbers in it. *
* Post-condition: The number must be told that the tree is empty. *
***********************************************/
void emptyTree() {
    printf("The tree is empty.\n");
}

/**********************************************
* Input: A character that isn't 'i', 's', 't' or 'q'. *
* Output: A message telling the user that they didn't enter a valid option. *
* Pre-condition: A user must have entered an option that isn't 'i', 's', 't' or 'q'. *
* Post-condition: The user must be told that their option is invalid. *
***********************************************/
void notValidOption() {
    printf("That is not a valid option!\n");
}