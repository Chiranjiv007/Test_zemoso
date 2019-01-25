// Validate and Return credit-card type

// Author: Chiranjiv Goyal
// Date: 24-01-2019


#include<cs50.h>
#include<stdio.h>

#define Max_input_char 50

//Helper function
long long get_long(const char* call_for_var);
bool is_valid(long long card_number);
int get_card_type(long long card_number);
bool is_digt_format(char_input_number);


int main(void)
{
	// Get card number
    long long card_number = get_long("Number: ");
    long long card_number_copy = card_number;

	// Validate by Lunn's algorithm
	if(is_valid(card_number))
	{
		get_card_type(card_number);
	}
	else
	{
		printf("INVALID\n");		
	}

    return 0;

}

long long get_long(char* call_for_var){
	
	long long card_number;
	char char_input_number[Max_input_char];

	do
	{
		printf("%s", call_for_var);
		scanf("%s\n", char_input_number);
		printf("\n");
	}while(!is_digt_format(char_input_number))
	
	sscanf(char_input_number,"%d\n", &card_number);
	return card_number;

}

// Lunn's Algorithm
bool is_valid(long long card_number)
{
	int sum_from_last = get_alternate_sum(card_number);
	int sum_from_second_last = 2*get_alternate_sum(card_number/10);
	int sum = sum_from_last + sum_from_second_last;

	if(sum%10 != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int get_card_type(long long card_number){

	if((length(card_number)==13 && temp%10000000000000==4) || (length(card_number)==16 && temp%10000000000000000==4))
    {
        printf("VISA\n");
    }
    else if(length(card_number)==16 && (temp%1000000000000000>=51 && temp%1000000000000000<=55))
    {
        printf("MASTERCARD\n");
    }
    else if(length(card_number)==15 && (temp%100000000000000==34 || temp%100000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

bool is_digt_format(const char* char_input_number)
{

	while(*(char_input_number++))
	{
		if((*char_input_number) < '0' || (*char_input_number) > '9')
		{
			return false;
		}
	}
	return true;
}
