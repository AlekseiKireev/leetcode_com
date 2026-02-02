func removeElement(nums []int, val int) (PtrOnFirstVal int) {

    for i := 0; i < len(nums); i++{
        if nums[i] != val {
            // nums[updLen++] = nums[i] // syntax error: unexpected ++, expected comma, : or ]
            nums[PtrOnFirstVal] = nums[i]
            PtrOnFirstVal++
        }
    }

     return PtrOnFirstVal
}
