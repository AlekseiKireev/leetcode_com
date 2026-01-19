func sortedSquares(nums []int) []int {

	SS := make([]int, len(nums))

	L := 0
	R := len(nums) - 1

	for IdxSS := len(nums) - 1; IdxSS >= 0; IdxSS-- {
		var Max int

		if nums[L]*nums[L] < nums[R]*nums[R] {
			Max = nums[R] * nums[R]
			R--
		} else {
			Max = nums[L] * nums[L]
			L++
		}
		SS[IdxSS] = Max

	}

	return SS
}
