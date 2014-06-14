#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 fuel <fuel@fuel-3330>
#
# Distributed under terms of the MIT license.

class Solution:
    # @param words, a list of strings
    # @param L, an integer
    # @return a list of strings
    def fullJustify(self, words, L):
        res = []
        while words:
            line,lenline,lineCache = [],-1,[' ']*L
            # take a line of words
            for w in words:
                if lenline+1+len(w)<=L:
                    lenline += 1+len(w)
                    line.append(w)
                else: break
            isLastLine=(len(line)==len(words))

            # render line
            if isLastLine:
                curser = 0
                for w in line:
                    lineCache[curser:curser+len(w)]=w
                    curser += len(w)+1
            elif len(line)>1:
                # compute blanks between words
                lineblank = L-sum(map(len,line))
                perblank = lineblank/(len(line)-1)
                remainder = lineblank%(len(line)-1)
                if remainder==0:
                    blanks = [perblank]*(len(line)-1)
                else:
                    blanks = [perblank+1]*remainder+[perblank]*(len(line)-1-remainder)

                # write words and blanks to lineCache
                curser = 0
                for w,blank in zip(line[:-1],blanks):
                    lineblank = L-sum(map(len,line))
                    lineCache[curser:curser+len(w)]=w
                    curser += len(w)+blank
                lineCache[-len(line[-1]):]=line[-1]
            else: # only one word in this line
                lineCache[0:len(line[0])]=line[0]

            for w in line:
                words.pop(0)
            res.append(''.join(lineCache))
        return res

print Solution().fullJustify(["This", "is", "an", "example", "of", "text", "justification."],16)
print Solution().fullJustify( ["a","b","c","d","e"], 1)
print Solution().fullJustify(["What","must","be","shall","be."], 12)
