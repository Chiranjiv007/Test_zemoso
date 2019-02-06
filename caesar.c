// Encrypt String 

// Author: Chiranjiv Goyal
// Date: 05/02/2019

#include <stdio.h>
#include <string.h>


// Helper functions
int get_int(const char* call_for_var);
char* get_string(const char* call_for_var);
char* cypher_string(char* plain_text, int key);
void print_string(char* cypher_text);

int main()
{
    
    char* plain_text = get_string("Plain text:");
    int key = get_int("Key: ");

    char* cypher_text = cypher_string(plain_text,key);
    print_string(cypher_text);   
	
}

int get_int(const char* call_for_var)
{
	int value;
	printf("%s\n", call_for_var);
	scanf("%d", &value);
	return value;
}

char* get_string(const char* call_for_var)
{
    char* input;
    printf("%s\n", call_for_var);
    scanf("%s", input);
    return input;
}

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

    }
    return plain_text;
}

void print_string(char* cypher_text)
{
    printf("%s\n", cypher_text);
    return;
}
