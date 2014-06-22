#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
        if len(num)<4:
            return []
        num.sort()
        Min,Max,N = num[0],num[-1],len(num)
        res = []

        def comS(start,acc,target):
            if len(acc)==4:
                if(target==0):
                    res.append(acc)
                return
            elif start>=N or (4-len(acc))*Min>target or (4-len(acc))*Max<target:
                return
            else:
                comS(start+1,acc+[num[start]],target-num[start])
                for i in range(start+1,N):
                    if(num[i]!=num[i-1]):
                        comS(i+1, acc+[num[i]], target-num[i])

        comS(0,[],target)
        return res

if __name__ == "__main__":
    fourSum = Solution().fourSum
    print fourSum([1,0,-1,0,-2,2],0)
    print fourSum([-3,-2,-1,0,0,1,2,3], 0)
    print fourSum([-1,-5,-5,-3,2,5,0,4],-7)
    print fourSum([1,1,1,1,1,1,2,2],5)
