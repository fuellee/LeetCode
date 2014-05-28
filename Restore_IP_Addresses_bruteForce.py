#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

class Solution:
    # @param s, a string
    # @return a list of strings
    def restoreIpAddresses(self, s):
        # if(len(s)==12): return ['.'.join([s[i:i+3] for i in range(0,12,3)])]
        def valid(s):
            if s=="0": return True
            else: return not s.startswith("0") and 0<=int(s)<=255
        if(len(s)>12): return []
        res = []
        for i in range(1,len(s)-2):
            for j in range(i+1,len(s)-1):
                for k in range(j+1,len(s)):
                    sep = [s[:i],s[i:j],s[j:k],s[k:]]
                    if all(map(valid, sep)):
                        res.append('.'.join(sep))
        return res

print Solution().restoreIpAddresses("25525511135")
