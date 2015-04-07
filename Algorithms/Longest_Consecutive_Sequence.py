#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

# 1. create hashmap of num list
# 2. scan num vector, check wether its successors and previous is present in
# hashmap
class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        S = set(num)
        curlen,maxlen = 0,0
        for i in num:
            if i in S:
                S.remove(i)
                curlen = 1
                nxt = i+1
                while nxt in S:
                    S.remove(nxt)
                    curlen+=1
                    nxt+=1
                pre = i-1
                while pre in S:
                    S.remove(pre)
                    curlen+=1
                    pre-=1
                maxlen = max(maxlen,curlen)
                if not S: break
        return maxlen
