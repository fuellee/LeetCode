#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if node is None:
            return None
        N = UndirectedGraphNode
        Q = [node]  # width first graph traverse. node in Q: to be visited, may been visited
        old2new = {node:N(node.label)} # node in old2new : node visited and cloned, keep going on its neighbors

        while(len(Q)):
            curN = Q.pop()
            neighbors = curN.neighbors
            newNeighbors = old2new[curN].neighbors
            for n in neighbors:
                if n not in old2new:
                    old2new[n] = N(n.label)
                    Q.append(n)

                newNeighbors.append(old2new[n])
        return old2new[node]
