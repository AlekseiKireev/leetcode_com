func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

    // dataRepeatChar := make(map[byte]int, len(s))
    var dataRepeatChar map[byte]int
    dataRepeatChar = make(map[byte]int, len(s))
	for i := 0; i < len(s); i++ {
        dataRepeatChar[s[i]] +=1
        dataRepeatChar[t[i]] -=1
	}

    for _, v := range dataRepeatChar{
	if v != 0 {
		return false
	}        
    }

    return true
}
