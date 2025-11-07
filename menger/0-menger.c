#include <stdio.h>
#include "menger.h"

/**
 * is_filled - decide if a cell (x,y) is part of the sponge (filled) or a hole
 * @x: column index
 * @y: row index
 *
 * Return: 1 if filled (‘#’), 0 if hole (‘ ’)
 *
 * A cell is a hole if at any scale its base-3 digits have (1,1) simultaneously.
 */
static int is_filled(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

/**
 * pow3 - compute 3^n using integers
 * @n: exponent (>= 0)
 *
 * Return: 3^n
 */
static int pow3(int n)
{
	int i, r = 1;

	for (i = 0; i < n; i++)
		r *= 3;
	return (r);
}

/**
 * menger - draw a 2D Menger sponge of a given level
 * @level: level of the sponge (>= 0). If < 0, do nothing.
 *
 * Description: prints to stdout using ‘#’ for filled cells and ‘ ’ for holes.
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow3(level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
			putchar(is_filled(col, row) ? '#' : ' ');
		putchar('\n');
	}
}
