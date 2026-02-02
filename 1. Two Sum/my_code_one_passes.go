func twoSum(nums []int, target int) []int {
	NumToIdx := make(map[int]int, len(nums))

	for i, num := range nums {

								
		// NumToIdx[num] = i // nums = [3,2,4] target = 6 Output [0,0] Expected [1,2]
							 // Input nums = [3,3] target = 6 Expected [0,1]
		if complement_idx, ok := NumToIdx[target-num]; ok {
			return []int{complement_idx, i}
		}

		NumToIdx[num] = i
	}

	return nil
}
