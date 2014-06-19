#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
import bisect

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        L = bisect.bisect_left(A,target)
        R = bisect.bisect_right(A,target)-1
        if L<len(A) and A[L]==target:
            return [L,R]
        else:
            return [-1,-1]
