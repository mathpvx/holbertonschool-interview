#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_recursively - Recursively checks if the list is a palindrome.
 * @start: Double pointer tracking the front of the list.
 * @end: Pointer moving to the end of the list to compare values.
 *
 * Description: Traverses to the end of the list recursively. Compares values from
 *              @start and @end on the return path to check palindrome properties.
 *              Moves @start forward post-recursion to check the next pair.
 *
 * Return: 1 if the sublist is a palindrome, 0 otherwise.
 */
int check_recursively(listint_t **start, listint_t *end)
{
	int check;

	if (end == NULL)
		return 1; /* Base case: end of list */

	check = check_recursively(start, end->next);
	if (check == 0)
		return 0; /* Early termination if mismatch found */

	check = ((*start)->n == end->n) ? 1 : 0;
	*start = (*start)->next; /* Advance start for next comparison */

	return check;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Pointer to the start of the list.
 *
 * Description: Uses recursion to check for palindrome by comparing
 *              nodes from start to end.
 *
 * Return: 1 if palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL)
		return 1; /* Consider empty list a palindrome */

	return check_recursively(head, *head);
}
