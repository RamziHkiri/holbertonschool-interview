#!/usr/bin/python3
""" make change function"""

def makeChange(coins, total):
    """make changes function"""
    
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    num = 0
    i = 0
    while total // coins[i] != 0:
        num += total // coins[i]
        total %= coins[i]
        i += 1
        if total == 0 :
            return num

    return -1
           
        
    