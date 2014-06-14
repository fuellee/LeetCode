class Solution:
  # @return a list of lists of integers
  def combine(self, n, k):
    res = []
    def com(acc,i):
        """acc::[e]
            i::int
        """
        if len(acc)==k:
            res.append(acc)
        elif i<=n:
            com(acc+[i],i+1)
            com(acc,i+1)
    com([],1)
    return res

if __name__=="__main__":
    print Solution().combine(5,3)
