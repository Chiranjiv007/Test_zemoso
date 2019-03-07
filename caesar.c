// Encrypt String 

// Author: Chiranjiv Goyal
// Date: 05/02/2019

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_LENGTH 50


// Helper functions
int get_int(const char call_for_var[MAX_LENGTH]);
char* get_string(const char call_for_var[MAX_LENGTH]);
char* cypher_string(char* plain_text, int key);
void print_string(char* cypher_text);
int get_key(char key[MAX_LENGTH]);
int is_valid(char key[MAX_LENGTH]);
int string_to_int (char key[MAX_LENGTH]);

char key_char[MAX_LENGTH] = {'\0'};
int main(int argc, char *key_char)
{
    if(argc!= 2){
        printf("Wrong number of arguments. You need to provide KEY ");
    }

    printf("%s\n",key_char);
    int key_int = get_key(key_char);
    
    char* plain_text = get_string("Plain text:");
    // int key_int = get_int("Key: ");

    char* cypher_text = cypher_string(plain_text,key_int);
    print_string(cypher_text);   
	
}

int get_key(char key[MAX_LENGTH])
{
    printf("get_key");
    do
    {
        printf("Key: ");
        scanf("%s ", key);    
    }while(!is_valid(key));
    
    return string_to_int(key)%26;
}

int string_to_int (char key[MAX_LENGTH])
{
    printf("string to int");
    int index = 0,key_int = 0;
    while(key[index]!='\0'){
        key_int*=10;
        key_int+=(key[index]-'0');
        index++;
    }
    return key_int;
}

int is_valid(char key[MAX_LENGTH])
{
    printf("is_valid");
    int i=0;
    
    while(key[i]!='\0')
    {
        if(key[i]-'0'<0 || key[i]-'0'>9){return 0;}
        i++;
    }
    return 1;
}


char* get_string(const char call_for_var[MAX_LENGTH])
{
    printf("get_string");
    char* input;
    printf("%s\n", call_for_var);
    scanf("%s", input);
    return input;
}

char* cypher_string(char* plain_text, int key)
{
    printf("cypher_string");
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

void print_string(char* cypher_text)
{
    printf("%s\n", cypher_text);
    return;
}
