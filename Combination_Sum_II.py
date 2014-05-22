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
    def combinationSum2(self, candidates, target):
        candidates.sort(reverse=True)
        res = []
        last = len(candidates)-1
        def comS(acc,sum, i):
            if sum==target:
                res.append(acc)
            elif i>last or sum>target:
                return
            else:
                comS(acc+[candidates[i]],sum+candidates[i],i+1)
                comS(acc,sum,i+1)

        comS([],0,0)
        return res

# print Solution().combinationSum2([10,1,2,7,6,1,5],8)
# print Solution().combinationSum2([1],1)
print Solution().combinationSum2([1,1], 1)
