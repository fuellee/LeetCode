#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

import collections

class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        D=collections.defaultdict(list)
        for s in strs:
            D[''.join(sorted(s))].append(s)
        res = []
        for los in D.values():
            if(len(los)>=2):
                res.extend(los)
        return res

print Solution().anagrams(["dog","cat","god","tac"])
print Solution().anagrams(["cat","rye","aye","dog", "god","cud","cat","old","fop","bra"])
