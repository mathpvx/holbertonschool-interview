#include <stdio.h>
#include "menger.h"

/**
 * is_filled - tell if a cell is filled or empty
 * @x: column index
 * @y: row index
 *
 * Return: 1 if filled, 0 if empty
 *
 * A cell is empty if, at any scale, both base-3 digits are 1.
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
 * pow3 - compute 3 to the power n
 * @n: exponent (>= 0)
 *
 * Return: 3^n
 */
static int pow3(int n)
{
	int r = 1;

	while (n-- > 0)
		r *= 3;
	return (r);
}

/**
 * menger - draw a 2D Menger sponge
 * @level: level of the sponge
 *
 * If level < 0, do nothing.
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
