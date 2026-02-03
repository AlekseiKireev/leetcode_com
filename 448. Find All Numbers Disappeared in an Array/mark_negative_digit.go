func findDisappearedNumbers(nums []int) []int {
    cntExistNum := 0
	for _, n := range nums {
        idxExistN := Abs(n) - 1
        if nums[idxExistN] > 0 {
            cntExistNum++
            nums[idxExistN] = -nums[idxExistN]
        }

	}

	disNums := make([]int, 0, len(nums) - cntExistNum)  
	for i, n := range nums {
		if n > 0 {
			disNums = append(disNums, i+1)
		}
	}

	return disNums
}

func Abs(n int) int {
	if n > 0 {
		return n
	}

	return -n
}
