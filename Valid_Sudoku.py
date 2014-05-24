#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        def validBlock(lst):
            return len(lst)==len(set(lst))

        return  all(map(validBlock, [filter(lambda c:c!='.', row) for row in board])) and \
                all(map(validBlock, [[row[i] for row in board if row[i]!='.'] for i in range(len(board))])) and \
                all(map(validBlock, [[board[r][c] for r in range(row,row+3) for c in range(col,col+3) if board[r][c]!='.'] for row in range(0,len(board),3) for col in range(0,len(board),3)]))
