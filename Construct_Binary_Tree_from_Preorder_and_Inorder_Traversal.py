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
    # @param preorder, a list of integers
    # @param inorder, a list of integers
    # @return a tree node
    def buildTree(self, preorder, inorder):
        preLen = inLen = len(preorder)
        def buildTree(preB,preE,inB,inE):
            if preE<preB or inE<inB or preE>preLen-1 or inE>inLen-1:
                return None
            else:
                val = preorder[preB]
                inPos = inorder.index(val)
                subtree = TreeNode(val)
                subtree.left = buildTree(preB+1,preB+inPos-inB,inB,inPos-1)
                subtree.right = buildTree(preB+inPos-inB+1,preE,inPos+1,inE)
                return subtree
        return buildTree(0,preLen-1,0,inLen-1)
