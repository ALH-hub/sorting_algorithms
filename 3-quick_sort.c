#include "sort.h"

/**
 * partition - parition the array of int to sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: the index of the partitioned point in the array
 */
int partition(int *array, size_t size)
{
	int pivot = array[size - 1];
	size_t i = 0, j;

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[j], &array[i]);
			print_array(array, size);
			i++;
		}
	}

	swap(&array[i], &array[size - 1]);
	print_array(array, size);
	return (i);
}

/**
 * quick_sort - sort the array of int using quick sort algo
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	int partitionIndex;

	if (size <= 1)
	{
		return;
	}

	partitionIndex = partition(array, size);

	quick_sort(array, partitionIndex);
	quick_sort(array + partitionIndex + 1, size - partitionIndex - 1);
}


/**
 * swap - swap two integers
 * @a: first value
 * @b: second value
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
