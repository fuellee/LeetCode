#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
class Solution:
    # @param num, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, num, target):
        num.sort()
        res = []
        n = len(num)
        def comS(start,acc,target):
            if target==0:
                res.append(acc)
            elif start>=n or target<0:
                return
            else:
                for i in range(start,n):
                    if(i==start or num[i]!=num[i-1]):
                        comS(i+1,acc+[num[i]],target-num[i])

        comS(0,[],target)
        return res

print Solution().combinationSum2([2,3,6,7],7)
# print Solution().combinationSum2([1],1)
print Solution().combinationSum2([1,1,1,1,2], 2)
