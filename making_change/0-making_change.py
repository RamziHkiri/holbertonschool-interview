#!/usr/bin/python3
""" fewest number of coins needed to meet a given amount total """


def makeChange(coins, total):
    """make change function    """

    if total <= 0:
        return 0

    coins.sort(reverse=True)
    sum = 0
    i = 0
    counter = 0
    num_coins = len(coins)
    while sum < total and i < num_coins:
        if coins[i] <= total - sum:
            sum += coins[i]
            counter += 1
            if sum == total:
                return counter
        else:
            i += 1
    return -1
