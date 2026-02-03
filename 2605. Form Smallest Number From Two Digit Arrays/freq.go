func minNumber(nums1, nums2 []int) int {
    var freq [10]int

    fillFreq(&freq, nums1)
    fillFreq(&freq, nums2)

    for i, n := range freq{
        if n == 2 {
            return i
        }
    }

    min1 := getMin(nums1)
    min2 := getMin(nums2)

    if min2 < min1{
        min1, min2 = min2, min1
    }

    return min1*10 + min2
}

func getMin(nums []int) (ans int) {
    ans = nums[0]
    for _, n := range nums {
        ans = min(ans, n)
    }

    return ans
}

func fillFreq(freq *[10]int, nums []int) {
    for _, n := range nums {
        freq[n]++
    }
}
