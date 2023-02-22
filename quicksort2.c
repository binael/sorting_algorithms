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

size_t partition(int *array, int first, int last, size_t size)
{
	int i, position = first;
	int temp;

	for (i = first; i <= last; i++)
	{
		if (array[last] >= array[i])
		{
			if (i != position)
			{
				temp = array[position];
				array[position] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			position++;
		}
	}
	return (position - 1);
}
void sorter(int *array, int first, int last, size_t size)
{
	int position;

	if (first >= last || first < 0)
	{
		return;
	}

	position = partition(array, first, last, size);

	sorter(array, first, position - 1, size);
	sorter(array, position + 1, last, size);
}


void quick_sort(int *array, size_t size)
{
	sorter(array, 0, (int)size - 1, size);
}

int main(void)
{
    int array[] = {19, 48, 99, 86, 71, 13, 7, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
