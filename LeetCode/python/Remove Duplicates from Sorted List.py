class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	def deleteDuplicates(self, head):
		p1= head
		p2 = p1.next
		while p2 != None:
			if p1.val == p2.val:
				p1.next = p2.next
				p2 = p2.next
				continue
			p1 = p2
			p2 = p2.next
		while head != None:
			print(head.val)
			head = head.next

l1 = ListNode(1)
l2 = ListNode(1)
l3 = ListNode(2)
l4 = ListNode(3)
l5 = ListNode(4)
l6 = ListNode(5)
L7 = ListNode(6)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6
l6.next = L7
s = Solution()
s.deleteDuplicates(l1)