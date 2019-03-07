// Sort the input elements using insertion sort algorithm

// Author: Chiranjiv Goyal
// Date: 29/01/2019

#include<stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 50

// helper function
int get_int(char call_for_var[MAX_LENGTH]);
void get_array(int array[], int size);
void insertion_sort(int array[], int size);
void print_array(int array[], int size);
void swap(int integer1, int integer2);

int main()
{
	int size_of_array = get_int("Size: ");
	int input_array[size_of_array];
	
	get_array(input_array,size_of_array);
	insertion_sort(input_array, size_of_array);
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

void insertion_sort(int array[], int size)
{
	for(int i = 0;i < size-1; i++){
		for (int j = i+1; j < size; ++j)
		{
			if(array[i]>array[j])
			{
				swap(array[i], array[j]);
			}
		}
	}

	return;
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