#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static TrieNode* create_node(void) {
    TrieNode* node = malloc(sizeof (TrieNode));
    if (!node) return NULL;
    
    for (int i = 0; i < CHARSET_LEN; i++) node->children[i] = NULL; // Set all children to NULL
    node->terminal = false;
    return node;
}

Trie* create_trie(void) {
    Trie* trie = malloc(sizeof (Trie));
    if (!trie) return NULL;

    TrieNode* root = create_node();
    if (!root) {
        free(trie);
        return NULL;
    }

    trie->root = root;
    trie->root->terminal = false;
    return trie;
}

bool insert_word(Trie* trie, const char* word) {
    if (!trie || !word || !*word) return false;

    TrieNode* curr = trie->root;

    const unsigned char* uword = (const unsigned char*) word;
    while (*uword) {
        if (!islower(*uword)) return false; // Reject words with non-lowercase letters

        int idx = *uword - 'a'; // Map character to child index

        if (!curr->children[idx]) { // Try to create the node if NULL, returning early in case of fail
            curr->children[idx] = create_node();
            if (!curr->children[idx]) return false;
        }
        curr = curr->children[idx]; // Move to the next node
        uword++; // Advance to the next character
    }

    // If the current node is terminal, word was already inserted
    if (curr->terminal) return false; 
    curr->terminal = true; // Mark this node as terminal to indicate end of a valid word
    return true;
}

bool has_word(Trie* trie, const char* word) {
    if (!trie || !word || !*word) return false;
        
    TrieNode* curr = trie->root;

    const unsigned char* uword = (const unsigned char*) word;
    while (*uword) {
        if (!islower(*uword)) return false; // Reject words with non-lowercase letters

        int idx = *uword - 'a'; // Map character to child index

        if (!curr->children[idx]) return false; // Return false if character not found

        curr = curr->children[idx]; // Move to the next node
        uword++; // Advance to the next character
    }
    return curr->terminal;
}

bool has_prefix(Trie* trie, const char* word) {
    if (!trie || !word | !*word) return false;

    TrieNode* curr = trie->root;

    const unsigned char* uword = (const unsigned char*) word;
    while (*uword) {
        if (!islower(*uword)) return false;

        int idx = *uword - 'a';

        if (!curr->children[idx]) return false;

        curr = curr->children[idx];
        uword++;
    }
    return true; 
}

bool delete_word(Trie* trie, const char* word) {
    if (!trie || !word || !*word) return false;

    TrieNode* curr = trie->root;

    const unsigned char* uword = (const unsigned char*) word;
    while (*uword) {
        if (!islower(*uword)) return false; // Reject words with non-lowercase letters

        int idx = *uword - 'a'; // Map character to child index

        if (!curr->children[idx]) return false; // Return false if character not found

        curr = curr->children[idx]; // Move to the next node
        uword++; // Advance to the next character
    }
    
    if (!curr->terminal) return false;

    curr->terminal = false;
    return true;
}
