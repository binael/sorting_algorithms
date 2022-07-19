#include "sort.h"

/**
* bubble_sort - Sort using bubble sort algorithm
*
* @array: array of integers
* @size: array size
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, checker;

	if (size <= 1 || array == NULL)
	{
		return;
	}

	for (i = 0; i < (size - 1); i++)
	{
		checker = 0;

		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
				checker = 1;
			}
		}
		if (checker == 0)
		{
			break;
		}
	}
}
