#!/usr/bin/python3
""" Module which contains minoperations function"""


def minOperations(n):
    """ Calculates the fewest number of operations needed
        to result in exactly n H characters in the file

        Args:
            n: repetitions of H

        Returns:
            number of operations (Copy & Paste) to reach n Hs
    """
    if type(n) is not int or n <= 1:
        return 0
    # initialize the start file
    start = 'H'
    # the new string after every paste operation
    newString = start
    # number of operation
    num = 0
    while(len(newString) < n):
        # increment the number of peration by 1 and paste
        num = num + 1
        newString = newString + start
        # if n divided by the length of the new string we will copy all
        # and increment the number of operation by one
        if(n % len(newString) == 0):
            start = newString
            num = num + 1

    return num
