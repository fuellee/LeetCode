#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.


class Solution:
    # @return a list of integers
    def grayCode(self, n):
        """ change from least significant bit to most significant bit
        (left most to right) """
        if n==0: return [0]
        res = [0,1]
        for i in range(1,n):
            mostSignificantBit = 1<<i
            res += [gc+mostSignificantBit for gc in res[::-1]]
        return res

n = 3
for gc in Solution().grayCode(n):
    print ("%"+str(n)+"d") % int(bin(gc)[2:])
