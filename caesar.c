// Encrypt String 

// Author: Chiranjiv Goyal
// Date: 05/02/2019

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_LENGTH 50


// Helper functions
char* get_string(const char call_for_var[MAX_LENGTH]);
char* cypher_string(char* plain_text, int key);
void print_string(char* cypher_text);
int get_key(char key[MAX_LENGTH]);
int is_valid(char key[MAX_LENGTH]);
int string_to_int (char key[MAX_LENGTH]);

int main(int argc, char *argv[])
{
    if(argc!= 2){
        printf("Wrong number of arguments. You need to provide KEY ");
    }

    int key_int = get_key(argv[1]);
    
    char* plain_text = get_string("Plain text:");
    // int key_int = get_int("Key: ");

    char* cypher_text = cypher_string(plain_text,key_int);
    print_string(cypher_text);   
	
}

// Get a valid key
int get_key(char *key)
{
    
    if(is_valid(key)){
        return string_to_int(key)%26;
    }
    else{
        printf("Key: ");
        scanf("%s ", key);
        return get_string(key);
    }
}

// Convert string to Integer
int string_to_int (char key[MAX_LENGTH])
{
    
    int index = 0,key_int = 0;
    while(key[index]!='\0'){
        key_int*=10;
        key_int+=(key[index]-'0');
        index++;
    }
    return key_int;
}


// Valid Key?
int is_valid(char key[MAX_LENGTH])
{
   
    int i=0;
    
    while(key[i]!='\0')
    {
        if(key[i]-'0'<0 || key[i]-'0'>9){return 0;}
        i++;
    }
    return 1;
}

// String input
char* get_string(const char call_for_var[MAX_LENGTH])
{
    
    char* input;
    printf("%s\n", call_for_var);
    scanf("%s", input);
    return input;
}


// Cypher String
char* cypher_string(char* plain_text, int key)
{
    
    int index=0;
    while(plain_text[index]!='\0')
    {
        
        if(plain_text[index]-'a'>=0 
            && plain_text[index]-'a'<=25)
        {
            plain_text[index] = ((plain_text[index]-'a') + key)%26 + 'a';
            
        }        
        else if(plain_text[index]-'A'>=0
            && plain_text[index]-'A'<=25){
                plain_text[index] = ((plain_text[index]-'A')+key)%26 + 'A';
        }
        index++;
    }
    return plain_text;
}

// Print Answer
void print_string(char* cypher_text)
{
    printf("%s\n", cypher_text);
    return;
}
