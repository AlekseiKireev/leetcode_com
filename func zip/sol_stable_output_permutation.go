package main

import "fmt"

func main() {
	s1, s2 := []int{1, 2, 3}, []int{4, 5, 6, 7, 8}
	fmt.Println(zip(s1, s2)) // [[1 4] [2 5] [3 6]]
	fmt.Println(zip(s2, s1)) // [[1 4] [2 5] [3 6]]
}
func zip(s1 []int, s2 []int) [][]int {

	if len(s1) > len(s2) {
		return zip(s2, s1)
	}
	// так делать не стоит: доп. затраты на заполнение значениями по умолчанию
	// ввиду указания длины
	/*
		ans := make([][]int, len(s1), len(s1))
		for i := 0; i < len(s1); i++ {
			ans[i] = []int{s1[i], s2[i]}
		}
	*/
	ans := make([][]int, 0, len(s1))
	for i := 0; i < len(s1); i++ {
		ans = append(ans, []int{s1[i], s2[i]})
	}
	return ans

}
