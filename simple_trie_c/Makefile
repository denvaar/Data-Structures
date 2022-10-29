# target : dependencies
# 	actions

all: main

main: _build/main.o _build/trie.o
	gcc _build/main.o _build/trie.o -o _build/main

main.o: src/main.c
	gcc -c src/main.c

trie.o: src/trie.h src/trie.c
	gcc -c src/trie.c -o _build/trie.o

clean:
	rm -rf _build

run:
	_build/main
