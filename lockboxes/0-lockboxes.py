#!/usr/bin/python3
""" create methode that define if all the boxes can be opened or no"""


def canUnlockAll(boxes):
    """ a method that determines if all the boxes can be opened.
    Prototype: def canUnlockAll(boxes)
    boxes is a list of lists """

    length = len(boxes)
    for k in range(1, length):
        opAll = False
        for box in range(length):
            if k in boxes[box] and box != k:
                opAll = True
                break
        if not opAll:
            return False

    return True
