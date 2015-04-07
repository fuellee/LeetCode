#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
import collections

class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        N = len(num)
        num.sort()
        D = collections.Counter(num)
        res = []
        for i in range(N-2):
            if num[i]>0:
                break
            if i==0 or num[i]!=num[i-1]:
                for j in range(i+1,N-1):
                    if j==i+1 or num[j]!=num[j-1]:
                        S = num[i]+num[j]
                        if S>0:
                            break
                        elif num[i]==0==num[j]: # [0,0,0] special too complicated
                            if D[0]>=3:
                                res.append([0,0,0])
                        elif -S in D:
                            if -S>num[j] or (-S==num[j] and D[-S]>=2):
                                res.append([num[i],num[j],-S])
        return res

if __name__ == "__main__":
    threeSum = Solution().threeSum
    # print threeSum([-1,0,1,2,-1,-4])
    # print threeSum([7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6])
    print threeSum([-1,0,1,2,-1,-4])
    print threeSum([-1,0,0,1])
    print threeSum([1,2,-2,-1])
    print threeSum([-2,1,1])
    print threeSum([-2,0,0,0,1,1])
    print threeSum([0,0,0,0])
    print threeSum([-2,0,1,1,2])
