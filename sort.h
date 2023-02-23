#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* struct listint_s - Doubly list node
*
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

void counting_sort(int *array, size_t size);
int find_max(int *array, size_t size);
void arraycpy(int *array, int *new_arr, size_t size);
void set_array(int *array, size_t size, int value);

void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int partition(int *array, int first, int last, size_t n);
void sorted(int *array, int first, int last, size_t n);
void interval_insertion(int *array, int size, int interval);
size_t power(size_t number, size_t power);
int compare_swap(listint_t **list, listint_t **node1, listint_t **node2);
/* void sort_deck(deck_node_t **deck); */

#endif /* End of sort header */
