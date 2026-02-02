func isMonotonic(nums []int) bool {
    
	isDec, isInc := true, true
	for i := 1; i < len(nums); i++ {
		if nums[i-1] < nums[i] {
			isDec = false
		} else if nums[i-1] > nums[i] {
			isInc = false
		}

        if !isDec && !isInc {
            return false
        }

	}
	return isDec || isInc
}
