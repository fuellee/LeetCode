class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        cache = {"":True}
        def parser(remain):
            if remain in cache:
                return cache[remain]
            for i in range(len(remain)):
                if (remain[:i+1] in dict) and parser(remain[i+1:]):
                    cache[remain]=True
                    return True
            cache[remain]=False
            return False
        return parser(s)
