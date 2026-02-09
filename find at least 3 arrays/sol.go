
package main

import "fmt"

func findCommon(a, b, c []int) (int, bool) {
	i, j, k := 0, 0, 0

	for i < len(a) && j < len(b) && k < len(c) {
		x, y, z := a[i], b[j], c[k]

		if x == y && y == z {
			return x, true
		}

		min := min(x, y, z)

		// двигаем указатель(и) с минимальным значением
		if x == min {
			i++
		}
		if y == min {
			j++
		}
		if z == min {
			k++
		}
	}

	return 0, false
}

func main() {
	a := []int{1, 2, 4, 5}
	b := []int{3, 3, 4}
	c := []int{2, 3, 4, 5, 6}

	if val, ok := findCommon(a, b, c); ok {
		fmt.Println(val) // 4
	} else {
		fmt.Println("common element not found")
	}
}
