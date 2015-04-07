#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
import collections
import itertools

class Solution:
    # @param S, a string
    # @param L, a list of string
    # @return a list of integer
    def findSubstring(self, S, L):
        def count(lst):
            res = collections.defaultdict(int)
            for e in lst:
                res[e]+=1
            return res
        wlen = len(L[0])
        D = {w:i for i,w in enumerate(L)}
        Sis = [[D[S[i:i+wlen]] if S[i:i+wlen] in D else None for i in range(start,len(S),wlen)] for start in range(wlen)]
        countL = count([D[l] for l in L])
        iss = [[offset+i*wlen for i in range(0,len(Si)-len(L)+1) if Si[i]!=None and count(Si[i:i+len(L)])==countL] for offset,Si in enumerate(Sis)]
        return sorted(itertools.chain.from_iterable(iss))
