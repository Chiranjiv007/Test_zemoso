// Sort the input elements using insertion sort algorithm

// Author: Chiranjiv Goyal
// Date: 29/01/2019

#include <stdio.h>
#include <cs50.h>

// helper functions
int get_int(char* call_for_var);
void get_array(int array[], int size);
void quick_sort(int array[], int size);
void Quick_sort(int array[], int left_limit, int right_limit);
int partition(int array[], int left_limit, int right_limit);
void print_array(int array[], int size);
void swap(int integer1, int integer2);

int main()
{
	int size_of_array = get_int("Size: ");
	int input_array[size_of_array];
	
	get_array(input_array,size_of_array);
	quick_sort(input_array, size_of_array);
	print_array(input_array,size_of_array);

	return 0;
}

int get_int(char* call_for_var)
{
	int value;
	printf("%s\n", call_for_var);
	scanf("%d", &value);
	return value;
}

void get_array(int array[], int size)
{
	printf("Input the array: ");
	for (int index = 0; index < size; index++)
	{
		scanf("%d\n", &array[index]);
	}
	return;
}

void quick_sort(int array[], int size_of_array)
{
	Quick_sort(array,0,size_of_array-1);
	return;
}

void Quick_sort(int array[], int left _limit, int right_limit)
{
	if(left_limit<right_limit)
	{
		pivot = partition(array,left_limit,right_limit);
		Quick_sort(array,left_limit,pivot-1);
		Quick_sort(array,pivot+1,right_limit);
	}
	return;
}

int partition(int array[], int left_limit, int right_limit)
{
	int pivot = array[right_limit];
	int final_pivot = left_limit-1;
	for (int i = left_limit; i < right_limit; ++i)
	{
		if(array[i]<=pivot)
		{
			final_pivot=final_pivot+1;
			swap(A[final_pivot],A[i]);
		}
	}
	swap(array[final_pivot+1],array[right_limit]);
	return final_pivot;
}

void swap(int integer1, int integer2)
{
	int temp;
	
	temp = integer1;
	integer1 = integer2;
	integer2 = integer1;

	return;
}

void print_array(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n", array[i]);
	}

	return;
}