func merge(nums1 []int, m int, nums2 []int, n int) {

	ptr1 := m - 1
	ptr2 := n - 1

	for idx := len(nums1) - 1; ptr2 >= 0; idx-- {

		if ptr1 >= 0 && nums1[ptr1] >= nums2[ptr2] {
			nums1[idx] = nums1[ptr1]
			ptr1--
		} else {
			nums1[idx] = nums2[ptr2]
			ptr2--

		}

	}

}
