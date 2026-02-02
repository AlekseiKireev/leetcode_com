package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(uniqRandn(10))
}
func uniqRandn(n int) []int {

	unSet := make(map[int]struct{}, n) // n нужно для ограничения снизу коичества бакетов
	ans := make([]int, 0, n)
	for len(unSet) != n {
		val := rand.Int()
		if _, ok := unSet[val]; !ok {
			ans = append(ans, val)
		}
		unSet[val] = struct{}{}
	}

	return ans
}
