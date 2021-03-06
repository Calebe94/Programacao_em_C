#ifndef __AVL_H__
#define __AVL_H__
#endif
#include <stdio.h>
#include <stdlib.h>
#include "binary.h"
int maximum(int a, int b);
int height(treeNode *N);
treeNode* newNode(int key);
treeNode *rightRotate(treeNode *y);
treeNode *leftRotate(treeNode *x);
int getBalance(treeNode *N);
treeNode* add_AVL(treeNode* node, int key);
treeNode * minValueNode(treeNode* node);
treeNode* rm_AVL(treeNode* root, int key);
void pre_Order_AVL(treeNode *root);

