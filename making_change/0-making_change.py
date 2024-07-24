#!/usr/bin/python3
""" fewest number of coins needed to meet a given amount total """

def makeChange(coins, total):
    """make change function """
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    num = 0
    i = 0
    while total // coins[i] >= 1:
        num += total // coins[i]
        total %= coins[i]
        i += 1
        if total == 0 :
            return num
    return -1
        
    