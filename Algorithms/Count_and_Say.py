class Solution:
    # @return a string
    def countAndSay(self, n):
        if n<=1:
            return "1"
        else:
            prestr = self.countAndSay(n-1)
            preC = prestr[0];
            res = []
            count = 0
            for c in prestr:
                if(c==preC):
                    count+=1
                    preC=c
                else:
                    res.append(str(count))
                    res.append(preC)
                    count = 1
                    preC=c
            res.append(str(count))
            res.append(preC)
            return ''.join(res)

s=Solution()
for i in range(1,11):
    print s.countAndSay(i)
