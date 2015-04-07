#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.
import operator
class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        ops = {"+":operator.add, "-":operator.sub, "*":operator.mul, "/":lambda l,r:int(float(l)/r)}
        # python says 1/2==0 and -1/2==-1 !! wat ???
        stack = []
        for e in tokens:
            if e in ops:
                op = ops[e]
                r = stack.pop()
                l = stack.pop()
                stack.append(op(l,r))
                # print l,e,r,"=",op(l,r)
            else:
                stack.append(int(e))
        return stack.pop()

s = Solution()
print s.evalRPN(["2", "1", "+", "3", "*"])
print s.evalRPN(["4", "13", "5", "/", "+"])
print s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])
