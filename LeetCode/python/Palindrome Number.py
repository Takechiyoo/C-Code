class Solution:
    # @return a boolean
    def isPalindrome(self, x):
    	if x < 0:
    		return  False
    	# if int(x/10) == 0:
    	# 	return True
    	result = 0
    	xx = x
    	# i = 1
    	while True:
    		if xx == 0:
    			break
    		result = 10 * result + xx % 10
    		xx = int(xx / 10)
    		print('xx is:', str(xx))
    		# i = i * 10
    	print('result is:' + str(result))
    	return x == result


s = Solution()
if s.isPalindrome(12331):
	print("succeed!")
else:
	print("failed!")