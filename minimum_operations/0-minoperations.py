#!/usr/bin/python3
"""
Calculating the minimum number of operations
to produce n H characters in the file.
"""


def minOperations(n):
    """
    Calculate the fewest number of operations to produce n H characters.
    Returns 0 if n is impossible to achieve.
    """
    if n <= 1:
        return 0

    operations = 0
    factor = 2

    # Loop to find the smallest factors of n
    while n > 1:
        # While n is divisible by factor, divide n and count operations
        while n % factor == 0:
            operations += factor
            n //= factor
        # Move to the next factor
        factor += 1

    return operations
