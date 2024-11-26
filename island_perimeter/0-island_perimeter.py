#!/usr/bin/python3
"""
Module that provides the island_perimeter function.
"""


def island_perimeter(grid):
    """Calculate the perimeter of an island represented in a grid.

    Args:
        grid (list of list of int): A grid where 0 represents water and 1
            represents land.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    m = len(grid)
    n = len(grid[0])

    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                for dx, dy in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
                    new_i, new_j = i + dx, j + dy
                    if (new_i >= m or new_j >= n or new_i < 0 or new_j < 0 or
                            grid[new_i][new_j] == 0):
                        perimeter += 1

    return perimeter
