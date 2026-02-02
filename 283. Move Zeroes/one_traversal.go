func moveZeroes(nums []int) {
	Val := 0 
	PtrOnSwapFirstVal := 0 // == Count(NotVal)
    // в любом префиксе действует инвариант: Count(Val) + Count(NotVal) == i
    // при Count(Val) != 0 между PtrOnSwapFirstVal и i возникает окно из Val
    // длиною Count(Val), при это PtrOnSwapFirstVal всегда указывет на первый
    // элемент этого окна
	for i := 0; i < len(nums); i++ {
		if nums[i] != Val { // // != -->  [1,2,3,4]
			nums[i], nums[PtrOnSwapFirstVal] = nums[PtrOnSwapFirstVal], nums[i]
            PtrOnSwapFirstVal++
			
		}
	}
}
