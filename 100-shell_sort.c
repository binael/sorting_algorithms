#include "sort.h"

/**
* shell_sort - Implement shell sort sorting
*
* @array: array of integers
* @size: size of array
*/

void shell_sort(int *array, size_t size)
{
	size_t interval;

	if (array == NULL || size == 0)
	{
		return;
	}

	interval = 1;

	while (interval < size)
	{
		interval = (interval * 3) + 1;
	}

	interval = interval / 3;

	while (interval >= 1)
	{
		interval_insertion(array, (int)size, (int)interval);
		print_array(array, size);
		interval /= 3;
	}
}


/**
* power - function to find the power of a number
*
* @number: number to find the power
* @power: the power of the number
*
* Return: the number raised to the power
*/
size_t power(size_t number, size_t power)
{
	size_t i, result = 1;

	if (power == 0)
	{
		return (1);
	}
	for (i = 0; i < power; i++)
	{
		result *= number;
	}
	return (result);
}


/**
* interval_insertion - insertion sort at a given interval
*
* @array: array to perform the insertion at interval sort
* @size: array size
* @interval: intervals to implement insertion sort
*
* Return: void
*/
void interval_insertion(int *array, int size, int interval)
{
	int temp, i, j;

	j = interval;

	while (j < size)
	{
		i = j - interval;

		while (i >= 0)
		{
			if (array[i] > array[i + interval])
			{
				temp = array[i];
				array[i] = array[i + interval];
				array[i + interval] = temp;
			}
			else
			{
				break;
			}
			i = i - interval;
		}
		j++;
	}
}
