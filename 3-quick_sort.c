#include "sort.h"
#include <stdio.h>
/**
 * swap - swaps two array elements
 * @a: integer to be swapped
 * @b: integer to be swapped
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - Finds the pivot index based on Lomuto
 * @array: array to be check for pivot index
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 *
 * Return: a positive integer
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quick_sort_recursively - Sorts an array recursively based on pivot index
 * @array: array to be sorted
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 */
void quick_sort_recursively(int *array, size_t low, size_t high, size_t size)
{
	size_t p_index;

	if (low < high)
	{
		p_index = partition(array, low, high, size);
		if (p_index > 0)
			quick_sort_recursively(array, low, p_index - 1, size);
		if (p_index < high)
			quick_sort_recursively(array, p_index + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array to besorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursively(array, 0, size - 1, size);
}
