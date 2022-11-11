#include "sort.h"

/**
* quick_sort - Implementation of quick_sort using Lomuto partition
*
* @array: array of integers
* @size: array size
*/

void quick_sort(int *array, size_t size)
{
	int my_size = (int)size;

	if (!array || my_size < 0)
	{
		return;
	}

	sorted(array, 0, my_size - 1, size);
}


/**
* sorted - recursive call of the the partitions of quick sort
*
* @array: array of integers
* @first: the pointer(or origin) to the first array element
* @last: the pointer to the last array element
* @n: size of array
*
* Return: void
*/
void sorted(int *array, int first, int last, size_t n)
{
	if (first < last)
	{
		int pivot = partition(array, first, last, n);

		sorted(array, first, pivot - 1, n);

		sorted(array, pivot + 1, last, n);
	}
}


/**
* partition - the sorting of each partition
*
* @array: array of integers
* @first: the pointer to the first array element
* @last: the pointer to the last array element
* @n: size of array
*
* Return: void
*/
int partition(int *array, int first, int last, size_t n)
{
	int j = first + 1;
	int i = first;
	int temp;

	while (j < last && first >= 0)
	{
		if (array[i] <= array[last])
			i++, j++;
		else if (array[j] < array[last])
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, n);
			j++, i++;
		}
		else
			j++;
	}
	if (array[j] <= array[i])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		if (array[i] != array[j])
			print_array(array, n);
	}
	else
	{
		i++;
	}
	return (i);
}
