#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NODES_COUNT 1000

struct Node {
	int key;
	struct Node* parent;
	struct Node* left;
	struct Node* right;
};

struct BST {
	struct Node* root;
}; 

struct BST* tree_initialize( struct Node* );
void inorder_tree_walk( struct Node* );
struct Node* tree_search( struct Node*, int );
struct Node* iterative_tree_search( struct Node*, int );
struct Node* tree_minimum( struct Node* );
struct Node* tree_maximum( struct Node* );
struct Node* tree_successor( struct Node* );
struct Node* tree_predecessor( struct Node* );
void tree_insert( struct BST*, struct Node* );
void tree_delete( struct BST*, struct Node* );

int main( void ) {
	struct BST* tree = tree_initialize( NULL );

	for ( int i = 0; i < NODES_COUNT; i++ ) {
		int k = floor( random() );
		struct Node* node = malloc( sizeof( struct Node ) );
		node->key = k;
		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;

		tree_insert( tree, node );
	}

	// inorder_tree_walk( tree->root );
	struct Node* s = iterative_tree_search( tree->root, 2143124030 );
	if ( s != NULL ) {
		printf( "2143124030 exist\n" );
	}
	else {
		printf( "2143124030 not exist\n" );
	}

	tree_delete( tree, s );

	struct Node* ss = iterative_tree_search( tree->root, 2143124030 );
	if ( ss != NULL ) {
		printf( "2143124030 exist\n" );
	}
	else {
		printf( "2143124030 not exist\n" );
	}
	return 0;
}

struct BST* tree_initialize( struct Node* root ) {
	struct BST* bst = malloc( sizeof( struct BST ) );
	bst->root = root;

	return bst;
}

void inorder_tree_walk( struct Node* root ) {
	if ( root != NULL ) {
		inorder_tree_walk( root->left );
		printf( "node with key %d\n", root->key );
		inorder_tree_walk( root->right );
	}
}

struct Node* tree_search( struct Node* root, int k ) {
	if ( root == NULL || root->key == k ) {
		return root;
	}

	if ( k > root->key ) {
		tree_search( root->right, k );
	}
	else {
		tree_search( root->left, k );
	}
}

struct Node* iterative_tree_search( struct Node* root, int k ) {
	while ( root != NULL && root->key != k ) {
		if ( k > root->key ) {
			root = root->right;
		}
		else {
			root = root->left;
		}
	}

	return root;
}

struct Node* tree_minimum( struct Node* root ) {
	while ( root != NULL && root->left != NULL ) {
		root = root->left;
	}

	return root;
}

struct Node* tree_maximum( struct Node* root ) {
	while ( root != NULL && root->right != NULL ) {
		root = root->right;
	}

	return root;
}

struct Node* tree_successor( struct Node* x ) {
	if ( x->right != NULL ) {
		return tree_minimum( x->right );
	}

	struct Node* y = x->parent;
	while ( y != NULL && y->left != x ) {
		x = y;
		y = y->parent;
	}

	return y; 
}

struct Node* tree_predecessor( struct Node* x ) {
	if ( x->left != NULL ) {
		return tree_maximum( x->left );
	}

	struct Node* y = x->parent;
	while ( y != NULL && y->right != x ) {
		x = y;
		y = y->parent;
	}

	return y; 
}

void tree_insert( struct BST* tree, struct Node* z ) {
	struct Node* x = tree->root;

	struct Node* y = NULL;
	while ( x != NULL ) {
		y = x;

		if (  z->key > x->key ) {			
			x = x->right;
		}
		else {
			x = x->left;
		}
	}

	z->parent = y;
	if ( y == NULL ) {
		tree->root = z;
	}
	else {
		if (  z->key > y->key ) {			
			y->right = z;
		}
		else {
			y->left = z;
		}
	}	
}

void tree_delete( struct BST* tree, struct Node* z ) {
	struct Node* toBeSplicedOut;
	if ( z->left == NULL || z->right == NULL ) {
		toBeSplicedOut = z;
	}
	else {
		toBeSplicedOut = tree_successor( z );
	}

	struct Node* nonNullChild;
	if ( toBeSplicedOut->left != NULL ) {
		nonNullChild = toBeSplicedOut->left;
	}
	else {
		nonNullChild = toBeSplicedOut->right;
	}

	if ( nonNullChild != NULL ) {
		nonNullChild->parent = toBeSplicedOut->parent;
	}

	if ( toBeSplicedOut->parent == NULL ) {
		tree->root = nonNullChild;
	}
	else {
		if ( toBeSplicedOut == (toBeSplicedOut->parent)->left ) {
			(toBeSplicedOut->parent)->left = nonNullChild;
		}
		else {
			(toBeSplicedOut->parent)->left = nonNullChild;
		}
	}

	if ( toBeSplicedOut != z ) {
		z->key = toBeSplicedOut->key;
	}

	free( toBeSplicedOut );
}