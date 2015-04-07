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
        lineCount = {}

        # all lines
        for i in range(len(points)-1):
            for j in range(i+1,len(points)):
                dx = float(points[i].x-points[j].x)
                dy = float(points[i].y-points[j].y)

                if dx==0:
                    line = (None,points[i].x)
                else:
                    slope = dy/dx
                    y0 = points[i].y - points[i].x*slope
                    line = (y0, slope)

                lineCount[line]=0

        # check each point for every line
        for p in points:
            for (y0,slope) in lineCount:
                if y0==None:
                    if p.x==slope:
                        lineCount[(y0,slope)]+=1
                elif p.x!=0 and float(p.y-y0)/p.x==slope:
                    lineCount[(y0,slope)]+=1
                elif p.x==0 and p.y!=y0 and slope!=0 and p.x/float(p.y-y0)==1/slope:
                    lineCount[(y0,slope)]+=1

        return max(lineCount.values())

points = [Point(),Point()]
s=Solution()
print s.maxPoints(points) # 2
print s.maxPoints([Point(0,0),Point(-1,-1),Point(2,2)]) # 3
