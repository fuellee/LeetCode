#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
import operator

class Solution:
    # @return a string
    def getPermutation(self, n, k):
        circle = reduce(operator.mul, range(1,n+1))
        k -= 1 # start from 1 not 0, move once
        k %= circle
        nums = range(1,n+1)
        seq = []
        #print circle,k,nums

        while(n):
            circle /= n
            idx = k/circle
            k %= circle
            seq.append(nums[idx])
            nums.remove(nums[idx])
            n -= 1
            #print seq

        return ''.join(map(str,seq))

if __name__=="__main__":
    getPermutation = Solution().getPermutation
    for k in range(1,6+1):
        print getPermutation(3,k)
