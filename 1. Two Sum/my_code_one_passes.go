func twoSum(nums []int, target int) []int {
	NumToIdx := make(map[int]int)

	for i, num := range nums {
		if complement_idx, ok := NumToIdx[target-num]; ok {
			return []int{complement_idx, i}
		}

		NumToIdx[num] = i
	}

	return nil
}
