#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def merge(self, intervals):
        itvs = []
        for itv in intervals:
            itvs.append((itv.start,"{"))
            itvs.append((itv.end,"}"))
        itvs.sort()
        print itvs
        stack = []
        res = []
        for n,flag in itvs:
            if flag is "{":
                print "push:",(n,flag)
                stack.append(n)
            else:
                print "pop: ",(n,flag)
                if len(stack)==1:
                    res.append(Interval(stack[0],n))
                stack.pop()
        return res




# intervals = map(lambda(itv):Interval(*itv),[[1,3],[2,6],[8,10],[15,18]])
intervals = map(lambda(itv):Interval(*itv),[[1,4],[0,0]])
s = Solution()
print [[itv.start,itv.end]for itv in s.merge(intervals)]
