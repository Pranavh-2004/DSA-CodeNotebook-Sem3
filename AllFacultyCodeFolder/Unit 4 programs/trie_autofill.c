//			trie_autofill.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"

// Recursive function to print auto-suggestions for given 
// node. 
void suggestionsRec(TrieNODE* root, char *currPrefix) 
{ 
    //int slen;

    //printf ("Cur prefix is %s\n", currPrefix);

    // found a string in Trie with the given prefix 
    if (root->isEndOfWord) 
    { 
	printf ("Word is %s\n", currPrefix);
    } 
  
    // All children struct node pointers are NULL 
    if (isEmpty(root)) 
    {
        currPrefix [strlen (currPrefix) - 1] = '\0';
	//printf ("Ret from here\n");
        return; 
    }
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    { 
        if (root->children[i]) 
        { 
 	    int slen;
            // append current character to currPrefix string
	    slen = strlen (currPrefix);
            currPrefix [slen] = (97 + i);  // 97 ia 'a' 
            //currPrefix [slen + 1] = '\0';
  
            // recur over the rest 
            suggestionsRec(root->children[i], currPrefix); 
        } 
    } 
} 
  
// print suggestions for given query prefix. 
int printAutoSuggestions(TrieNODE* root, char *query) 
{ 
    TrieNODE* pCrawl = root; 
    char prefix [100];
  
    // Check if prefix is present and find 
    // the node (of last level) with last character 
    // of given string. 
    int level; 
    int n = strlen (query); 
    for (level = 0; level < n; level++) 
    { 
        int index = CHAR_TO_INDEX(query[level]); 
  
        // no string in the Trie has this prefix 
        if (!pCrawl->children[index]) 
            return 0; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // If prefix is present as a word. 
    bool isWord = (pCrawl->isEndOfWord == true); 
  
    // If prefix is last node of tree (has no 
    // children) 
    bool isLast = isEmpty(pCrawl); 
  
    // If prefix is present as a word, but there is no subtree below 
    // the last matching node. 
    if (isWord && isLast) 
    { 
	printf ("Query is %s\n", query);
        return -1; 
    } 
  
    // If there are nodes below last matching character. 
    if (!isLast) 
    { 
 	strcpy (prefix, query);
        suggestionsRec(pCrawl, prefix); 
        return 1; 
    } 
} 
