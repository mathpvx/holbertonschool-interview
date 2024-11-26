#!/usr/bin/python3
'''
    Calculates the perimeter of the lands represented by
    1 considering length of a 1 cell is 1
'''


def island_perimeter(grid):
    '''
    Calculates the perimeter of the lands represented by
    1 considering length of a 1 cell is 1
    '''
    total_perimeter = 0
    number_of_rows = len(grid)
    num_c = len(grid[0])

    # Loop through each cell in the grid
    for row_index in range(number_of_rows):
        for column_index in range(num_c):
            # If the cell is land
            if grid[row_index][column_index] == 1:
                # Check all four possible neighbors: right, down, left, and up
                for r_ofs, c_ofs in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                    neighbor_row = row_index + r_ofs
                    neighbor_c = column_index + c_ofs

                    # Add to perimeter if out of bounds or neighbor is water
                    if (neighbor_row < 0 or neighbor_row >= number_of_rows or
                            neighbor_c < 0 or neighbor_c >= num_c or
                            grid[neighbor_row][neighbor_c] == 0):
                        total_perimeter += 1

    return total_perimeter
