#!/usr/bin/python3
"""
This module implements the Prime Game logic.

Maria and Ben play a game over multiple rounds.
Each round, they take turns picking prime numbers and
removing them and their multiples from a set {1, 2, ..., n}.
The player unable to make a move loses the round.

The player who wins the most rounds overall is the winner.
"""


def is_prime(n):
    """
    Determine whether a given number is prime.

    Args:
        n (int): The number to test.

    Returns:
        bool: True if n is a prime number, False otherwise.
    """
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def count_primes(n):
    """
    Count the number of prime numbers from 1 to n (inclusive).

    Args:
        n (int): The upper bound of the set.

    Returns:
        int: The count of prime numbers in the set.
    """
    count = 0
    for i in range(2, n + 1):
        if is_prime(i):
            count += 1
    return count


def isWinner(x, nums):
    """
    Determine the overall winner of the Prime Game.

    Args:
        x (int): Number of game rounds.
        nums (list of int): List of n values, one per round.

    Returns:
        str or None: "Maria" if Maria wins more rounds,
                     "Ben" if Ben wins more,
                     None if there is a tie.
    """
    if not nums or x < 1:
        return None

    maria_wins = 0
    ben_wins = 0

    for n in nums[:x]:
        primes = count_primes(n)

        # Maria wins if there's an odd number of primes (she starts)
        if primes % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
