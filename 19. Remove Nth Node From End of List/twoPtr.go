/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	rPtr := head
	for ; n != 0; n-- {
		rPtr = rPtr.Next
	}

	if rPtr == nil {
		head = head.Next
		return head
	}

	lPtr := head

	for rPtr.Next != nil {
		rPtr = rPtr.Next
		lPtr = lPtr.Next
	}

	lPtr.Next = lPtr.Next.Next
	return head
}
