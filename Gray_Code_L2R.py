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
        """ change from most significant bit to least significant bit
        (left most to right) """
        if n==0:return [0]
        res = [0,1]
        for i in range(1,n):
            res = [gc<<1 for gc in res]
            res += [gc+1 for gc in res[::-1]]
        return res

n = 3
for gc in Solution().grayCode(n):
    print ("%"+str(n)+"d") % int(bin(gc)[2:])
