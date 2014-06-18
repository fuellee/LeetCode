class Solution:
    # @return a list of lists of string
    def solveNQueens(self, n):
        res = []
        def dumpsolution(solution):
            n = len(solution)
            return [''.join(['.'*row, 'Q', '.'*(n-row-1)]) for row in solution]
        def is_feasible_incr(solution,newR):
            newC = len(solution)
            for c,r in enumerate(solution):
                if newR==r or abs(newR-r)==newC-c:
                    return False
            return True
        def solve(solution):
            c = len(solution)
            if c==n:
                res.append(dumpsolution(solution))
            else:
                for newR in range(n):
                    if is_feasible_incr(solution,newR):
                        solve(solution+[newR])
        solve([])
        return res

if __name__ == "__main__":
    print Solution().solveNQueens(6)
