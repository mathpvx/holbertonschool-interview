#!/usr/bin/python3
"""Solve the N-Queens problem and print all solutions.

Usage:
    nqueens N
"""

import sys


def parse_args():
    """Validate CLI arguments and return N as an int."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    n_str = sys.argv[1]
    if not n_str.isdigit():
        print("N must be a number")
        sys.exit(1)

    n = int(n_str)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    return n


def solve(n):
    """Generate all solutions as lists of [row, col]."""
    solutions = []
    cols = set()
    diag1 = set()  # r - c
    diag2 = set()  # r + c
    placement = [-1] * n  # placement[row] = col

    def backtrack(row):
        if row == n:
            sol = [[r, placement[r]] for r in range(n)]
            solutions.append(sol)
            return

        for c in range(n):
            if c in cols or (row - c) in diag1 or (row + c) in diag2:
                continue
            placement[row] = c
            cols.add(c)
            diag1.add(row - c)
            diag2.add(row + c)

            backtrack(row + 1)

            cols.remove(c)
            diag1.remove(row - c)
            diag2.remove(row + c)
            placement[row] = -1

    backtrack(0)
    return solutions


def main():
    n = parse_args()
    for sol in solve(n):
        print(sol)


if __name__ == "__main__":
    main()
