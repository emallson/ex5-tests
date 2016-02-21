#include <stdio.h>

#include "list.h"

struct Node* create_node(int val) {
  struct Node* n = calloc(sizeof(struct Node), 1);
  n->val = val;
  n->next = NULL;
  return n;
}

/* insert a new element into the list in-order. Return the new head of the list. */
struct Node* insert_ordered(struct Node* head, int val) {
  struct Node* new = create_node(val),
    *prev = NULL,
    *cur = head;

  while(val > cur->val) {
    prev = cur;
    cur = cur->next;
    if(cur == NULL) break;
  }

  new->next = cur;
  if(prev) {
    prev->next = new;
    return head;
  } else {
    return new;
  }
}

/* returns 1 if the list is ordered */
int is_ordered(struct Node* head) {
  for(struct Node* cur = head; cur != NULL; cur = cur->next) {
    if(cur->next && cur->val > cur->next->val)
      return 0;
  }
  return 1;
}

void print_list(struct Node* head) {
  for(struct Node* cur = head; cur != NULL; cur = cur->next) {
    printf("%d ", cur->val);
  }
  printf("\n");
}
