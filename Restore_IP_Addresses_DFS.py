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
        res = []

        def valid(s):
            if s=="": return False
            elif s=="0": return True
            else: return not s.startswith("0") and 0<=int(s)<=255

        def parse(acc, s, n=0):
            if n==3:
                if valid(s):
                    res.append('.'.join(acc+[s]))
                return
            for i in range(1,4): # take 1,2,3 char
                if valid(s[:i]):
                    parse(acc+[s[:i]], s[i:], n+1)
            return

        parse([],s)
        return res

print Solution().restoreIpAddresses("25525511135")
print Solution().restoreIpAddresses("1111")
