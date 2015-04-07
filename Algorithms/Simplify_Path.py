#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        folders = [f for f in path.split(r"/") if f and f!='.']
        path = []
        for f in folders:
            if f=="..":
                if path: # special case: "/../" is "/"
                    path.pop()
            else:
                path.append(f)
        return "/"+"/".join(path)

simplifyPath = Solution().simplifyPath
print simplifyPath("/a/./b/../../c/")
print simplifyPath("/../")
print simplifyPath("/home//foo/")
