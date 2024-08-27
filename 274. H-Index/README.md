https://leetcode.com/problems/h-index/description/

O(n log n) time https://leetcode.com/problems/h-index/solutions/70768/java-bucket-sort-o-n-solution-with-detail-explanation/

O(n) time https://leetcode.com/problems/h-index/solutions/4308437/h-index-easy-solution-brute-force-or-binary-search/

___

Учёный имеет индекс h, если h из его $N_p$ статей цитируются как минимум h раз каждая, в то время как оставшиеся $(N_p — h)$ статей цитируются не более чем h раз каждая.
___


количество статей <= количество цитирования == c[i] 

Если данные отсортированны, то 
* c[i] -- количество цитирования i статьи
*  n-i -- количество опубликованных статей таких, что c[t] >= c[i] : t > i
