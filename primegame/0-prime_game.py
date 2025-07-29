#!/usr/bin/python3
"""
This module implements the Prime Game logic.

Maria and Ben play a game over multiple rounds.
Each round, they take turns picking prime numbers and
removing them and their multiples from a set {1, 2, ..., n}.
The player unable to make a move loses the round.

The player who wins the most rounds overall is the winner.
"""


def isWinner(x, nums):
    """
    Determine the overall winner of the Prime Game.
    Uses precomputed prime counts to improve performance.
    """
    if not nums or x < 1:
        return None

    max_n = max(nums)

    # Sieve of Eratosthenes
    sieve = [True] * (max_n + 1)
    sieve[0] = sieve[1] = False

    for i in range(2, int(max_n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, max_n + 1, i):
                sieve[j] = False

    # Precompute the number of primes up to each number
    prime_counts = [0] * (max_n + 1)
    count = 0
    for i in range(1, max_n + 1):
        if sieve[i]:
            count += 1
        prime_counts[i] = count

    maria_wins = 0
    ben_wins = 0

    for n in nums[:x]:
        if prime_counts[n] % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
