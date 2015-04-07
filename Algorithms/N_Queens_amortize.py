#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
import operator

class Solution:
    # @return a list of lists of string
    def solveNQueens(self, n):
        self.frontiers = [[]]
        # frontiers :: [solution]
        # solution :: [pos]
        # pos :: int
        def dumpsolution(solution):
            n = len(solution)
            return [''.join(['.'*row, 'Q', '.'*(n-row-1)]) for row in solution]
        def is_feasible_incr(solution,newR):
            newC = len(solution)
            for c,r in enumerate(solution):
                if newR==r or abs(newR-r)==newC-c:
                    return False
            return True

        for c in range(n):
            self.frontiers = [solution+[newR] for solution in self.frontiers for newR in range(n) if is_feasible_incr(solution,newR)]

        return map(dumpsolution, self.frontiers)

if __name__ == "__main__":
    print Solution().solveNQueens(6)
