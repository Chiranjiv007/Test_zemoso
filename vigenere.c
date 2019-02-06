// Encrypt String 

// Author: Chiranjiv Goyal
// Date: 05/02/2019

#include <stdio.h>
#include <string.h>


// Helper functions

char* get_string(const char* call_for_var);
char* cypher_string(char* plain_text, char* key);
void print_string(char* cypher_text);


int main()
{
    char* plain_text = get_string("String to Cypher: ");
    char key = get_string("Key: ");

    char* cypher_text = cypher_string(plain_text, key);
    print_string(cypher_text);
}

char* get_string(const char* call_for_var)
{
    char* input;
    printf("%s\n", call_for_var);
    scanf("%s", input);
    return input;
}

char* cypher_string(char* plain_text, char* key)
{
    int cypher_index = 0;
    int plain_index = 0;

    while(plain_text[plain_index] != '\0')
    {
        if(plain_text[plain_index] != ' ')
        {
            plain_text[plain_index] = ((plain_text[plain_index] - 'a') + (key[cypher_index]-'a'))%26 + 'a';
            cypher_index++;
        }
        plain_index++;
    }

    return plain_text;
}

void print_string(char* cypher_text)
{
    printf("%s\n", cypher_text);
    return;
}