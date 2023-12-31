#include "sort.h"

/**
 * bubble_sort - sort an array using the bubble sort algorithm
 * @array: the array to sort
 * @size: the size fo the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped, tmp;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				print_array(array, size);
				swapped = 1;
			}
		}

		if (swapped == 0)
			return;
	}
}
