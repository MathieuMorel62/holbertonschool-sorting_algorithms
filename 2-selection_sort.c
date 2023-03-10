#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 *                  selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of te array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			/* Swap array[i] and array[min_index] */
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			/* Print the array after the swap */
			print_array(array, size);
		}
	}
}
