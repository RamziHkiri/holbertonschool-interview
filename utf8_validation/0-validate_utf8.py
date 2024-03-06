#!/usr/bin/python3
"""utf8 validation methode"""


def validUTF8(data):
    """ determines if a given data set represents a valid UTF-8 encoding."""
    for x in data:
        if x < 0 or x >= 256:
            return False

    return True
