#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right
        self.next = None
    def pl(self):
        if(self.next):
            print self.val,"->",
            self.next.pl()
        else:
            print self.val

class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
        def connect2(ln,rn):
            ln.next=rn
            return rn
        if root==None:
            return
        prelevel = [root]
        while prelevel!=[]:
            reduce(connect2,prelevel)
            curlevel = []
            for node in prelevel:
                if node.left!=None: curlevel.append(node.left)
                if node.right!=None: curlevel.append(node.right)
            prelevel = curlevel

T = TreeNode
s = Solution()
tree = T(0,
         T(1, T(3), T(4)),
         T(2, T(5), T(6)))
s.connect(tree)

def connect2(ln,rn):
    ln.next=rn
    return rn
#
# nodes = [T(1),T(2),T(3)]
# nodes = [T(1),T(2)]
# reduce(connect2,nodes)
# print [n.val for n in nodes]
# head = nodes[0]
# head.pl()
