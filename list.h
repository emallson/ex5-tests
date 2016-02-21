#ifndef EMPTYP_H
#define EMPTYP_H

#include <stdlib.h>

struct Node {
  int val;
  struct Node* next;
};

struct Node* create_node(int val);
struct Node* insert_ordered(struct Node* head, int val);

#endif
