#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers to the left or right
 * @line: array of integers
 * @size: size of the array
 * @direction: direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 on success, 0 on failure
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t i, j;
	int merged = 0;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return 0;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; ++i)
		{
			if (line[i] == 0)
				continue;
			for (j = i + 1; j < size; ++j)
			{
				if (line[j] != 0)
				{
					if (line[i] == line[j] && !merged)
					{
						line[i] *= 2;
						line[j] = 0;
						merged = 1;
					}
					break;
				}
			}
			merged = 0;
		}
		for (i = 0, j = 0; i < size; ++i)
		{
			if (line[i] != 0)
			{
				if (i != j)
				{
					line[j] = line[i];
					line[i] = 0;
				}
				++j;
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = size; i > 0; --i)
		{
			if (line[i - 1] == 0)
				continue;
			for (j = i - 1; j > 0; --j)
			{
				if (line[j - 1] != 0)
				{
					if (line[i - 1] == line[j - 1] && !merged)
					{
						line[i - 1] *= 2;
						line[j - 1] = 0;
						merged = 1;
					}
					break;
				}
			}
			merged = 0;
		}
		for (i = size, j = size; i > 0; --i)
		{
			if (line[i - 1] != 0)
			{
				if (i != j)
				{
					line[j - 1] = line[i - 1];
					line[i - 1] = 0;
				}
				--j;
			}
		}
	}
	return 1;
}
