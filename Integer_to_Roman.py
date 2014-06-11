class Solution:
    # @return a string
    def intToRoman(self, N):
        def compose(n,one,five,ten):
            if n==0: return ""
            elif n<=3: return one*n
            elif n==4: return one+five
            elif n==5: return five
            elif n<=8: return five+one*(n-5)
            elif n==9: return one+ten
            else: return ""
        N_=list(str(N))
        N_ = map(int, ['0']*(4-len(N_))+N_)
        res = map(lambda x,y:compose(x,*y), \
                   N_ , \
                   [['M', '', ''], ['C', 'D', 'M'], ['X', 'L', 'C'], ['I', 'V', 'X']])
        return ''.join(res)        
