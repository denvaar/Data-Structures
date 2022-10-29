#include <stdio.h>

#include "trie.h"

int main(void) {
  node *root = new_node();

  insert(root, "day", 50);
  insert(root, "dogs", 10);

  print_trie(root);

  printf("lookup(root, \"day\") -> %d\n", lookup(root, "day"));
  printf("lookup(root, \"dogs\") -> %d\n", lookup(root, "dogs"));
  printf("lookup(root, \"dog\") -> %d\n", lookup(root, "dog"));

  insert(root, "donut", 3);
  insert(root, "doggy", 22);

  print_trie(root);

  printf("lookup(root, \"donut\") -> %d\n", lookup(root, "donut"));
  printf("prefix(root, \"z\") -> %d\n", prefix(root, "z"));
  printf("prefix(root, \"d\") -> %d\n", prefix(root, "d"));
  printf("prefix(root, \"do\") -> %d\n", prefix(root, "do"));
  printf("prefix(root, \"dog\") -> %d\n", prefix(root, "dog"));
  printf("prefix(root, \"dogg\") -> %d\n", prefix(root, "dogg"));
  printf("prefix(root, \"doggy\") -> %d\n", prefix(root, "doggy"));
  printf("prefix(root, \"doggyy\") -> %d\n", prefix(root, "doggyy"));

  delete_trie(root);
}
