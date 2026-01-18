func isValid(s string) bool {

	OpenToClosed := map[rune]rune{
		'(': ')',
		'[': ']',
		'{': '}',
	}

	stackOpen := make([]rune, 0, len(s))

	for _, ch := range s { /*range s возвращает rune*/
		if _, exist := OpenToClosed[ch]; exist {
			stackOpen = append(stackOpen, ch)
		} else {
			if len(stackOpen) == 0 {
				return false
			}

			idxTop := len(stackOpen) - 1
			if ch != OpenToClosed[stackOpen[idxTop]] {
				return false
			}

			stackOpen = stackOpen[:idxTop]
		}
	}

	return len(stackOpen) == 0

}
