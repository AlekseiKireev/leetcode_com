package main

import "fmt"

func main() {
	s1, s2 := []int{1, 2, 3}, []int{4, 5, 6, 7, 8}
	fmt.Println(zip(s1, s2, []int{9, 10}))
}
func zip(s ...[]int) [][]int {

	lenS := len(s)
	if lenS == 0 {
		return [][]int{}
	} // инвариант: lenS > 0 --> exist s[0]

	minLenSubS := len(s[0])
	for _, SubS := range s {
		tmpSize := len(SubS)
		if tmpSize < minLenSubS {
			minLenSubS = tmpSize
		}
	}

	ans := make([][]int, 0, minLenSubS)
	for sub_i := 0; sub_i < minLenSubS; sub_i++ {

		tmp := make([]int, 0, lenS)
		for i := 0; i < lenS; i++ {
			tmp = append(tmp, s[i][sub_i])
		}
		ans = append(ans, tmp)
	}

	return ans

}

/*
[
[]int{1, 2, 3},
[]int{4, 5, 6, 7, 8},
[]int{9,10}
]
ans = [[1 4 9] [2 5 10]]
*/
