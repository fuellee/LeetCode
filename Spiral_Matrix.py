M = [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of integers
    def spiralOrder(self, matrix):
        m=len(matrix)
        if m==0: return []
        n=len(matrix[0])
        res = []
        ml,mr = 0,m-1
        nl,nr = 0,n-1
        while ml<=mr and nl<=nr:
            for n in range(nl,nr+1):
                res.append(matrix[ml][n])
            ml+=1
            if ml>mr: break
            for m in range(ml,mr+1):
                res.append(matrix[m][nr])
            nr-=1
            if nl>nr: break
            for n in range(nl,nr+1)[::-1]:
                res.append(matrix[mr][n])
            mr-=1
            if ml>mr: break
            for m in range(ml,mr+1)[::-1]:
                res.append(matrix[m][nl])
            nl+=1
            if nl>nr: break
        return res



s = Solution()
print s.spiralOrder(M) ==[1,2,3,6,9,8,7,4,5]
print s.spiralOrder([])==[]
print s.spiralOrder([[2,3]])
print s.spiralOrder([[1]])
