#include <stdio.h>
#include "trie.h"

int main() {
    Trie* t = create_trie();
    if (!t) {
        perror("\nError: Trie cannot be created.");
        return 1;
    }

    char* words[] = {"ladder", "lead", "led", "catcher", "cat", "catch"};

    for(int i = 0; i < sizeof (words) / sizeof (words[0]); i++) {
        if (insert_word(t, words[i])) printf("\nWord '%s'\tinserted successfully.", words[i]);
    }

    printf("\n\nIs 'ladder' really in the Trie? %s", has_word(t, "ladder") ? "Yes" : "No");
    
    if(delete_word(t, "ladder")) {
        printf("\n\n'ladder' deleted! Let's search for it again");
    }
    
    printf("\n\nIs 'ladder' still in the Trie? %s", has_word(t, "ladder") ? "Yes" : "No");

    printf("\n\nWhat about 'catch'? Is it in the Trie? %s", has_word(t, "catch") ? "Yes" : "No");
    return 0;
}