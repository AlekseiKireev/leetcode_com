func backspaceCompare(s string, t string) bool {
    
    sIdx := len(s) - 1
    tIdx := len(t) - 1

    for (sIdx >= 0) || (tIdx >= 0) {

        backspace := 0
        for sIdx >=0 && (s[sIdx] == '#' || backspace > 0) {

            if s[sIdx] == '#' {
                backspace += 1
            }else{
                backspace -= 1
            }
            sIdx--
            

        } // sIdx < 0 || s[sIdx] != '#'
        //fmt.Println("sIdx : ", sIdx)

        backspace = 0
        for tIdx >=0 && (t[tIdx] == '#' || backspace > 0) {

            if t[tIdx] == '#' {
                backspace += 1
            }else{
                backspace -= 1
            }
            tIdx--
            

        } // tIdx < 0 || t[tIdx] != '#'
        //fmt.Println("tIdx : ", tIdx)

        if sIdx >= 0 && tIdx >= 0 && s[sIdx] != t[tIdx] {
            return false
        }
        // один из указателей гарантированно указывает на символ != #
        // в то время как в иной строке гарантировано закончились символы
        if (sIdx >= 0) != (tIdx >= 0) {
            return false
        }
        sIdx--
        tIdx--

    }

     return true
}
