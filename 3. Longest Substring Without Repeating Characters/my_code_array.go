func lengthOfLongestSubstring(s string) (LLS int) {
	var DataRepeatChar [256]bool

	L, R := 0, 0
	for ; R < len(s); R++ {

		for ; DataRepeatChar[s[R]] == true; L++ {
			DataRepeatChar[s[L]] = false
		}
		DataRepeatChar[s[R]] = true
		LLS = max(LLS, R-L+1)

	}

	return LLS
}
