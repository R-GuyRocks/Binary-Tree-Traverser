/**********************************************
* io.h
***********************************************
* This header file contains method declarations
* for all of the methods in the io.c class.
***********************************************/

#ifndef SMITHR_P2_IO_H
#define SMITHR_P2_IO_H

#include "bst.h"


void printOptions();
char getOption();
int insertOption();
int searchOption();
void isInTree(int searchKey, int temp, int insertedZero);
void inorderTraversalOption(char* inorder);
int deleteOption();
void cantDelete();
void emptyTree();
void notValidOption();

#endif //SMITHR_P2_IO_H