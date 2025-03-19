#include "stdlib.h"
#include "stdint.h"
#include <stdint.h>

#ifndef TREE_H
#define TREE_H

typedef struct Node {
  float weight;
  uint8_t symbol;
  struct Node *left;
  struct Node *right;

} Node;



typedef struct Tree {
  Node *root;
} Tree;

Tree* new_tree();

Node* new_node(uint8_t symbol, float weight);

void insert_node(Node* node, Tree* tree);

void traverse_or_insert(Node* n1, Node* n2);

#endif // !TREE_H
       //
