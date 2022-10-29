#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

node *new_node() {
  node *n = malloc(sizeof(node));
  n->term = false;

  for (int i = 0; i < N_CHILDREN; i++) {
    n->children[i] = NULL;
  }

  return n;
}

bool in(node *trie, char *word) {
  node *tmp = trie;

  int word_length = strlen(word);

  for (int i = 0; i < word_length; i++) {
    char letter = word[i];

    if (tmp->children[(int)letter]) {
      tmp = tmp->children[(int)letter];
    } else {
      return false;
    }
  }

  return tmp->term;
}

void insert_word(node *trie, char *word) {
  node *tmp = trie;

  int word_length = strlen(word);

  for (int i = 0; i < word_length; i++) {
    char letter = word[i];

    if (tmp->children[(int)letter] == NULL) {
      node *n = new_node();
      tmp->children[(int)letter] = n;
      tmp = n;

    } else {
      tmp = tmp->children[(int)letter];
    }

    if (i == word_length - 1) {
      tmp->term = true;
    }
  }

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
