#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{
        int data,height;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;
typedef struct tree{
	treeNode *root;
}tree;
typedef struct info{
	char data[30][30];
	unsigned int index,node_left,node_right;
	int element;
}info;
treeNode* Find_Min(treeNode *node);
treeNode* Find_Max(treeNode *node);
treeNode * add(treeNode *node,int data);
treeNode * rm(treeNode *node, int data);
info find(treeNode *node, int data);
void in_order(treeNode *toPrint);
void pre_order(treeNode *toPrint);
void post_order(treeNode *toPrint);
