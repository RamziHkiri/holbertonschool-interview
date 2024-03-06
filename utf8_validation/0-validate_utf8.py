#!/usr/bin/python3
"""utf8 validation methode"""


from codecs import decode


def validUTF8(data):
    """ determines if a given data set represents a valid UTF-8 encoding."""
    try:
        decoded_data = decode(bytes(data), 'utf-8')
        return True
    except ValueError:
        return False
