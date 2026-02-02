func twoSum(nums []int, target int) []int {
	NumToIdx := make(map[int]int, len(nums))

	for i, num := range nums {

								
		// NumToIdx[num] = i // nums = [3,2,4] target = 6 Output [0,0] Expected [1,2]
							 // Input nums = [3,3] target = 6 Expected [0,1]
		if complementIdx, ok := NumToIdx[target-num]; ok { // num == nums[i], target = nums[i] + nums[complementIdx]
			return []int{complementIdx, i}
		}

		NumToIdx[num] = i
	}

	return nil
}
