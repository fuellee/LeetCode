#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
# from collections import defaultdict
import collections

class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        n2i = collections.defaultdict(list)
        for i,n in enumerate(num):
            n2i[n].append(i)
        for n in n2i:
            if target-n in n2i:
                ps1, ps2 = n2i[n], n2i[target-n]
                if ps1 is ps2:
                    return (ps1[0]+1, ps1[1]+1)
                else:
                    return sorted((ps1[0]+1, ps2[0]+1))

print Solution().twoSum([2, 7, 11, 15],9)
print Solution().twoSum([0,4,3,0], 0)
print Solution().twoSum([-3,4,3,90], 0)
