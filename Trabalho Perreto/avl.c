#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
//#include "binary_tree.h"

int max(int a, int b);

int height(treeNode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
treeNode* newNode(int data)
{
    treeNode* node = (treeNode*) malloc(sizeof(treeNode));
    node->data   = data;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

treeNode *rightRotate(treeNode *y)
{
    treeNode *x = y->left;
    treeNode *subTree = x->right;
 
    x->right = y;
    y->left = subTree;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    return x;
}

treeNode *leftRotate(treeNode *x)
{
    treeNode *y = x->right;
    treeNode *subTree = y->left;
 
    y->left = x;
    x->right = subTree;
 
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}
 
int getBalance(treeNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
treeNode* add_AVL(treeNode* node, int data)
{
 
    if (node == NULL)
        return(newNode(data));
 
    if (data < node->data)
        node->left  = add_AVL(node->left, data);
    else if (data > node->data)
        node->right = add_AVL(node->right, data);
    else 
        return node;
 
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    int balance = getBalance(node);
 
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
 
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
 
    if (balance > 1 && data > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}
 
treeNode * minValueNode(treeNode* node)
{
    treeNode* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
treeNode* rm_AVL(treeNode* root, int data)
{
   
    if (root == NULL)
        return root;
 
    if ( data < root->data )
        root->left = rm_AVL(root->left, data);
 
    else if( data > root->data )
        root->right = rm_AVL(root->right, data);
 
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            treeNode *temp = root->left ? root->left :
                                             root->right;
 
          
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
             *root = *temp; 
            free(temp);
        }
        else
        {
            treeNode* temp = minValueNode(root->right);
 
            root->data = temp->data;
            root->right = rm_AVL(root->right, temp->data);
        }
    }

    if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left), height(root->right));
 
    int balance = getBalance(root);
 
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
 
void pre_Order_AVL(treeNode *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        pre_Order_AVL(root->left);
        pre_Order_AVL(root->right);
    }
}

/*int main()
{
  treeNode *root = NULL;
 
    root = add_AVL(root, 10);
    root = add_AVL(root, 9);
    root = add_AVL(root, 8);
    root = add_AVL(root, 5);
    root = add_AVL(root, 4);
 
    printf("Preorder traversal of the constructed AVL "           "tree is \n");
    pre_Order_AVL(root);
 	printf ("\n");
    root = rm_AVL(root, 8);
	root = add_AVL(root, 7);
    root = add_AVL(root, 6);
 
     
    printf("\npre_Order_AVL traversal after deletion of 10 \n");
    pre_Order_AVL(root);
 	printf("\n");
    return 0;
}*/
