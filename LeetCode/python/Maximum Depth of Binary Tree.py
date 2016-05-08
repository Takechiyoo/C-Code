# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def __init__(self):
        self.depth = 0
    
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):
        if root == None:
            return self.depth
        self.depth += 1
        L = []
        if root.left != None:
            L.append(root.left)
        if root.right != None:
            L.append(root.right)
        self.levelTra(L)
        return self.depth
        
    def levelTra(self, L):
        if len(L) == 0:
            return 
        self.depth += 1
        l = []
        for i in range(0, len(L)):
            if L[i].left != None:
                l.append(L[i].left)
            if L[i].right != None:
                l.append(L[i].right)
        self.levelTra(l)