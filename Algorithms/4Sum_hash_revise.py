#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
import collections

class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
        N = len(num)
        num.sort()
        res = []
        sum2Pair = collections.defaultdict(list)
        # 2-sum to list of index-pairs

        for i1 in xrange(N-3):
            for i2 in xrange(i1+1,N-2):
                if i2!=i1+1 and num[i2]==num[i2-1]: continue
                sum2Pair[num[i1]+num[i2]].append((i1,i2))

        for i3 in xrange(2,N-1):
            for i4 in xrange(i3+1,N):
                if i4!=i3+1 and num[i4]==num[i4-1]: continue
                sum12 = target-num[i3]-num[i4]
                if sum12 in sum2Pair:
                    for i1,i2 in sum2Pair[sum12]:
                        if i1!=0 and num[i1]==num[i1-1]: continue
                        if i2<i3:
                            if i3!=i2+1 and (num[i3]==num[i3-1]): continue
                            res.append([num[i1],num[i2],num[i3],num[i4]])
        return res

if __name__ == "__main__":
    fourSum = Solution().fourSum
    print fourSum([1,0,-1,0,-2,2],0)
    print fourSum([-3,-2,-1,0,0,1,2,3], 0)
    print fourSum([-1,-5,-5,-3,2,5,0,4],-7)
    print fourSum([1,1,1,1,1,1,2,2],5)
    print fourSum([0,0,0,0],0)
