#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH_ARRAY 50


// Helper Function
int get_array(int input[MAX_LENGTH_ARRAY]);
void print_majority(int input[MAX_LENGTH_ARRAY], int size, int test);
void find_majority(int input[MAX_LENGTH_ARRAY],int size);


int main()
{
    int input[MAX_LENGTH_ARRAY];

    int size = get_array(input);
    find_majority(input,size);

    return 0;
}


int get_array(int input[MAX_LENGTH_ARRAY])
{
	int size;
	printf("Size( < 50): ");
	scanf("%d", &size);

	
	for(int index = 0; index < size; index ++)
	{
		scanf("%d", &input[index]);
	}

	return size;
}


void print_majority(int input[MAX_LENGTH_ARRAY], int size, int test)
{
	int count = 0;

	for(int index = 0;index < size; index++)
	{
		if(input[index] == test)
		{
			count++;
		}
	}

	if(count > size/2)
	{
		printf(" %d \n", test);
	}
	else
	{
		printf("No Majority Element\n");
	}
	
	return;
}


void find_majority(int input[MAX_LENGTH_ARRAY],int size)
{
	int majority_ind = 0,count=1;

	for(int index = 0;index<size;index++)
	{
		if(input[index] == input[majority_ind])
		{
			count++;
		}
		else
		{
			count--;
		}

		if(count == 0)
		{
			majority_ind = index;
			count = 1;
		}
	}

	print_majority(input,size,input[majority_ind]);

	return;
}

