// Sort the input elements using insertion sort algorithm

// Author: Chiranjiv Goyal
// Date: 29/01/2019

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 50

// helper function
int get_int(char call_for_var[MAX_LENGTH]);
void get_array(int array[], int size);
void print_array(int array[], int size);
void swap(int integer1, int integer2);
void Merge_sort(int array[], int size);
void merge_sort(int array[], int left_limit, int right_limit);
void merge(int array[], int left_limit, int mid, int right_limit);

int main()
{
	int size_of_array = get_int("Size: ");
	int input_array[size_of_array];
	
	get_array(input_array,size_of_array);
	Merge_sort(input_array, size_of_array);
	print_array(input_array,size_of_array);

	return 0;
}

int get_int(char call_for_var[MAX_LENGTH])
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

void Merge_sort(int array[], int size)
{
	merge_sort(array, 0, size-1);
	return;
}

void merge_sort(int array[], int left_limit, int right_limit)
{
	if(left_limit<right_limit)
	{
		int mid = (left_limit+right_limit)/2;
		merge_sort(array, left_limit, mid);
		merge_sort(array, mid+1, right_limit);
		merge(array,left_limit, mid, right_limit);
	}
}

void merge(int array[], int left_limit, int mid, int right_limit)
{
	int temp[right_limit-left_limit+1];
	int i = left_limit, j = mid+1, k=0;

	while(i<=mid && j<=right_limit)
	{
		if(array[i]<=array[j])
		{
			temp[k] = array[i];
			k+=1;i+=1;
		}
		else
		{
			temp[k] = array[j];
			k+=1;j+=1;
		}
	}

	// Add elements left in first interval
	while(i<=mid)
	{
		temp[k] = array[i];
		k+=1;i+=1;
	}


	// Add elements left in the second interval
	while(j<=right_limit)
	{
		temp[k] = array[j];
		k+=1; j+=1;
	}

	// Copy temp to original interval
	for (int i = left_limit; i < right_limit; ++i)
	{
		array[i] = temp[i-left_limit];
	}
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