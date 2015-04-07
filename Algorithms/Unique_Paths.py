#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
# class Solution:
#     # @return an integer
#     def uniquePaths(self, m, n):
#         return C
class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        def C(m,n):
            numerator,denominator = 1,1
            for i in range(n):
                numerator *= m
                denominator *= n
                m-=1
                n-=1
            return numerator/denominator
        return C(m+n-2,m-1)

s = Solution()
print s.uniquePaths(3,7)
