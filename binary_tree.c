#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
	int value;
	struct bst_node* left;
	struct bst_node* right;
} bst_node;

typedef struct bst {
	bst_node* root;
	int size;
} bst;

bst_node* r_add(bst_node* cur, int data);
void add(bst* tree, int data);
int delete(int data);
bst_node* r_remove(bst_node* cur, bst_node* dummy, int data);

// takes an array and builds a BST representing the array
// bst* build_bst(int[] arr) {
// }

bst* build_empty_bst() {
	bst* tree = malloc(sizeof(bst));
	tree->root = NULL;
	tree->size = 0;
	return tree;
}

// takes in an integer to add to the tree and puts it in the correct spot
// bst assumes no duplicate data is present in the tree
void add(bst* tree, int data) {
	tree->root = r_add(tree->root, data);
}

// recursive adding helper method
bst_node* r_add(bst_node* cur, int data) {
	if(cur == NULL) {
		bst_node* node = malloc(sizeof(bst_node));
		node->value = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	} else if (cur -> value > data) {
		// recurse left
		cur->left = r_add(cur->left, data);
	} else if (cur->value < data) {
		// recurse right
		cur->right = r_add(cur->right, data);
	}

	return cur;
}

// remove the node containing the data
// in the case of 2 children, it will use it's predecessor

int delete(int data) {
	return 0;
}
