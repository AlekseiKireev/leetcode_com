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
/*
func isMonotonic(nums []int) bool {
    desc, asc := true, true

    val := nums[0]

    for i := 1;i < len(nums); i++{
        num := nums[i]
        if(val < num){
            desc = false
        }
        if(val > num){
            asc = false
        }  

        if(!desc && !asc){
            return false
        }
        val = num      
    }

    return true
}
*/
