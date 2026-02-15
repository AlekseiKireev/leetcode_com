import "unicode"

func isPalindrome(s string) bool {
    i, j := 0, len(s)-1

    for i < j {
        left := rune(s[i])
        right := rune(s[j])
        
        if !isAlphanumeric(left) {
            i++
            continue
        }

        if !isAlphanumeric(right) {
            j--
            continue
        }

        if unicode.ToLower(left) != unicode.ToLower(right) {
            return false
        }

        i++
        j--
    }

    return true
}

func isAlphanumeric(r rune) bool {
    return unicode.IsLetter(r) || unicode.IsDigit(r)
}
