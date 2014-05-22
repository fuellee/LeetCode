#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        candidates.sort()
        res = []
        last = len(candidates)-1
        def comS(i,acc,target):
            if i>last or target<0:
                return
            elif target==0:
                res.append(acc)
            else:
                comS(i,acc+[candidates[i]],target-candidates[i])
                comS(i+1,acc,target)

        comS(0,[],target)
        return res

print Solution().combinationSum([2,3,6,7],7)
# print Solution().combinationSum2([1],1)
print Solution().combinationSum([1,1], 1)
