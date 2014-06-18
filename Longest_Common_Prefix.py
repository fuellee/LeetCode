class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        elif len(strs)==1:
            return strs[0]
        else:
            minlen = min(map(len,strs))
            for i in range(minlen):
                for n in range(1,len(strs)):
                    if strs[n][i]!=strs[0][i]:
                        return strs[0][:i]
            return strs[0][:minlen]
