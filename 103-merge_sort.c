#include "sort.h"

/**
 * m_copyarr - copy from source to destination
 * @source: array to copy from
 * @dest: array to copy to
 * @left: index to start copying from
 * @right: index to end to copy
 *
 * Return: void
*/
void m_copyarr(int *source, int *dest, size_t left, size_t right)
{
	size_t i;

	for (i = left; i <= right; i++)
	{
		dest[i] = source[i];
	}
}


/**
 * m_print - prints a section of a given array
 * @ar: the array to print its section
 * @tmp: the string to print
 * @l: index to start printing from
 * @m: the middle of the array
 * @r: indext to end the print
 *
 * Return: void
*/
void m_print(int *ar, int *tmp, size_t l, size_t m, size_t r)
{
	size_t i;

	printf("Merging...\n");

	printf("[left]: ");
	for (i = l; i <= m; i++)
	{
		if (i > l)
			printf(", ");

		printf("%i", ar[i]);
	}

	printf("\n[right]: ");
	for (i = (m + 1); i <= r; i++)
	{
		if (i > (m + 1))
			printf(", ");

		printf("%i", ar[i]);
	}

	printf("\n[Done]: ");
	for (i = l; i <= r; i++)
	{
		if (i > l)
			printf(", ");

		printf("%i", tmp[i]);
	}
	printf("\n");
}


/**
 * merger - function to merge the atomized elements of the array
 * @ar: main array that is atomized
 * @tmp: temporary array
 * @l: left index
 * @m: middle index
 * @r: right index
 *
 * Return: void
*/
void merger(int *ar, int *tmp, size_t l, size_t m, size_t r)
{
	size_t i, a, b;

	a = l;
	b = m + 1;

	for (i = l; a <= m && b <= r; i++)
	{
		if (ar[a] < ar[b])
			tmp[i] = ar[a++];
		else
			tmp[i] = ar[b++];
	}

	while (a <= m)
		tmp[i++] = ar[a++];

	while (b <= r)
		tmp[i++] = ar[b++];

	m_print(ar, tmp, l, m, r);
	m_copyarr(tmp, ar, l, r);
}

/**
 * m_sort - funtion that uses recurssion to break the array
 * @ar: the array to be broken and merged
 * @tmp: temporary array to store values
 * @l: left value
 * @r: right value
 *
 * Return: void
*/
void m_sort(int *ar, int *tmp, size_t l, size_t r)
{
	size_t m;

	if (l >= r)
		return;

	if ((l + r) % 2 == 0)
		m = (l + r) / 2 - 1;
	else
		m = (l + r) / 2;

	m_sort(ar, tmp, l, m);
	m_sort(ar, tmp, (m + 1), r);
	merger(ar, tmp, l, m, r);
}

/**
 * merge_sort - implementation of merge sorting
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t left, right;
	int *temp_array;

	if (size < 2)
		return;

	temp_array = (int *)malloc(sizeof(int) * size);

	if (temp_array == NULL)
		return;

	left = 0;
	right = size - 1;

	m_sort(array, temp_array, left, right);

	free(temp_array);
}
