#!/usr/bin/python3
"""  method that calculates the fewest number of operations needed
to result in exactly n H characters in the file"""


def minOperations(n):
    """method min operation """
    
    start='H'
    newString=start
    num = 0
    while (len(newString) < n ):
        num = num + 1
        newString= newString + start

        if ( len(newString)> n):
            return 0

        if(n % len(newString)==0):
            start = newString
            num = num + 1

    return num
