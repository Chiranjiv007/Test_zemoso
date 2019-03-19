#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LETTER 100
#define MAX_DIGIT 15

void get_letter(char* Number_digit);
int isdigit(char* num);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./question Number\n");
        return 1;
    }

    if(isdigit(argv[1]) == 0){
        printf("Usage: ./question1 Number\n");
        return 2;
    } 


    get_letter(argv[1]);

    return 0;
}

int isdigit(char* num)
{
    int index =0;
    while(num[index] != '\0')
    {
        if(num[index]-'0'<0 || num[index]-'0' > 9)
        {
            return 0;
        }
        index++;
    }
    return 1;
}


void get_letter(char* num)
{
    int len = strlen(num);
  
    /* Base cases */
    if (len == 0) { 
        fprintf(stderr, "empty string\n"); 
        return; 
    } 
    if (len > 13) { 
        fprintf(stderr, "Length more than 13 is not supported\n"); 
        return; 
    } 
  
    
    char *single_digits[] = { "zero", "one", "two",  
                               "three", "four","five",  
                               "six", "seven", "eight", "nine"}; 
  
   
    char *two_digits[] = {"", "ten", "eleven", "twelve",  
                               "thirteen", "fourteen", 
                               "fifteen", "sixteen",  
                               "seventeen", "eighteen", "nineteen"}; 
  
   
    char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty", 
                            "sixty", "seventy", "eighty", "ninety"}; 
  
    char *tens_power[] = {"", "thousand","million","billion","trillion"}; 
  
    
    if (len == 1) { 
        printf("%s\n", single_digits[*num - '0']); 
        return; 
    } 

    if (len == 13) { 
        if (*num -'0' != 0) { 
            printf("%s ", single_digits[*num - '0']); 
            printf("trillion"); 
        } 
        return;
    }
  
    
    while (*num != '\0') { 
        int temp_len = len%3;

        if(len%3 == 0)
        {
            if (*num -'0' != 0) { 
                printf(" %s ", single_digits[*num - '0']); 
                printf("hundred"); 
            } 
            num++;
        }
  
  
        else if(len%3 == 2 || temp_len==2) 
        { 
            
            if (*num == '1')
             { 
                int sum = *num - '0' + *(num + 1)- '0'; 
                printf(" %s ", two_digits[sum]);  
                num = num+2;
            } 
  
            else { 
                int i = *num - '0'; 
                printf(" %s ", i? tens_multiple[i]: ""); 
                 
                 ++num;
                if (*(num) != '0') 
                {
                    printf("%s ", single_digits[*num - '0']);
                } 
                ++num;
            } 
        } 

        else if(len%2 == 1)
        {
            if (*num != '0') 
            {
                printf(" %s ", single_digits[*num - '0']);
            }
            num++;

        }

        if(len%3 == 0){
            len = len - 1;
        }
        else
        {
            printf("%s ", tens_power[(len-1)/3]);
            len = len - len%3;
        }
    }

    return;
    
}
