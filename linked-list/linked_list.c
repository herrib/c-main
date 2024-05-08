#include "linked_list.h"
#include <stdbool.h>
#include <stdlib.h>

struct list_node *create_node(struct list_node *prev, struct list_node *next,
                              ll_data_t data) {
  struct list_node *node = malloc(sizeof(struct list_node));
  node->prev = prev;
  node->next = next;
  node->data = data;
  return node;
}

struct list *list_create(void) {

  struct list *l = (struct list *)malloc(sizeof(struct list));
  l->first = NULL;
  l->last = NULL;
  return l;
}

size_t list_count(const struct list *list) {
  if (!list->first) {
    return 0;
  }
  struct list_node *p = list->first;
  size_t count = 0;
  while (p) {
    count++;
    p = p->next;
  }
  return count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data) {
  if (list_count(list) == 0) {
    list_unshift(list, item_data);
    return;
  }
  struct list_node *node = create_node(list->last, // prev
                                       NULL,       // next
                                       item_data);
  list->last->next = node;
  list->last = node;
}

// removes item from back of a list
ll_data_t list_pop(struct list *list) {

  struct list_node *node = list->last;
  ll_data_t output = node->data;
  if (node->prev) { //this not the only node
    node->prev->next = NULL;
  }
  list->last = node->prev;
  if (!list->last) {
    list->first = NULL;
  }
  free(node);
  return output;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data) {
  struct list_node *node = create_node(NULL, list->first, item_data);

  if (list->first)
    list->first->prev = node;
  else
    list->last = node;
  list->first = node;
}

// removes item from front of a list
ll_data_t list_shift(struct list *list) {

  struct list_node *node = list->first;
  ll_data_t output = list->first->data;

  if (node->next) {
    node->next->prev = NULL;
  }
  list->first = node->next;
  if (!list->first) {
    list->last = NULL;
  }
  free(node);
  return output;
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data) {

  struct list_node *node = list->first;
  while (node && node->data != data) {
    node = node->next;
  }
  if (!node)
    return;
  if (node->prev)
    node->prev->next = node->next;
  if (list->first == node)
    list->first = node->next;
  if (node->next)
    node->next->prev = node->prev;
  if (list->last == node)
    list->last = node->prev;
  free(node);
}
// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list) {
  while (list->last)
    list_pop(list);
  free(list);
}
