#include <stdio.h>
#include <string.h>

#include "trie.h"

int main(void) {
  node *root = NULL;

  print_trie(root);

  printf("insert(&root, \"day\", 50)\n");
  insert(&root, "day", 50);

  print_trie(root);

  printf("insert(&root, \"dogs\", 10)\n");
  insert(&root, "dogs", 10);

  print_trie(root);

  printf("lookup(root, \"day\") -> %d\n", lookup(root, "day"));
  printf("lookup(root, \"dogs\") -> %d\n", lookup(root, "dogs"));
  printf("lookup(root, \"dog\") -> %d\n", lookup(root, "dog"));

  printf("insert(&root, \"donut\", 3)\n");
  insert(&root, "donut", 3);

  printf("insert(&root, \"doggy\", 22)\n");
  insert(&root, "doggy", 22);

  print_trie(root);

  printf("lookup(root, \"donut\") -> %d\n", lookup(root, "donut"));
  printf("prefix(root, \"z\") -> %d\n", prefix(root, "z"));
  printf("prefix(root, \"d\") -> %d\n", prefix(root, "d"));
  printf("prefix(root, \"do\") -> %d\n", prefix(root, "do"));
  printf("prefix(root, \"dog\") -> %d\n", prefix(root, "dog"));
  printf("prefix(root, \"dogg\") -> %d\n", prefix(root, "dogg"));
  printf("prefix(root, \"doggy\") -> %d\n", prefix(root, "doggy"));
  printf("prefix(root, \"doggyy\") -> %d\n", prefix(root, "doggyy"));

  print_trie(root);

  printf("remove_key(root, \"day\") -> %d\n", remove_key(&root, "day"));
  print_trie(root);

  printf("remove_key(&root, \"dogs\") -> %d\n", remove_key(&root, "dogs"));
  print_trie(root);

  printf("remove_key(&root, \"non key\") -> %d\n", remove_key(&root, "non key"));
  print_trie(root);

  printf("remove_key(&root, \"donu\") -> %d\n", remove_key(&root, "donu"));
  print_trie(root);

  printf("remove_key(&root, \"donuts\") -> %d\n", remove_key(&root, "donuts"));
  print_trie(root);

  printf("remove_key(&root, \"donut\") -> %d\n", remove_key(&root, "donut"));
  print_trie(root);

  delete_trie(root);
}
