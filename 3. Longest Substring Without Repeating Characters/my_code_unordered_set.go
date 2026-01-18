func lengthOfLongestSubstring(Str string) int {
    DataRepeatChar := make(map[byte]struct{}, len(Str))
    LLS := 0

    LeftPtr := 0

    for RightPtr := 0; RightPtr < len(Str); RightPtr++ {

        for _, ok := DataRepeatChar[Str[RightPtr]]; ok; LeftPtr++{

            delete(DataRepeatChar, Str[LeftPtr])
             _, ok = DataRepeatChar[Str[RightPtr]] 
        }

        DataRepeatChar[Str[RightPtr]] = struct{}{}
        LLS = max(LLS, RightPtr-LeftPtr+1)
    }

    return LLS
}
