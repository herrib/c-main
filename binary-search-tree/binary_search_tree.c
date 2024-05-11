#include "binary_search_tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

node_t *build_tree(int *tree_data, size_t tree_data_len) {

  node_t *root = (node_t *)calloc(sizeof(node_t), 1);
  root->data = tree_data[0];
  if (tree_data_len == 1) {
    return root;
  }

  node_t *tmp = root;
  for (int i = 1; i < (int)tree_data_len; i++) {
    while (tmp) {
      tmp = has_value(tmp, tree_data[i]);
    }
    tmp = root;
    }
return root;
}

void free_tree(node_t *tree) {

 /* node_t **l_nodes = calloc(sizeof(node_t *), 11);
  l_nodes[0] = tree;
  for (size_t i = 0; l_nodes[i]; i++) {
    size_t j = 1;
    if (l_nodes[i]->left) {
      l_nodes[i + j] = l_nodes[i]->left;
      j++;
    }
    if (l_nodes[i]->right) {
      l_nodes[i + j] = l_nodes[i]->right;
    }
  }
  for (size_t i = 0; l_nodes[i]; i++) {
    free(l_nodes[i]);
  }
  free(l_nodes);*/
  if(tree->left!=NULL) free_tree(tree->left);
    if(tree->right!=NULL) free_tree(tree->right);
    free(tree);
}

int *sorted_data(node_t *tree) {

  node_t **l_nodes = calloc(sizeof(node_t *), 11);

  int *list = calloc(sizeof(int), 10);

  l_nodes[0] = tree;
  for (size_t i = 0; l_nodes[i]; i++) {
    size_t j = 1;
    if (l_nodes[i]->left) {
      l_nodes[i + j] = l_nodes[i]->left;
      j++;
    }
    if (l_nodes[i]->right) {
      l_nodes[i + j] = l_nodes[i]->right;
    }
  }
  int count = 0;
  for (size_t i = 0; l_nodes[i]; i++) {
    list[i] = l_nodes[i]->data;
    count++;
  }
  int i, j, c;
  for (i = 0; i < count - 1; i++)
    for (j = i + 1; j < count; j++)
      if (list[i] > list[j]) {
        c = list[i];
        list[i] = list[j];
        list[j] = c;
      }
  free(l_nodes);
  return list;
}

node_t *has_value(node_t *t, int data) {
  if (data <= t->data) {
    if (t->left) {
      return t->left;
    } else {
      t->left = (node_t *) calloc(sizeof(node_t), 1);
      t->left->data = data;
    }
  } else {
    if (t->right) {
      return t->right;
    } else {
      t->right = (node_t *) calloc(sizeof(node_t), 1);
      t->right->data = data;
    }
  }
  return NULL;
}
