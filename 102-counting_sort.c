#include "sort.h"

/**
 * find_max - function to find the maximum integer in an array
 * @array: the array to find the maximum integer
 * @size: array size
 *
 * Return: maximum integer or -1 if failure
*/
int find_max(int *array, size_t size)
{
	size_t i;
	int maximum;

	if (size < 1)
		return (-1);

	maximum = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > maximum)
		{
			maximum = array[i];
		}
	}
	return (maximum);
}


/**
 * arraycpy - function to copy integers from one array to another
 * @array: array to copy from
 * @new_arr: array to copy to
 * @size: size of array 1 or array 2, both are equal in size
 *
 * Return: void
*/
void arraycpy(int *array, int *new_arr, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		new_arr[i] = array[i];
	}
}


/**
 * set_array - function sets an integer value to all indexed of
 * an array
 * @array: the array to set
 * @size: size of the array
 * @value: the value of integer to set
 *
 * Return: void
*/
void set_array(int *array, size_t size, int value)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		array[i] = value;
	}
	array[i] = '\0';
}


/**
 * counting_sort - implementation of counting sort algorithm
 * @array: the pointer to the array
 * @size: the array size
 *
 * Return: void
*/
void counting_sort(int *array, size_t size)
{
	int index, j, max, *count_arr, *ar_cpy;
	size_t i;

	if (size < 2 || array == NULL)
		return;

	max = find_max(array, size);

	ar_cpy = malloc(sizeof(int) * size);
	count_arr = malloc(sizeof(int) * (max + 1));

	if (count_arr == NULL || ar_cpy == NULL)
		return;

	arraycpy(array, ar_cpy, size);
	set_array(count_arr, (size_t)(max + 1), 0);

	for (i = 0; i < size; i++)
		count_arr[array[i]] += 1;

	for (j = 1; j <= max; j++)
		count_arr[j] += count_arr[j - 1];

	print_array(count_arr, (size_t)(max + 1));

	for (i = 0; i < size; i++)
	{
		index = count_arr[ar_cpy[i]];
		array[index - 1] = ar_cpy[i];
		count_arr[ar_cpy[i]] = index - 1;
	}

	free(ar_cpy);
	free(count_arr);
}
