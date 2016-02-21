#include <stdio.h>

#include "list.h"

#define NUM_TESTS 5

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int test_create_node() {
  struct Node* n = create_node(5);
  return (n && n->val == 5);
}

int test_is_ordered() {
  struct Node* a = create_node(1),
    *b = create_node(2),
    *c = create_node(3);

  /* check that an ordered list returns 1 */
  a->next = b;
  b->next = c;

  if(!is_ordered(a)) {
    return 0;
  }

  /* check that an unordered list returns 0 */
  a->next = c;
  c->next = b;
  b->next = NULL;

  if(is_ordered(a)) {
    return 0;
  }

  return 1;

}

int main() {
  int passed = 0;
  if(test_create_node()) {
    passed += 1;
    printf(ANSI_COLOR_GREEN "test_create_node()" ANSI_COLOR_RESET "\n");
  } else {
    printf(ANSI_COLOR_RED "test_create_node()" ANSI_COLOR_RESET "\n");
  }

  if(test_is_ordered()) {
    passed += 1;
    printf(ANSI_COLOR_GREEN "test_is_ordered()" ANSI_COLOR_RESET "\n");
  } else {
    printf(ANSI_COLOR_RED "test_is_ordered()" ANSI_COLOR_RESET "\n");
  }

  /* add tests here. You can copy the code that runs test_create_node() */

  /* do not modify this part */
  if(passed == NUM_TESTS) {
    printf(ANSI_COLOR_GREEN "Passed: %d/%d" ANSI_COLOR_RESET "\n", passed, NUM_TESTS);
  } else {
    printf(ANSI_COLOR_RED "Passed: %d/%d" ANSI_COLOR_RESET "\n", passed, NUM_TESTS);
  }

  return 0;
}
