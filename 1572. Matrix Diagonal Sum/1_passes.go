func diagonalSum(mat [][]int) (sum int) {

	len_mat := len(mat)	
	for i := 0; i < len_mat; i++ {
		sum += (mat[i][i] + mat[i][len_mat-i-1])
	}

	return sum - mat[len_mat/2][len_mat/2]*(len_mat%2)

}
