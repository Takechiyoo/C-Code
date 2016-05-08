# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.figure = True
    def depth(self, p, q):
        if self.figure == False:
            return
        if p == None and q == None:
            return 
        if p == None or q == None:
            self.figure = False
            return
        if p.val == q.val:
            self.depth(p.left, q.left)
        else:
            self.figure = False
            return 
        self.depth(p.right, q.right)
    # @param p, a tree node
    # @param q, a tree node
    # @return a boolean
    def isSameTree(self, p, q):
        self.depth(p, q)
        return self.figure