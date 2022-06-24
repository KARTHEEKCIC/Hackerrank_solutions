#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'formingMagicSquare' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY s as parameter.
#

def rotation(magic_square):

    row0 = []
    col2 = []
    row2 = []
    col0 = []

    # Obtain the new elements of the matrix
    for i in range(3):
        row0.append(magic_square[2-i][0])
        col2.append(magic_square[0][i])
        row2.append(magic_square[2-i][2])
        col0.append(magic_square[2][i])

    for i in range(3):
        magic_square[0][i] = row0[i]
        magic_square[i][2] = col2[i]
        magic_square[2][i] = row2[i]
        magic_square[i][0] = col0[i]

    return magic_square

def formingMagicSquare(s):
    # Write your code here

    # Form the possible set of magic squares which by observation is only 8 for a 3 x 3 matrix.
    # Some observation - 
    # 1. All the magic squares have 5 as center and the magic sum is 15
    # 2. The possible corners for this magic square with center 5 is 6,4 and 8,2.
    # 3. Once the corner pairs are fixed, then there is only one possible way of filling the leftover numbers.

    # Empty set to store the 8 matrices.
    S = []
    for i in range(8):
        S.append([])

    # Therefore, we can form 4 different squares for a fixed pair of corners by rotating the corners.
    magic_square = [[4, 3, 8], [9, 5, 1], [2, 7, 6]]

    for i in range(4):
        for j in range(3):
            S[i].append(magic_square[j].copy())
        magic_square = rotation(magic_square)

    magic_square = [[4, 9, 2], [3, 5, 7], [8, 1, 6]]

    for i in range(4,8):
        for j in range(3):
            S[i].append(magic_square[j].copy())
        magic_square = rotation(magic_square)

    # Now finding the shortest distance between the set of square and the present square
    final_s = None
    min_dist = 100
    for s_ in S:
        dist = 0
        for row1, row2, in zip(s_, s):
            dist = dist + sum([abs(ele1 - ele2) for ele1, ele2 in zip(row1, row2)])
        if dist < min_dist:
            final_s = s_
            min_dist = dist

    return min_dist

if __name__ == '__main__':
    fptr = open(os.environ['PWD'] + '/output.txt', 'w')

    s = []

    for _ in range(3):
        s.append(list(map(int, input().rstrip().split())))

    result = formingMagicSquare(s)

    fptr.write(str(result) + '\n')

    fptr.close()
