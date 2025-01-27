#!/usr/bin/python3
"""
Rainwater trap calculation
"""


def rain(walls):
    """
    Calculate how much water can be trapped after raining.

    Args:
        walls (list): A list of non-negative
        integers representing wall heights.

    Returns:
        int: Total units of water trapped.
    """
    if not walls or len(walls) < 3:
        return 0  # No water can be trapped with less than 3 walls

    total_water = 0
    n = len(walls)

    for i in range(n):
        # Find the tallest wall to the left of the current position
        left_max = 0
        for j in range(i + 1):
            left_max = max(left_max, walls[j])

        # Find the tallest wall to the right of the current position
        right_max = 0
        for j in range(i, n):
            right_max = max(right_max, walls[j])

        # Calculate water trapped at this position
        trapped = min(left_max, right_max) - walls[i]

        # Add to the total only if water is trapped
        if trapped > 0:
            total_water += trapped

    return total_water
