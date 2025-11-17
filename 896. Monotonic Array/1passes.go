func isMonotonic(nums []int) bool {

	IsIncr := true
	IsDecr := true

	for i := 1; i < len(nums); i++ {

		IsIncr = IsIncr && (nums[i-1] <= nums[i])
		IsDecr = IsDecr && (nums[i-1] >= nums[i])
		if !IsIncr && !IsDecr {
			return false
		}
	}

	return true

}
