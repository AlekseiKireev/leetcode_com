func isValid(s string) bool {

	OpenToClosed := map[byte]byte{
		'(': ')',
		'[': ']',
		'{': '}',
	}

	stackOpen := make([]byte, 0, len(s))

	for i:=0;i<len(s) ;i++ { 
		if _, exist := OpenToClosed[s[i]]; exist {
			stackOpen = append(stackOpen, s[i])
		} else {
			if len(stackOpen) == 0 {
				return false
			}

			idxTop := len(stackOpen) - 1
			if s[i] != OpenToClosed[stackOpen[idxTop]] {
				return false
			}

			stackOpen = stackOpen[:idxTop]
		}
	}

	return len(stackOpen) == 0

}
