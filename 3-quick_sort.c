#include "sort.h"

/**
 * aux_swap - swaps two integers in an array
 * @array: array to be sorted
 * @a: index fo first integer
 * @b: index of second integer
 * @size: size of the array to be sorted
 */
void aux_swap(int *array, size_t a, size_t b, size_t size)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
	print_array(array, size);
}

/**
 * aux_part - partitions the array using the Lomuto scheme
 * @array: array to be sorted
 * @low: starting
 * @high: ending
 * @size: size of the array
 * Return: indx f the pivot after partitioning
 */
int aux_part(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			aux_swap(array, i, j, size);
		}
	}
	aux_swap(array, i + 1, high, size);
	return (i + 1);
}

/**
 * aux_qsort_help - recursive helper function for aux_qsort
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: the ending
 * @size: size of the array
 */
void aux_qsort_help(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = aux_part(array, low, high, size);
		aux_qsort_help(array, low, pi - 1, size);
		aux_qsort_help(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts array of int in asc. order using the quicksort algthm
 * @array: array to be sorted
 * @size: of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	aux_qsort_help(array, 0, size - 1, size);
}

