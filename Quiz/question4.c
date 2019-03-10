#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH_ARRAY 50

// Helper function
int is_found(int input_short[MAX_LENGTH_ARRAY],int size, int val);
void get_ans(int input_short[MAX_LENGTH_ARRAY],int input_long[MAX_LENGTH_ARRAY],int size_short,int size_long);
int get_array(int input[MAX_LENGTH_ARRAY]);
int until_all_found(int input_short[MAX_LENGTH_ARRAY],int input_long[MAX_LENGTH_ARRAY], int size_short,int size_long,int index);
int All_positive(int count[100001],int input_short[MAX_LENGTH_ARRAY],int size_short);

int main()
{
    int input_short[MAX_LENGTH_ARRAY],input_long[MAX_LENGTH_ARRAY];

    int size_short = get_array(input_short);
    int size_long = get_array(input_long);


    printf("reached Here\n");
    get_ans(input_short,input_long,size_short,size_long);

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


int is_found(int input_short[MAX_LENGTH_ARRAY],int size, int val)
{
	for(int i=0;i<size;i++)
	{
		if(input_short[i]==val)
		{
			return 1;
		}
	}

	return 0;
}


int All_positive(int count[100001],int input_short[MAX_LENGTH_ARRAY],int size_short)
{
	int c = 0;
	for(int i = 0;i<size_short;i++)
	{
		if(count[input_short[i]]>0)
		{
			c++;
		}
	}

	if(c == size_short)
	{
		return 1;
	}

	return 0;
}


int until_all_found(int input_short[MAX_LENGTH_ARRAY],int input_long[MAX_LENGTH_ARRAY],
					int size_short,int size_long,int index)
{
	int count[100001] = {0};

	while(1)
	{
		if(is_found(input_short,size_short,input_long[index]))
		{
			count[input_long[index]]++;
		}

		if(All_positive(count,input_short,size_short))
		{
			break;
		}

		index++;
	}

	return index;
}

void get_ans(int input_short[MAX_LENGTH_ARRAY],int input_long[MAX_LENGTH_ARRAY],int size_short,int size_long)
{

	int min_index, min_window_size = MAX_LENGTH_ARRAY+1;
	for(int i = 0;i<size_long-size_short+1;i++)
	{
		if(is_found(input_short,size_short,input_long[i]))
		{
			int last_index = until_all_found(input_short,input_long,size_short,size_long,i);

			if(last_index-i < min_window_size)
			{
				min_window_size = last_index-i+1;
				min_index = i;
			}

		}

	}

	printf("{%d,%d}\n",min_index,min_index+min_window_size-1);
	return;
}