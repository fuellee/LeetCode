# Definition for a point
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        if len(points)==0:
            return 0
        elif len(points)==1:
            return 1
        dirCount = {}
        for i in range(len(points)-1):
            for j in range(i+1,len(points)):
                dx = float(points[i].x-points[j].x)
                dy = float(points[i].y-points[j].y)

                if dx==0:
                    line = points[i].x
                else:
                    slope = dy/dx
                    y0 = points[i].y - points[i].x*slope
                    line = (y0, slope)

                if line not in dirCount:
                    dirCount[line]=2
                else:
                    dirCount[line]+=1
        print dirCount
        return max(dirCount.values())

points = [Point(),Point()]
s=Solution()
print s.maxPoints(points) # 2
print s.maxPoints([Point(0,0),Point(-1,-1),Point(2,2)]) # 3
