#include "sort.h"

/**
 * swap_and_print - Swaps two integers and prints the array.
 * @array: The array to print.
 * @size: Size of the array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_and_print(int *array, size_t size, int *a, int *b)
{
	int tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_sort - Recursive function that implements the Lomuto partition.
 * @array: The array to sort.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Total size of the array (for printing).
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	if (low < high)
	{
		pivot = array[high];
		i = low;
		for (j = low; j < high; j++)
		{
			if (array[j] <= pivot)
			{
				swap_and_print(array, size, &array[i], &array[j]);
				i++;
			}
		}
		swap_and_print(array, size, &array[i], &array[high]);

		lomuto_sort(array, low, i - 1, size);
		lomuto_sort(array, i + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, 0, (int)size - 1, size);
}




