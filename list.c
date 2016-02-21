#include "list.h"

struct Node* create_node(int val) {
  struct Node* n = calloc(sizeof(struct Node), 1);
  n->val = val;
  n->next = NULL;
  return n;
}

struct Node* insert_ordered(struct Node* head, int val) {
  struct Node* new = create_node(val);

  while(val < head->val) {
    head = head->next;
    if(head == NULL) break;
  }

  new->next = head->next;
  head->next = new->next;

  return new;
}

/* returns 0 if the list is ordered */
int is_ordered(struct Node* head) {
  for(struct Node* cur = head; cur != NULL; cur = cur->next) {
    if(head->next && head->val > head->next->val)
      return 1;
  }
  return 0;
}
