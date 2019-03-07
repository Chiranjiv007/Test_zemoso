// Encrypt String 

// Author: Chiranjiv Goyal
// Date: 05/02/2019

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50
char input[MAX_LENGTH];

// Helper functions
void get_string(const char call_for_var[MAX_LENGTH]);
char* cypher_string(char plain_text[MAX_LENGTH], char* key);
void print_string(char cypher_text[MAX_LENGTH]);
int is_alpha(char* key);
char* get_key(char* key);

int main(int argc, char* argv[])
{


    if(argc != 2)
    {
        printf("Enter Valid Input\n");
        return 1;
    }


    char* key = get_key(argv[1]);
    get_string("String to Cypher: ");
    
    
    char* cypher_text = cypher_string(input, key);
    print_string(cypher_text);
}

char* get_key(char *input_key)
{
    if(is_alpha(input_key))
    {
        return input_key;
    }
    else
    {
        
        printf("Key: ");
        scanf("%s", input_key);
        get_key(input_key);
    }
}

int is_alpha(char* key)
{
    int index = 0;
    while(key[index]!='\0')
    {
        if(!((key[index]-'a'>=0 && key[index]-'a'<=25 )||
                (key[index]-'A'>=0 && key[index]-'A'<=25 )))
        {
            return 0;
        }
        index++;
    }
    return 1;
}

void get_string(const char call_for_var[MAX_LENGTH])
{
    
    printf("%s\n", call_for_var);
    fgets(input, MAX_LENGTH, stdin);
    input[strlen(input)-1]='\0';

    return;
}

char* cypher_string(char plain_text[MAX_LENGTH], char* key)
{
    int cypher_index = 0;
    int plain_index = 0;
    
    while(plain_text[plain_index] != '\0')
    {


        if(plain_text[plain_index]-'a'>=0 && plain_text[plain_index]-'a'<=25)
        {
            plain_text[plain_index] = ((plain_text[plain_index] - 'a') + (key[cypher_index]-'a'))%26 + 'a';
            cypher_index++;
        }

        else if(plain_text[plain_index]-'A'>=0 && plain_text[plain_index]-'A'<=25)
        {
            plain_text[plain_index] = ((plain_text[plain_index] - 'A') + (key[cypher_index]-'a'))%26 + 'A';
            cypher_index++;
        }
        if(key[cypher_index]=='\0')
        {
            cypher_index = 0;
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