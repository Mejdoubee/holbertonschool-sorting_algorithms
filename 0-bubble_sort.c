#include "sort.h"

/**
* bubble_sort - function that sorts an array of integers in ascending order
*				using the Bubble sort algorithm
*
* @array: The array to be sorted
* @size: Number of elements in array
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp_swap;

	if (!array || size < 2)
		return;

	for (; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp_swap = array[j], array[j] = array[j + 1], array[j + 1] = temp_swap;
				print_array(array, size);
			}
		}
	}
}
