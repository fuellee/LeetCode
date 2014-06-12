import operator

class Solution:
    # @return an integer
    def totalNQueens(self, n):
        self.total = 0
        def is_feasible(solution):
            n = len(solution)
            cs = range(n)
            return len(set(map(operator.add,solution,cs)))==n==len(set(map(operator.sub,solution,cs)))
        def solve(solution):
            if(is_feasible(solution)):
                c = len(solution)
                if c==n:
                    self.total += 1
                else:
                    for r in range(n):
                        if r not in solution:
                            solve(solution+[r])
        solve([])
        return self.total

print Solution().totalNQueens(6)
