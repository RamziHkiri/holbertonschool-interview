#!/usr/bin/python3
'''Minimum Operations'''


def minOperations(n):
    '''Minimum Operations
    Args:
        n : integer
    Return : number operations
    '''

    if n <= 1:
        return 0
    op = 2
    cont = 0
    while op <= n:
        if n % op == 0:
            cont += op
            n = n / op
        else:
            op += 1
    return cont
