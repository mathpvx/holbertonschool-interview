#!/usr/bin/python3
'''calculates the perimeter of the lands represented by 1 considering length of a 1 cell is 1'''

def island_perimeter(grid):
    perimeter = 0

    for row in range(len(grid)):
        for column in range(len(grid[0])):
            # If the cell is land
            if grid[r][c] == 1:
                # Start with 4 sides
                perimeter += 4
                # Check the cell above
                if r > 0 and grid[r-1][c] == 1:
                    # Shared edge with the cell above
                    perimeter -= 2
                
                # Check the cell to the left
                if c > 0 and grid[r][c-1] == 1:
                    # Shared edge with the cell to the left
                    perimeter -= 2 

    return perimeter
