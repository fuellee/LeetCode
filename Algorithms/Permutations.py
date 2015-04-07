#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        if len(num)<=1:
            return [num]
        res = [[num[0]]]
        for n,e in enumerate(num[1:]):
            res = [p[:i]+[e]+p[i:] for p in res for i in range(n+2)]
        return res

if __name__ == "__main__":
    s=Solution()
    print s.permute([1])
    print s.permute([1,2])
    print s.permute([1,2,3])
