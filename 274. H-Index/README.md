https://leetcode.com/problems/h-index/description/

O(n log n) time https://leetcode.com/problems/h-index/solutions/70768/java-bucket-sort-o-n-solution-with-detail-explanation/

O(n) time https://leetcode.com/problems/h-index/solutions/4308437/h-index-easy-solution-brute-force-or-binary-search/

количество статей <= количество цитирования == c[i] 

Если данные отсортированны, то 
* c[i] -- количество цитирования i статьи
*  n-i -- количество опубликованных статей таких, что c[t] >= c[i] : t > i
