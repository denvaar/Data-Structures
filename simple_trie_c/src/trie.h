#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <stdbool.h>

#define N_CHILDREN 255

typedef struct node {
  bool term;
  struct node *children[N_CHILDREN];
} node;

node* new_node(void);

bool in(node *trie, char *word);

void insert_word(node *trie, char *word);

void print_trie(node *trie);

#endif
