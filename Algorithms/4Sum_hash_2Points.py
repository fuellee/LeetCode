#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

# 这么复杂，代码丑哭了
import collections
class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
        N = len(num)
        if N<4: return []

        num.sort()
        C = collections.Counter(num)
        res = set()
        D = collections.defaultdict(list)

        # for all uniq pair of nums (nums[i1],num[i2]), collect two-sum
        for i1 in xrange(N-1):
            if i1==0 or num[i1]!=num[i1-1]:
                for i2 in xrange(i1+1,N):
                    if i2==i1+1 or num[i2]!=num[i2-1]:
                        D[num[i1]+num[i2]].append((num[i1],num[i2]))

        sum2s = sorted(D.keys())
        emptyCounter = collections.Counter()

        # do two-sum on two-sums
        L,R = 0,len(sum2s)-1
        while(L<=R):
            # print "L,R =",L,R
            sum4 = sum2s[L]+sum2s[R]
            if(sum4==target):
                # print D[sum2s[L]],D[sum2s[R]]
                for n1,n2 in D[sum2s[L]]:
                    for n3,n4 in D[sum2s[R]]:
                        tuple4 = (n1,n2,n3,n4)
                        # use set/Counter to guarantee the uniqueness of quadruplets
                        # (any better way ?)
                        if collections.Counter(tuple4)-C==emptyCounter: # valid quadruplet
                            res.add(tuple(sorted(tuple4)))
                            # tuple -> Counter
                            # tuple -> sored_list -> tuple -> list
                            # lots of construction make this slow!
                L+=1;R-=1
            elif(sum4<target): L+=1
            else: R-=1

        return map(list,res)

if __name__ == "__main__":
    fourSum = Solution().fourSum
    print fourSum([1,0,-1,0,-2,2],0)
    print fourSum([-3,-2,-1,0,0,1,2,3], 0)
    print fourSum([-1,-5,-5,-3,2,5,0,4],-7)
    print fourSum([1,1,1,1,1,1,2,2],5)
    print fourSum([0,0,0,0],0)
