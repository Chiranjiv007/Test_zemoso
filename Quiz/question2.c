#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH_ARRAY 50

// Helper Function
int get_array(int input_one[MAX_LENGTH_ARRAY]);
int sum_of_array(int array[MAX_LENGTH_ARRAY],int size);
void find_print_pair(int input_one[MAX_LENGTH_ARRAY],int input_two[MAX_LENGTH_ARRAY],int size_one,int size_two,int difference_sum);


int main()
{
    int input_one[MAX_LENGTH_ARRAY],input_two[MAX_LENGTH_ARRAY];

    int size_one = get_array(input_one);
    int size_two = get_array(input_two);
	int difference_sum = sum_of_array(input_one,size_one)-sum_of_array(input_two,size_two);
    

    if(difference_sum%2 != 0)
    {
    	printf("Not possible\n");
    	return 0;
    }

    find_print_pair(input_one,input_two,size_one,size_two,difference_sum/2);

    return 0;
}


int get_array(int input_one[MAX_LENGTH_ARRAY])
{
	int size;
	printf("Size( < 50): ");
	scanf("%d", &size);

	
	for(int index = 0; index < size; index ++)
	{
		scanf("%d", &input_one[index]);
	}

	return size;
}


int sum_of_array(int array[MAX_LENGTH_ARRAY],int size)
{
	int sum = 0; 
    for (int i = 0; i < size; i++) 
        sum += array[i]; 
    return sum;
}


void find_print_pair(int input_one[MAX_LENGTH_ARRAY],int input_two[MAX_LENGTH_ARRAY],int size_one,int size_two,int difference_sum)
{
	int count_possible = 0;

	int iter_1,iter_2;
	for(int index_one = 0; index_one < size_one; index_one++)
	{
		for(int index_two = 0; index_two < size_two; index_two++)
		{
			if(input_one[index_one] - input_two[index_two] == difference_sum)
			{

				iter_1 = input_one[index_one];
				iter_2 = input_two[index_two];
				count_possible++;
			}
		}
	}

	if(count_possible = 0)
	{
		printf("Not Possible\n");
		return;
	}

	printf("From Array one: %d", iter_1);
	printf(", From Array two: %d\n", iter_2);
	return;	
}