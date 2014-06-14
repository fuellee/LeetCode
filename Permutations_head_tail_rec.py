class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        if len(num)<=1:
            return [num]
        else:
            res = []
            for i,e in enumerate(num):
                tails = self.permute(num[:i]+num[i+1:])
                res += [[e]+tail for tail in tails]
            return res
