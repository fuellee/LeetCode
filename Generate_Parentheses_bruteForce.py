#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

"""
brute force solution
"""
class Solution:
    # @param an integer
    # @return a list of string
    def generateParenthesis(self, n):
        if n<=0:
            return []
        elif n==1:
            return ["()"]
        else:
            return list({e[:i]+"()"+e[i:] for e in self.generateParenthesis(n-1) for i in range(n+1)})

if __name__=="__main__":
    s=Solution()
    print s.generateParenthesis(1)
    print s.generateParenthesis(2)
    print s.generateParenthesis(3)
