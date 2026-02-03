func findDisappearedNumbers(nums []int) []int {

	unSet := make(map[int]struct{}, len(nums))
	for _, n := range nums {
		unSet[n] = struct{}{}
	}

	ans := make([]int, 0, len(nums)-len(unSet))
	for i := 1; i <= len(nums); i++ {
		if _, ok := unSet[i]; !ok {
			ans = append(ans, i)
		}
	}

	return ans

}
