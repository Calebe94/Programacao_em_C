#define _XOPEN_SOURCE 500 /* Enable certain library functions (strdup) on linux. See feature_test_macros(7) */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include "binary_tree.h"
int avl_node_height( treeNode *node ) {
	int height_left = 0;
	int height_right = 0;

	if( node->left ) height_left = avl_node_height( node->left );
	if( node->right ) height_right = avl_node_height( node->right );

	return height_right > height_left ? ++height_right : ++height_left;
}

/* Find the balance of an AVL node */
int avl_balance_factor( treeNode *node ) {
	int bf = 0;

	if( node->left  ) bf += avl_node_height( node->left );
	if( node->right ) bf -= avl_node_height( node->right );

	return bf ;
}

/* Left Left Rotate */
treeNode *avl_rotate_leftleft( treeNode *node ) {
 	treeNode *a = node;
	treeNode *b = a->left;
	
	a->left = b->right;
	b->right = a;

	return( b );
}

/* Left Right Rotate */
treeNode *avl_rotate_leftright( treeNode *node ) {
	treeNode *a = node;
	treeNode *b = a->left;
	treeNode *c = b->right;
	
	a->left = c->right;
	b->right = c->left; 
	c->left = b;
	c->right = a;

	return( c );
}

/* Right Left Rotate */
treeNode *avl_rotate_rightleft( treeNode *node ) {
	treeNode *a = node;
	treeNode *b = a->right;
	treeNode *c = b->left;
	
	a->right = c->left;
	b->left = c->right; 
	c->right = b;
	c->left = a;

	return( c );
}

/* Right Right Rotate */
treeNode *avl_rotate_rightright( treeNode *node ) {
	treeNode *a = node;
	treeNode *b = a->right;
	
	a->right = b->left;
	b->left = a; 

	return( b );
}

/* Balance a given node */
treeNode *avl_balance_node( treeNode *node ) {
	treeNode *newroot = NULL;

	/* Balance our children, if they exist. */
	if( node->left )
		node->left  = avl_balance_node( node->left  );
	if( node->right ) 
		node->right = avl_balance_node( node->right );

	int bf = avl_balance_factor( node );

	if( bf >= 2 ) {
		/* Left Heavy */	

		if( avl_balance_factor( node->left ) <= -1 ) 
			newroot = avl_rotate_leftright( node );
		else 
			newroot = avl_rotate_leftleft( node );

	} else if( bf <= -2 ) {
		/* Right Heavy */

		if( avl_balance_factor( node->right ) >= 1 )
			newroot = avl_rotate_rightleft( node );
		else 
			newroot = avl_rotate_rightright( node );

	} else {
		/* This node is balanced -- no change. */

		newroot = node;
	}

	return( newroot );	
}

/* Balance a given tree */
void avl_balance( treeNode *tree ) {

	treeNode *newroot = NULL;

	newroot = avl_balance_node( tree );

	if( newroot != tree )  {
		tree = newroot; 
	}
}
