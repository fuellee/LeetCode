class Solution:
    # @return a string
    def convert(self, s, nRows):
        def itlv_merge(s1,s2):
            res = [None]*(len(s1)+len(s2))
            res[::2]=s1
            res[1::2]=s2
            return ''.join(res)
        if nRows==1 or len(s)==1:
            return s
        sls = [s[start::2*nRows-2] for start in range(2*nRows-2)]
        for i in range(1,nRows-1):
            sls[i] = itlv_merge(sls[i],sls.pop())
        return ''.join(sls)

Solution().convert("A",1)
Solution().convert("AB", 1)
Solution().convert("PAYPALISHIRING", 3)
Solution().convert("PAYPALISHIRING",4)
