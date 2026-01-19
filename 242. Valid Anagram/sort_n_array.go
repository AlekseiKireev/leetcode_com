func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

    // dataRepeatChar := [128]int{}
    var dataRepeatChar [128]int 
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
