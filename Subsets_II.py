#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        S.sort()
        res = [[]]
        pre, count = None, 0
        for e in S:
            if e != pre:
                pre,count = e,len(res)
            # print "res",res
            # print "count",count
            # print "res[len(res)-count:]",res[len(res)-count:]
            # print "---------------------------"
            res = res + [l+[e] for l in res[len(res)-count:]]
        return res

subsetsWithDup = Solution().subsetsWithDup
# print subsetsWithDup([1,2,3])
# print "================================"
print subsetsWithDup([1,2,2,2,3])
# print "================================"
# print subsetsWithDup([1,1])
# print "================================"
# print subsetsWithDup([1,1,1])
# print "================================"
# print subsetsWithDup([1,1,1,1])
