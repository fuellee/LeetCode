class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        res = [[]]
        S.sort()
        for e in S:
            res = res+[l+[e] for l in res]
        return res

def subsets(S):
    A = [[]]
    S.sort()
    for n in S:
        for i in range(len(A)):
            ss = A[i][:]
            ss.append(n)
            A.append(ss)
    return A


if __name__ == "__main__":
    print Solution().subsets([1,2,3])
    print subsets([1,2,3])
