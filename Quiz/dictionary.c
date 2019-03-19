// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26
int s;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        int index = tolower(word[0])-'a'

        node *cursor = hashtable(index);
        node *newnode = malloc(sizeof(node));

        strcpy(newnode->word,word);
        newnode->next = NULL;

        if(hashtable[index] == NULL)
        {
            hashtable[index] = newnode;
        }
        else
        {
            while(cursor->next != NULL)
            {
                cursor = cursor->next;
            }
            cursor->next = newnode;
        }

        s++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return s;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    if(word[0] == '\0')
    {
        return false;
    }

    int index = tolower(word[0])-'a';
    node* cursor = hashtable[index];

    while(cursor != NULL)
    {
        if(strcasecmp(word,cursor->word)==0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    // TODO
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0;i < 26; i++)
    {
        node* cursor = hashtable[i];
        while(cursor->next != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    // TODO
    return true;
}
