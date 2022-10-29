#include <stdio.h>

#include "trie.h"

int main(void) {
  node *root = new_node();

  insert_word(root, "day");
  insert_word(root, "dogs");
  insert_word(root, "donut");
  insert_word(root, "doggy");
  insert_word(root, "dope");
  insert_word(root, "dopes");

  insert_word(root, "pickle");
  insert_word(root, "pick");
  insert_word(root, "pass");
  insert_word(root, "paint");
  insert_word(root, "painter");
  insert_word(root, "please");

  print_trie(root);
}
