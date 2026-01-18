func lengthOfLongestSubstring(s string) (LLS int) {
	DataRepeatChar := make(map[byte]bool)

	for L, R := 0, 0; R < len(s); R++ {
		for ; DataRepeatChar[s[R]]; L++ {
			DataRepeatChar[s[L]] = false

		}
		DataRepeatChar[s[R]] = true
		LLS = max(LLS, R-L+1)
	}
	return LLS
}
