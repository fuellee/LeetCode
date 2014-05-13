#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):
        if root is None:
            return []
        res = []
        prelevel = [root]
        while(prelevel):
            curlevel = []
            for node in prelevel:
                if node.left!=None:
                    curlevel.append(node.left)
                if node.right!=None:
                    curlevel.append(node.right)
            res.append([node.val for node in prelevel])
            prelevel = curlevel
        return res

if __name__ == "__main__":
    tree = TreeNode(3)
    tree.left = TreeNode(9)
    tree.right = TreeNode(20)
    s=Solution()
    print s.levelOrder(tree)
    print s.levelOrder(TreeNode(3))
    print s.levelOrder(None)
