#include "../include/tree.h"
#include <stdio.h>
#include <stdlib.h>


Tree* new_tree() {
  
  Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
  tree->root = NULL;

  return tree;
}

void insert_node(Node* node, Tree* tree) {
  if (tree->root == NULL) {
    tree->root = node;
    return;
  }

  if (node->weight < tree->root->weight) {
    if (tree->root->left != NULL) {
      traverse_or_insert(node, tree->root->left);
    } else {
      tree->root->left = node;
    }
  } else if (node->weight >=tree->root->weight) {
    if (tree->root->right != NULL) {
      traverse_or_insert(node, tree->root->right);
    } else {
      tree->root->right = node;
    }
  }
}


void traverse_or_insert(Node* n1, Node* n2) {

  if (n1->weight < n2->weight) {
    if (n2->left) {
      traverse_or_insert(n1, n2->left);
    } else {
      n2->left = n1;
    }
  } else if (n1->weight >= n2->weight) {
    if (n2->right) {
      traverse_or_insert(n1, n2->right);
    } else {
      n2->right = n1;
    }
  }

}

