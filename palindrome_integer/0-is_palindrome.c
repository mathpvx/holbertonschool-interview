#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned long is a palindrome
 * @n: number to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, original = n, digit;

	while (n != 0)
	{
		digit = n % 10;
		reversed = reversed * 10 + digit;
		n /= 10;
	}

	if (original == reversed)
		return (1);
	return (0);
}
