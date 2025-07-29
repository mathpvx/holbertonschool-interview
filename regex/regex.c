#include "regex.h"

/**
 * regex_match - checks if a string matches a pattern
 * @str: the string to check
 * @pattern: the pattern to match (supports '.' and '*')
 *
 * Return: 1 if there's a match, 0 otherwise
 */
int regex_match(const char *str, const char *pattern)
{
	int first_match;

	if (!pattern || !str)
		return (0);

	/* If pattern is empty, return true only if str is also empty */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Check if current character matches */
	first_match = (*str && (*str == *pattern || *pattern == '.'));

	/* Handle * operator */
	if (*(pattern + 1) == '*')
	{
		return (
			regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern))
		);
	}

	/* No star, just move forward if match */
	return (first_match && regex_match(str + 1, pattern + 1));
}
