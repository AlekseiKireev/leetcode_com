func isSubsequence(s string, t string) bool {
    
    if len(s) == 0 {
        return true
    }

    if len(s) > len(t) || len(t) == 0 {
        return false
    }    

    sPtr := 0

    for tPtr := 0; tPtr < len(t); tPtr++{

        if(s[sPtr] == t[tPtr]){
            sPtr++
        }

        if sPtr == len(s) {
            return true
        }

    }

    return false
}
