// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 65536

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
/* THIS IS CUSTOMISABLE */
const unsigned int N = HASHTABLE_SIZE;

// Hash table, also a global pointer array
node *table[N];
// for counting each time loading word in dictionary
int word_count = 0;

unsigned int hash(const char *word);

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    // Hash word to obtain a hash value, for index
    unsigned int index = hash(word);

    /* How to change all of word to lowercase? */
    // make a string copy of word
    // why copy? Not to change the original word
    // iterate through the word, and change each of them to lowercase version
    char word_copy[strlen(word) + 1];
    // ^^ this will make extra space to add "\0" to each last element of the copied word

    for (int i = 0; i < strlen(word); i++)
    {
        // copy word to its lowercase version
        word_copy[i] = tolower(word[i]);
    }
    word_copy[strlen(word)] = '\0';

    // cursor for traversing linked list
    node *cursor = table[index];

    // Access linked list at that index in the hash table
    while (cursor != NULL)
    {
        // check if cursor is the same as word
        if (strcmp(cursor->word, word_copy) == 0)
        {
            return true;
        }

        // move the cursor to the next node on hash table in that index
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
// Source: stackoverflow.com/questions/7666509/hash-function-for-string
unsigned int hash(const char *word)
{
    // TODO
    unsigned long hash = 5381;
    int c = 0;

    while (c == *word++)
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % HASHTABLE_SIZE;
}

// int hash_it(char *needs_hashing);

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO

    // open file
    FILE *inptr = fopen(dictionary, "r"); // don't forget to close the file after being used!!!
    if (inptr == NULL)
    {
        // close the file if something bad happen
        fclose(inptr);
        return false;
    }

    char buffer[LENGTH + 1]; // storing data to manipulate

    // read strings from the dictionary file until end of the file
    while (fscanf(inptr, "%s", buffer) != EOF)
    {
        // create new node for each word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        // copy word into node
        strcpy(new_node->word, buffer);
        new_node->next = NULL;

        // Use the hash function to find index
        int bucket = hash(buffer);

        /* REMINDER
            table[bucket] == (current) HEAD
        */

        // insert the new node
        if (table[bucket] == NULL)
        {
            // determine first new node as head
            table[bucket] = new_node;
            word_count++;
        }
        else
        {
            // new node point to next of previous head
            new_node->next = table[bucket];
            // change head to new node
            table[bucket] = new_node;
            word_count++;
        }
    }
    // close the file after being used
    fclose(inptr);

    return true;
}

unsigned int size(void)
{
    // TODO
    if (word_count > 0)
    {
        return word_count;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // iterate through every single index of the hashtabke
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        // cursor pointing the current head
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            // move the cursor before freeing the first element
            cursor = cursor->next;
            free(tmp);
        }
    }

    return true;
}
