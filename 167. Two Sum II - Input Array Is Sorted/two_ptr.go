func twoSum(nums []int, target int) []int {
	L, R := 0, len(nums)-1

	for target != nums[L]+nums[R] {
		if target < nums[L]+nums[R] {
			R--
		} else {
			L++
		}
	}

	return []int{L + 1, R + 1}
}
