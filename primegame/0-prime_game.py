#!/usr/bin/python3

def is_prime(n):
    """Check if n is a prime number."""
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def count_primes(n):
    """Count the number of prime numbers from 1 to n."""
    count = 0
    for i in range(2, n + 1):
        if is_prime(i):
            count += 1
    return count


def isWinner(x, nums):
    """Determine who wins the most rounds."""
    if not nums or x < 1:
        return None

    maria_wins = 0
    ben_wins = 0

    for n in nums[:x]:
        primes = count_primes(n)
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
