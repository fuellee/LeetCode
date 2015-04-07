class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permuteUnique(self, num):
        def P(lst):
            if len(lst)<=1:
                return [lst]
            else:
                res = []
                for i,e in enumerate(lst):
                    if i>0 and lst[i-1]==e: continue
                    tails = P(lst[:i]+lst[i+1:])
                    res += [[e]+tail for tail in tails]
                return res
        num.sort()
        return P(num)

if __name__ == "__main__":
    s=Solution()
    print s.permuteUnique([1])
    print s.permuteUnique([1,2])
    print s.permuteUnique([1,2,3])
    print s.permuteUnique([1,1,5])
