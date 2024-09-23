#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct bst_node {
  int value;
  struct bst_node *left;
  struct bst_node *right;
} bst_node;

typedef struct bst {
  bst_node *root;
  int size;
} bst;

bst* build_bst(int arr[], int size);
bst *build_empty_bst();
bst_node *r_add(bst_node *cur, int data);
void add(bst *tree, int data);
int remove_node(bst *tree, int data);
bst_node *r_delete(bst_node *cur, bst_node *dummy, int data);
bst_node* delete_predecessor(bst_node* cur, bst_node* dummy);
void print_bst(bst_node *root);
void free_tree(bst *tree);
void free_tree(bst *tree);
void free_tree_helper(bst_node *root);

#endif
