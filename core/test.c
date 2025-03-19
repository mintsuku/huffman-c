#include "../include/tree.h"
#include "stdlib.h"
#include <stdio.h>
#include "../include/test.h"

int tests_run = 0;


static char* test_left_root_assign() {
  Tree *tree = new_tree();
  Node *root = new_node(0x00, 0.50);
  Node *root_left = new_node(0x01, 0.40);

  insert_node(root, tree);
  insert_node(root_left, tree);
  mu_assert("error: root left node assignment failed", root->left->symbol == 0x01);
  

  free(root);
  free(root_left);
  free(tree);

  return 0;
}


static char* test_root_child_left_assign() {
  Tree *tree = new_tree();
  Node *root = new_node(0x00, 0.50);
  Node *root_left = new_node(0x01, 0.40);
  Node *left_child = new_node(0x02, 0.30);

  insert_node(root, tree);
  insert_node(root_left, tree);
  insert_node(left_child, tree);

  mu_assert("error left nodes left child assignment failed", root->left->left->symbol == 0x02);

  free(tree);
  free(root);
  free(root_left);
  free(left_child);

  return 0;
}


static char* test_right_root_assign() {
  Tree *tree = new_tree();
  Node *root = new_node(0x00, 0.50);
  Node *root_right = new_node(0x01, 0.70);

  insert_node(root, tree);
  insert_node(root_right, tree);

  mu_assert("error: roots right node assignment failed", root->right->symbol == 0x01);

  free(tree);
  free(root);
  free(root_right);

  return 0;
}


static char* test_root_child_right_assign() {
  Tree *tree = new_tree();
  Node *root = new_node(0x00, 0.33);
  Node *root_right = new_node(0x01, 0.70);
  Node *right_child = new_node(0x02, 0.99);


  insert_node(root, tree);
  insert_node(root_right, tree);
  insert_node(right_child, tree);

  mu_assert("error: right nodes right child assignment failed", root_right->right->symbol == 0x02);

  free(tree);
  free(root);
  free(root_right);
  free(right_child);

  return 0;
}

static char* run_all_test() {

  mu_run_test(test_left_root_assign);
  mu_run_test(test_root_child_left_assign);
  mu_run_test(test_right_root_assign);
  mu_run_test(test_root_child_right_assign);
  return 0;
}


 int main() {
     char *result = run_all_test();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);
 
     return result != 0;
 }
