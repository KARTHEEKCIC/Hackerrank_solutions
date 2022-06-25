#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pickingNumbers' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#

def pickingNumbers(a):
    # Write your code here

    # Get the unique elements
    freq = {}

    for i in a:
        if i not in freq:
            freq[i] = 1
        else:
            freq[i] = freq[i] + 1

    freq_upd = freq.copy()

    for item in freq:
        if (item-1) in freq:
            freq_upd[item-1] = freq[item-1] + freq[item]

    return max(freq.values())

if __name__ == '__main__':
    fptr = open(os.environ['PWD'] + '/output.txt', 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = pickingNumbers(a)

    fptr.write(str(result) + '\n')

    fptr.close()
