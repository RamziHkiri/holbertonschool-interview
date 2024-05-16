#!/usr/bin/python3
"""
 calculate how many square units of water will be retained after it rains.
"""


def rain(walls):
    """
    calculate how many square units of water
    will be retained after it rains.
    """
    if not walls:
        return 0

    water = 0
    for i in range(1, len(walls) - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])
        water += min(left, right) - walls[i]
    return water
