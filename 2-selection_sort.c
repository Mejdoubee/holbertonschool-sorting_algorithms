#include "sort.h"

/**
* _swap - swaps the values of two integers
* @a: the first integer to be swapped
* @b: the second integer to be swapped
*
* Return: void
*/
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* selection_sort - sorts an array of integers in ascending order
* using the Selection Sort algorithm
* @array: pointer to the array to be sorted
* @size: the number of elements in the array
*
* Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min;

	if (!array || size < 2)
	{
		return;
	}

	for (; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			_swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
