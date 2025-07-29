#ifndef REGEX_H
#define REGEX_H

/**
 * regex_match - Checks if a string matches a pattern
 * @str: The string to check
 * @pattern: The pattern to match (supports '.' and '*')
 *
 * Return: 1 if there's a match, 0 otherwise
 */
int regex_match(const char *str, const char *pattern);

#endif /* REGEX_H */
