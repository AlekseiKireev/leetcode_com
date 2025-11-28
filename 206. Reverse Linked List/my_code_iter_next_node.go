// Definition for singly-linked list.
// type ListNode struct {
//     Val  int
//     Next *ListNode
// }

/*
Time complexity: O(n)
Space complexity: O(1)
*/
func reverseList(head *ListNode) *ListNode {
    var reversed *ListNode = nil // будет хранить перевернутый список

    for head != nil {
        nextNode := head.Next   // сохраняем следующую ноду, чтобы не потерять остаток списка
        head.Next = reversed    // меняем направление ссылки
        reversed = head         // обновляем указатель на перевернутую часть
        head = nextNode         // переходим к следующей ноде
    }

    return reversed
}
