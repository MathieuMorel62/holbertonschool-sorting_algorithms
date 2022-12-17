#include "sort.h"

/**
 * quick_sort_recursive - Recursively sort an array of integers using the
 * Quick sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 * @low: The lower bound of the partition
 * @high: The upper bound of the partition
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot;
	/* If the lower bound is less than the upper bound, */
	/* then there are*elements in the partition that need to be sorted.*/
	if (low < high)
	{
		/* Partition the array and get the index of the pivot element */
		pivot = lomuto_partition(array, size, low, high);

		/* Recursively sort the left partition */
		quick_sort_recursive(array, size, low, pivot - 1);

		/* Recursively sort the right partition */
		quick_sort_recursive(array, size, pivot + 1, high);
	}
}

/**
 * lomuto_partition - Partition an array using the Lomuto partition scheme
 *
 * @array: The array to partition
 * @size: The size of the array
 * @low: The lower bound of the partition
 * @high: The upper bound of the partition
 *
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	/* Set the pivot element to the last element in the partition */
	pivot = array[high];

	/* Check if all elements in the array are equal to the pivot */
	for (i = low; i < high; i++)
	{
		if (array[i] != pivot)
			break;
	}
	/* If all elements are equal, return the pivot index */
	if (i == high)
		return high;

	/* Set the index of the first element to the lower bound */
	i = low;
    /* Iterate over the elements in the partition */
	for (j = low; j < high; j++)
	{
		/* If the current element is smaller than the pivot, then swap it with */
		/* the element at index i and increment i */
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	/* Swap the pivot element with the element at index i */
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	/* Return the index of the pivot element */
	return (i);
}

/**
 * quick_sort - Sort an array of integers using the Quick sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	/* Return if the array is NULL or has fewer than 2 elements */
	if (array == NULL || size < 2)
		return;
	/* Call the recursive function to sort the array */
	quick_sort_recursive(array, size, 0, size - 1);
}

/**
 * swap - Swap two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
