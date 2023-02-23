#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;

	while (array && i < size)
	{
		if (i > 0)
		{
			printf(", ");
		}

		printf("%d", array[i]);
		++i;
	}

	printf("\n");
}

void print_list(const listint_t *list)
{
	int i;

	i = 0;

	while (list)
	{
		if (i > 0)
		{
			printf(", ");
		}

		printf("%d", list->n);
		++i;
		list = list->next;
	}

	printf("\n");
}

void clockwise(int *array, size_t size)
{
	int temp1;
	int temp2;
	size_t i;

	if (array == NULL)
		return;
	
	if (size <= 1)
		return;

	temp1 = array[0];
	for (i = 1; i < size; i++)
	{
		temp2 = array[i];
		array[i] = temp1;
		temp1 = temp2;
	}
}

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

int main(void)
{
    int array[] = {19, 48, 99, 86, 71, 13, 7, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    clockwise(array, n);
    printf("\n");
    print_array(array, n);
	printf("%i\n", find_max(array, n));
    return (0);
}
