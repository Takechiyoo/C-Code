class TreeNode:
	"""docstring for TreeNode"""
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None

def isT(left, right):
	if left == None and right == None:
		return True
	if left == None or right == None:   #这里还是很妙的，因为有前两行代码作保证，所以这里使用这样一条代码就可以同时确定左子树为空右子树不为空，或右子树为空左子树不为空两种情况
		return False

	return left.val == right.val and isT(left.left, right.right) and isT(left.right, right.left)

def isSymmetric(root):
	if root == None:
		return True
	return isT(root)
		