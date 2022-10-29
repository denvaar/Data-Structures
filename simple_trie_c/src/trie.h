#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <stdbool.h>

#define N_CHILDREN 256

typedef struct node {
  bool term;
  int value;
  struct node *children[N_CHILDREN];
} node;

node* new_node(void);

void delete_trie(node *trie);

int lookup(node *trie, char *key);

bool prefix(node *trie, char *key);

void insert(node *trie, char *key, int value);

void print_trie(node *trie);

#endif
