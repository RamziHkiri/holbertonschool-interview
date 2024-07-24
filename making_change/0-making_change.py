#!/usr/bin/python3


def makeChange(coins, total):
    
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
        
    