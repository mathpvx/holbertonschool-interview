#!/usr/bin/python3
"""
Validation of UTF8 encoding
"""


def validUTF8(data):
    """
    Determine if a given data set represents a valid UTF-8 encoding.

    Args:
        data (list): A list of integers where each integer represents a byte.

    Returns:
        bool: True if data is a valid UTF-8 encoding, otherwise False.
    """
    num_bytes = 0  # Tracks the number of continuation bytes expected

    for byte in data:
        # Mask to only consider the 8 least significant bits
        byte = byte & 0xFF

        if num_bytes == 0:
            # Check the first byte to determine the
            # number of bytes in the character
            if (byte >> 7) == 0:  # 1-byte character (0xxxxxxx)
                continue
            elif (byte >> 5) == 0b110:  # 2-byte character (110xxxxx)
                num_bytes = 1
            elif (byte >> 4) == 0b1110:  # 3-byte character (1110xxxx)
                num_bytes = 2
            elif (byte >> 3) == 0b11110:  # 4-byte character (11110xxx)
                num_bytes = 3
            else:
                return False  # Invalid first byte
        else:
            # Check continuation bytes (should be 10xxxxxx)
            if (byte >> 6) != 0b10:
                return False
            num_bytes -= 1

    # If there are no leftover bytes to be processed, the encoding is valid
    return num_bytes == 0
