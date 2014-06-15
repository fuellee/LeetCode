#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
class Solution:
    # @return an integer
    def maxArea(self, height):
        L,R,maxWater  = 0, len(height)-1, 0
        while(L<R):
            barH = min(height[L],height[R])
            water = (R-L)*barH
            maxWater = max(maxWater,water)
            if height[L]<height[R]:
                L+=1
            else:
                R-=1
        return maxWater
