#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

static void merge_sort_rec(int *array, int *buff, size_t left, size_t right);
static void merge_parts(int *array, int *buff, size_t left,
		size_t mid, size_t right);

/**
 * merge_sort - Sort an array of integers in ascending order using Merge Sort
 * @array: Pointer to the array
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_rec(array, buff, 0, size);

	free(buff);
}

/**
 * merge_sort_rec - Recursively split, sort, and merge subarrays
 * @array: Pointer to the array
 * @buff: Buffer used for merging
 * @left: Left index (inclusive)
 * @right: Right index (exclusive)
 */
static void merge_sort_rec(int *array, int *buff, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;

	merge_sort_rec(array, buff, left, mid);
	merge_sort_rec(array, buff, mid, right);
	merge_parts(array, buff, left, mid, right);
}

/**
 * merge_parts - Merge two sorted halves of an array
 * @array: Pointer to the array
 * @buff: Buffer used for merging
 * @left: Left index (inclusive)
 * @mid: Middle index (start of right half)
 * @right: Right index (exclusive)
 */
static void merge_parts(int *array, int *buff, size_t left,
		size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;
	k = left;

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			buff[k++] = array[i++];
		else
			buff[k++] = array[j++];
	}

	while (i < mid)
		buff[k++] = array[i++];

	while (j < right)
		buff[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buff[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
