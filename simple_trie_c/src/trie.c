#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

static node *new_node() {
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
void insert(node **trie, char *key, int value) {
  if (*trie == NULL) *trie = new_node();

  node *tmp = *trie;

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

static bool any_edges(node *n) {
  for (int i = 0; i < N_CHILDREN; i++) {
    if (n->children[i] != NULL) {
      return true;
    }
  }

  return false;
}

static int remove_node(node **n, int key_length) {
  int value = -1;

  if ((*n)->term && key_length == 0) {
    (*n)->term = false;
    value = (*n)->value;
  }

  if (!any_edges(*n)) {
    free(*n);
    *n = NULL;
  }

  return value;
}

static char strhead(char *s) {
  if (s != NULL) return s[0];

  return '\0';
}

static char *strtail(char *s) {
  if (s == NULL || strcmp(s, "") == 0) return "";

  char *tail = &s[1];

  return tail;
}

int remove_key(node **n, char *key) {
  int value = -1;
  int key_length = strlen(key);

  if (key_length == 0) {
    value = (*n)->value;
    remove_node(n, key_length);
    return value;
  }

  char k = strhead(key);

  if ((*n)->children[(int)k]) {
    value = remove_key(&(*n)->children[(int)k], strtail(key));
    remove_node(n, key_length);
  }

  return value;
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
  if (trie == NULL) return;

  print_walk(trie, 1, '*');
  printf("\n");
}
