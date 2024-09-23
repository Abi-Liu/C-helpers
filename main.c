#include <stdio.h>
#include "binary_tree.h"

int main() {
  /*
  *           original tree structure:
  *       preorder: [5, 3, 2, 4, 7, 6, 8]
  *                   5
  *                 /   \
  *                3    7
  *               / \  / \
  *              2  4  6  8 
  */

  int arr[7] = {5, 3, 7, 2, 4, 6, 8};
  bst *tree = build_bst(arr, 7);
  print_bst(tree->root);
  printf("\n");


 /*
  *          post add tree structure:
  *       preorder: [5, 3, 2, 1, 4, 7, 6, 8]
  *                   5
  *                 /   \
  *                3    7
  *               / \  / \
  *              2  4  6  8 
  *             /
  *            1
  */
  add(tree, 1);
  print_bst(tree->root);
  printf("\n");


  /*
  *           post remove 1 tree structure:
  *       preorder: [5, 3, 2, 4, 7, 6, 8]
  *                   5
  *                 /   \
  *                3    7
  *               / \  / \
  *              2  4  6  8 
  */
  remove_node(tree, 1);
  print_bst(tree->root);
  printf("\n");

  /*
  *           post remove 1 tree structure:
  *       preorder: [4, 3, 2, 7, 6, 8]
  *                   4
  *                 /   \
  *                3    7
  *               /    / \
  *              2     6  8 
  */
  remove_node(tree, 5);
  print_bst(tree->root);
  printf("\n");
  printf("%d\n", tree->size);

  free_tree(tree);
}
