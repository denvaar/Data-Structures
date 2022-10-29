#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

/*
 * Creation
 */
node *new_node() {
  node *n = malloc(sizeof(node));
  n->term = false;
  n->value = -1;

  for (int i = 0; i < N_CHILDREN; i++) {
    n->children[i] = NULL;
  }

  return n;
}

/*
 * Look up a value using a given key
 */
int lookup(node *trie, char *key) {
  node *tmp = trie;

  for (int i = 0; i < strlen(key); i++) {
    char letter = key[i];

    if (tmp->children[(int)letter]) {
      tmp = tmp->children[(int)letter];
    } else {
      return -1;
    }
  }

  return tmp->value;
}

/*
 * Check if key is a prefix.
 */
bool prefix(node *trie, char *key) {
  node *tmp = trie;

  for (int i = 0; i < strlen(key); i++) {
    char letter = key[i];

    if (tmp->children[(int)letter]) {
      tmp = tmp->children[(int)letter];
    } else {
      return false;
    }
  }

  return true;
}

/*
 * Insertion
 */
void insert(node *trie, char *key, int value) {
  node *tmp = trie;

  int key_length = strlen(key);

  for (int i = 0; i < key_length; i++) {
    char letter = key[i];

    if (tmp->children[(int)letter] == NULL) {
      node *n = new_node();
      tmp->children[(int)letter] = n;
      tmp = n;

    } else {
      tmp = tmp->children[(int)letter];
    }

    if (i == key_length - 1) {
      tmp->term = true;
      tmp->value = value;
    }
  }

}

void delete_trie(node *trie) {
  for (int i = 0; i < N_CHILDREN; i++) {
    if (trie->children[i]) {
      delete_trie(trie->children[i]);
    }
  }

  free(trie);
}

static void indent(n) {
  for (int i = 0; i < n; i++) printf("%s", " ");
}

static void print_letter(char letter) {
  printf("-%c", letter);
}

static void print_walk(node *n, int depth, char letter) {
  print_letter(letter);

  int edge_count = 0;

  for (int i = 0; i < N_CHILDREN; i++) {
    if (n->children[i]) {
      edge_count++;

      if (edge_count > 1 || n->term) {
        printf("\n");
        indent(depth * 2);
      }

      print_walk(n->children[i], depth + 1, (char)i);
    }
  }
}

void print_trie(node *trie) {
  print_walk(trie, 1, '*');
  printf("\n");
}
