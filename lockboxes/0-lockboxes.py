#!/usr/bin/python3
def canUnlockAll(boxes):
    """ a method that determines if all the boxes can be opened.
    Prototype: def canUnlockAll(boxes)
    boxes is a list of lists """

    l= len(boxes)
    for k in range(1, l):
        opAll = False
        for box in range(l):
            if k in boxes[box] and box != k:
                opAll = True
                break
        if not opAll:
            return False

    return True
