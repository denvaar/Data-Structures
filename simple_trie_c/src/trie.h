#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <stdbool.h>

#define N_CHILDREN 256

typedef struct node {
  bool term;
  int value;
  struct node *children[N_CHILDREN];
} node;

void delete_trie(node *trie);

int lookup(node *trie, char *key);

bool prefix(node *trie, char *key);

void insert(node **trie, char *key, int value);

int remove_key(node **trie, char *key);

void print_trie(node *trie);

#endif
