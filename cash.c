// Number coins in change

// Author: Chiranjiv Goyal
// Date: 25/01/2019

#include<stdio.h>
#include<math.h>

#define Max_input_number 50

// Helper functions
float get_float(const char* call_for_var);

int main(void)
{
	float change_owed_dollar = get_float("Change owed: ");
	int change_owed_cents = to_cents(change_owed_dollar);
	
	get_change(change_owed_cents);
	return 0;
} 

float get_float(const char* call_for_var)
{
	float change_owed_dollar;
	char change_owed_input[Max_input_number];

	do
	{
		printf("%s:", call_for_var);
		scanf("%s", change_owed_input);
	}while(is_valid_float(change_owed_input))
	sscanf(change_owed_input, "%f\n", &change_owed_dollar);

	return change_owed_dollar;
}

bool is_valid_float(char* change_owed_input)
{
	if(*(change_owed_input)=='-')
	{
		return false;
	}

	while(*(char_owed_input++))
	{
		if((*char_owed_input) < '0' || (*char_owed_input) > '9')
		{
			if(*(change_owed_input)=='.')
			{
				continue;
			}
			return false;
		}
	}
	return true;
}

int to_cents(float change_owed_dollar)
{
	return round(change_owed_dollar*100);
}

void get_change(int change_owed_cents)
{
	int change_left=0,change_given=0;

	change_given += change_owed_cents/25;
	change_left = change_owed_cents%25;

	change_given += change_left/10;
	change_left = change_left%10;

	change_given += change_left/5;
	change_left = change_left%5;

	change_given+=change_left;

	printf("%d\n", change_given);
	return;
}