#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

class Solution:
    # @param num, a list of integer
    # @return a list of integer
    def nextPermutation(self, num):
        L = -1
        for i in range(len(num)-1,0,-1):
            if num[i-1]<num[i]:
                L = i-1; break

        if L==-1:
            num.reverse()
        else:
            R = -1
            for i in range(L+1,len(num)):
                if num[i]<=num[L]:
                    R = i-1; break
            if R==-1 and num[L]==num[R]: #special case
                R=-2
            # print "L:",L,"  R:",R
            num[L],num[R] = num[R],num[L]
            num[L+1:] = reversed(num[L+1:])
        return num

nextPermutation=Solution().nextPermutation
num = [4, 3, 2, 1]
for i in range(24):
    num = nextPermutation(num)
    print num
num = [5,1,1]
for i in range(6):
    num = nextPermutation(num)
    print num
num = [2,2,7,5,4,3,2,2,1]
print nextPermutation(num)==[2, 3, 1, 2, 2, 2, 4, 5, 7]
