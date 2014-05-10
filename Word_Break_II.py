class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a list of strings
    def wordBreak(self, s, dict):
        cache = {} # cache::string -> [string]|False ,string to parsed result
        res = [] # res::[[string]]
        def parser(acc,remain):
            """parser::[string] * string -> bool
            side_Effect : push acc::[string] to res
            """
            if not remain: # done parsing
                res.append(acc)
                return True
            if remain in cache:
                if cache[remain]==False:
                    return False
                else:
                    res.append(acc + cache[remain])
                    return True

            exit_status = False;
            for i in range(len(remain)):
                curWord,newRemain = remain[:i+1],remain[i+1:]
                if curWord in dict and parser(acc+[curWord], newRemain):
                        exit_status = True
            if exit_status==False:
                cache[remain]=False
                return False

            return True

        parser([],s)
        return [' '.join(sp) for sp in res]

if __name__ == "__main__":
    S = Solution()
    s = "catsanddog"
    dict = {"cat", "cats", "and", "sand", "dog"}
    print S.wordBreak(s,dict)
    # A solution is ["cats and dog", "cat sand dog"].
    dict = {"a","aa"}
    print S.wordBreak("aa",dict)
    print S.wordBreak("aaa",dict)
    print S.wordBreak("aaaa",dict)
    print S.wordBreak("aaaaaaa", {"aaaa","aa","a"})
    for s in S.wordBreak("结婚的和尚未结婚的",{"结婚","和","尚未","和尚","未","的"}):
        print s


