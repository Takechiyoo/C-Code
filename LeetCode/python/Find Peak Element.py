def Helper(num, low, high):
	if low == high:
		return low
	else:
		mid1 = int((low + high) / 2)
		mid2 = mid1 + 1
		if num[mid1] > num[mid2]:
			return Helper(num, low, mid1)
		else:
			return Helper(num, mid2, high)


def findPeakElement(num):
	return Helper(num, 0, len(num)-1)

# num = [1,2,3,5,7,4,6,3,10]
num = [7,5,6]
print(findPeakElement(num))