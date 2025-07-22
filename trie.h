#ifndef TRIE_H
#define TRIE_H

#define CHARSET_LEN 26 // a to z (lowercase)

#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[CHARSET_LEN];
    bool terminal;
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

Trie* create_trie(void);
bool insert_word(Trie* trie, const char* word);
bool has_word(Trie* trie, const char* word);
bool delete_word(Trie* trie, const char* word);

#endif // TRIE_H