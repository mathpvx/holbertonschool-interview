#!/usr/bin/python3
"""
This module contains a function to calculate the minimum
number of coins needed to reach a given total.
"""


def makeChange(coins, total):
    """Returns the fewest number of coins needed to meet total"""
    if total <= 0:
        return 0

    # Initialize DP array with a high number
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # 0 coins needed for total 0

    for coin in coins:
        for x in range(coin, total + 1):
            dp[x] = min(dp[x], dp[x - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
