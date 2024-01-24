#!/usr/bin/python3
""" method that calculates the fewest number of operations needed
to result in exactly n H characters in the file"""


def minOperations(n):
    """ method min operation """
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

        if(len(newString) > n):
            return 0
        # if n divided by the length of the new string we will copy all
        # and increment the number of operation by one
        if(n % len(newString) == 0):
            start = newString
            num = num + 1

    return num
