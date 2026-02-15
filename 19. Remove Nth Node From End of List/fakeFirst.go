func removeNthFromEnd(head *ListNode, n int) *ListNode {
    dummy := &ListNode{Next: head}

    fast := dummy
    slow := dummy

    // делаем gap = n
    for i := 0; i < n; i++ {
        fast = fast.Next
    }

    // двигаем оба до конца
    for fast.Next != nil {
        fast = fast.Next
        slow = slow.Next
    }

    // удаляем элемент
    slow.Next = slow.Next.Next

    return dummy.Next
}
