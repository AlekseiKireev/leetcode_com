func lengthOfLongestSubstring(Str string) int {
    UnSet := make(map[byte]struct{}, len(Str))
    LLS := 0

    LeftPtr := 0

    for RightPtr := 0; RightPtr < len(Str); RightPtr++ {

        for _, ok := UnSet[Str[RightPtr]]; ok; LeftPtr++{

            delete(UnSet, Str[LeftPtr])
             _, ok = UnSet[Str[RightPtr]] 
        }

        UnSet[Str[RightPtr]] = struct{}{}
        LLS = max(LLS, RightPtr-LeftPtr+1)
    }

    return LLS
}
