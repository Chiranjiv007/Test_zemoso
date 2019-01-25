// Print mario pyramid

// Author: Chiranjiv Goyal
// Date: 25/01/2019

#include <cs50.h>
#include <stdio.h>

// Helper Functions
int get_int(const char* call_for_var);
bool is_valid(int height);
void print_pyramid(int n);


int main(void)
{
    int height = get_int("Height: ");
    print_pyramid(height);    
    return 0;
}


int get_int(const char* call_for_var)
{
    int height_input;
    do
    {
        printf("%s", call_for_var);
        scanf("%d", &height_input);
        printf("\n");
    }while(!is_valid(height_input));
    return height_input;
}


bool is_valid(int height_input)
{
    if(height_input <= 0 || height_input > 8)
    {
        return false;
    }
    return true;
}


void print_pyramid(int height)
{
    for(int hash_itr = 1; hash_itr <= height; hash_itr++)
    {
        for(int i = 0; i <height-itr; i++)
        {
            printf(" ");
        }
        
        for(int i = 0; i < hash_itr; i++)
        {
            printf("#");
        }
        
        printf("  ");
        
        for(int i = 0; i < hash_itr; i++){
            printf("#");
        }
        
        for(int i = 0; i < height-hash_itr; i++){
            printf(" ");
        }
        
        printf("\n");
    }
    return;
}
