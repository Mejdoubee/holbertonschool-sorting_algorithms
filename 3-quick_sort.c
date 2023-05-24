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
* _lomuto_partition - partitions the array and swaps values
* @array: array to be partitioned and sorted
* @low: starting index of the array
* @high: ending index of the array/sub-array
* @size: size of the original array
*
* Return: final partition index
*/
int _lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				_swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		_swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
* _quick_sort_lomuto - sorts a partition of an array of integers
* @array: array to be sorted
* @low: starting index of the array
* @high: ending index of the array/sub-array
* @size: size of the original array
*
* Return: void
*/
void _quick_sort_lomuto(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = _lomuto_partition(array, low, high, size);
		_quick_sort_lomuto(array, low, pivot - 1, size);
		_quick_sort_lomuto(array, pivot + 1, high, size);
	}
}

/**
* quick_sort - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array to be sorted
* @size: size of the array
*
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_quick_sort_lomuto(array, 0, size - 1, size);
}
