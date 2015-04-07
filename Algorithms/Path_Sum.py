# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers

    def pathSum(self, root, sum):
        pathes = []
        def search(root, sum,path):
            if root is None:
                return
            sum=sum-root.val
            path = path+[root.val]
            if root.left==None and root.right==None:
                if sum==0: pathes.append(path)
                return
            else:
                search(root.left, sum, path)
                search(root.right, sum, path)
                return
        search(root,sum,[])
        return pathes
