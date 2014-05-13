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
    def zigzagLevelOrder(self, root):
        if root is None:
            return []
        res = []
        prelevel = [root]
        flag=-1
        while(prelevel):
            flag=-flag
            curlevel = []
            for node in prelevel:
                if node.left!=None:
                    curlevel.append(node.left)
                if node.right!=None:
                    curlevel.append(node.right)
            res.append([node.val for node in prelevel][::flag])
            prelevel = curlevel
        return res

if __name__ == "__main__":
    tree = TreeNode(3)
    tree.left = TreeNode(9)
    tree.right = TreeNode(20)
    tree.right.left = TreeNode(15)
    tree.right.right = TreeNode(7)
    s=Solution()
    print s.zigzagLevelOrder(tree)
    print s.zigzagLevelOrder(TreeNode(3))
    print s.zigzagLevelOrder(None)
