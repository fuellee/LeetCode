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
                for s in strs:
                    if s[i]!=strs[0][i]:
                        return s[:i]
            return strs[0][:minlen]
