func isPalindrome(s string) bool {
    
    L := 0
    R := len(s) - 1

    for L < R  {

        for ;L < R && !isAlphanumeric(s[L]);L++{}
        for ;L < R && !isAlphanumeric(s[R]);R--{}

        if unicode.ToLower(rune(s[L])) != unicode.ToLower(rune(s[R])) {
            return false
        }
        L++
        R--
    }

    return true
}

func isAlphanumeric(ch byte) bool {
    return unicode.IsLetter(rune(ch)) || unicode.IsDigit(rune(ch))
}
