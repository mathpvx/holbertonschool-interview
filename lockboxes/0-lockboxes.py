#!/usr/bin/python3

'''Method to determine if all the boxes can be opened'''

def canUnlockAll(boxes):
    # sets the unlocked box to the index of the first unlocked box
    unlocked = set([0])
    # sets the keys to the first index of the boxes
    keys = set(boxes[0])
    
    while keys:
        # takes one key from the set
        key = keys.pop()
        if key not in unlocked and key < len(boxes):
            # identifies the box as unlocked
            unlocked.add(key)
            # add new keys from the unlocked box
            keys.update(boxes[key])
    
    # check if all boxes are unlocked
    return len(unlocked) == len(boxes)
