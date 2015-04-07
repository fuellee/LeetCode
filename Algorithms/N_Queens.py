class Solution:
    # @return a list of lists of string
    def solveNQueens(self, n):
        res = []
        def dumpsolution(solution):
            n = len(solution)
            return [''.join(['.'*row, 'Q', '.'*(n-row-1)]) for row in solution]
        def is_feasible(solution):
            n = len(solution)
            cs = range(n)
            return len(set(map(operator.add,solution,cs)))==n==len(set(map(operator.sub,solution,cs)))
        def solve(solution):
            if(is_feasible(solution)):
                c = len(solution)
                if c==n:
                    res.append(dumpsolution(solution))
                else:
                    for r in range(n):
                        if r not in solution:
                            solve(solution+[r])
        solve([])
        return res
