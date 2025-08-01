#!/usr/bin/python3
"""Log parsing script"""

import sys
import signal

status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
counter = {code: 0 for code in status_codes}
total_size = 0
line_count = 0


def print_stats():
    """Prints the metrics"""
    print("File size: {}".format(total_size))
    for code in sorted(counter.keys()):
        if counter[code]:
            print("{}: {}".format(code, counter[code]))


try:
    for line in sys.stdin:
        line_count += 1
        try:
            parts = line.strip().split()
            status = parts[-2]
            size = int(parts[-1])
            total_size += size
            if status in counter:
                counter[status] += 1
        except Exception:
            pass

        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise

print_stats()