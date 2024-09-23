#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
  int value;
  struct bst_node *left;
  struct bst_node *right;
} bst_node;

typedef struct bst {
  bst_node *root;
  int size;
} bst;

bst_node *r_add(bst_node *cur, int data);
void add(bst *tree, int data);
int delete(bst *tree, int data);
bst_node *r_delete(bst_node *cur, bst_node *dummy, int data);
bst_node* delete_predecessor(bst_node* cur, bst_node* dummy);

// takes an array and builds a BST representing the array
// bst* build_bst(int[] arr) {
// }

bst *build_empty_bst() {
  bst *tree = malloc(sizeof(bst));
  tree->root = NULL;
  tree->size = 0;
  return tree;
}

// takes in an integer to add to the tree and puts it in the correct spot
// bst assumes no duplicate data is present in the tree
void add(bst *tree, int data) { tree->root = r_add(tree->root, data); }

// recursive adding helper method
bst_node *r_add(bst_node *cur, int data) {
  if (cur == NULL) {
    bst_node *node = malloc(sizeof(bst_node));
    node->value = data;
    node->left = NULL;
    node->right = NULL;
    return node;
  } else if (cur->value > data) {
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
// returns INT_MIN when node to delete is not found, and the deleted data otherwise
int delete(bst *tree, int data) {
  bst_node *dummy = malloc(sizeof(bst_node));
  dummy->value = INT_MIN;
  tree->root = r_delete(tree->root, dummy, data);

  if(dummy->value != INT_MIN) {
    // we know the node to delete was found, decrement size
    tree->size--;
  }

  free(dummy);
  return dummy->value;
}

bst_node *r_delete(bst_node *cur, bst_node *dummy, int data) {
  if (cur == NULL) {
    // data not found.
    return NULL;
  } else if (cur->value > data) {
    // recurse left
    cur->left = r_delete(cur->left, dummy, data);
  } else if (cur->value < data) {
    // recures right
    cur->right = r_delete(cur->right, dummy, data);
  } else {
    // data found
    dummy->value = cur->value;
    if(cur->left == NULL && cur->right == NULL) {
      // both children are null we can safely remove the node
      return NULL;
    } else if(cur->left==NULL) {
      // right child exists
      return cur->right;
    } else if(cur->right == NULL) {
      // left child exists
      return cur->left;
    } else {
      // both children exist. We will use the predecessor
      bst_node* dummy2 = malloc(sizeof(bst_node));
      cur->left = delete_predecessor(cur->left, dummy2);
      cur->value = dummy2->value;
      free(dummy2);
    }
  }

  return cur;
}

bst_node* delete_predecessor(bst_node* cur, bst_node* dummy) {
  if(cur->right == NULL) {
    // found predecessor
    dummy->value = cur->value;
    return cur->left;
  } else {
    cur->right = delete_predecessor(cur->right, dummy);
  }

  return cur;
}
