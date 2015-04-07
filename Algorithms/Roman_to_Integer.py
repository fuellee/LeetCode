#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

class Solution:
    # @return an integer
    def romanToInt(self, s):
        value = {'C': 100, 'D': 500, 'I': 1, 'L': 50, 'M': 1000, 'V': 5, 'X': 10}
        Lchar = {'I':['V','X'], 'X':['L','C'], 'C':['D','M']}
        res = 0
        for i,c in enumerate(s[:-1]):
            if c in Lchar and s[i+1] in Lchar[c]:
                res -= value[c]
            else:
                res += value[c]
        res += value[s[-1]]
        return res
