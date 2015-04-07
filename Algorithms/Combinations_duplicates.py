def combination(num, n):
     num.sort()
     res = []
     N = len(num)
     def com(start,acc):
         if len(acc)==n:
             res.append(acc)
         elif start>=N:
             return
         else:
             for i in range(start,N):
                 if(i==start or num[i]!=num[i-1]):
                     com(i+1,acc+[num[i]])

     com(0,[])
     return res

print combination([1,1,2,2,3,4],3)
