https://leetcode.com/problems/3sum/ -- по сути задачу можно обобщить на поиск суммы любого числа, надо лишь вместо нуля вставить искомое число в условном операторе для push_back и при сдвиге k

related: 
- https://leetcode.com/problems/two-sum/
  - https://github.com/SkosMartren/leetcode_com/tree/main/1.%20Two%20Sum
- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
  - https://github.com/SkosMartren/leetcode_com/tree/main/167.%20Two%20Sum%20II%20-%20Input%20Array%20Is%20Sorted
- https://leetcode.com/problems/3sum-closest/
  - https://github.com/SkosMartren/leetcode_com/tree/main/16.%203Sum%20Closest -- на основе my_code_sort.cpp написан код my_code_3SumClosest.cpp
https://walkccc.me/LeetCode/problems/0015/

_______

[Разбор задачи 15 leetcode.com 3Sum. Решение на C++](https://www.youtube.com/watch?v=F3hwiKebyCw)

Меньше какой сложности нельзя? 

n=1000

n/4 чисел положительных 1..250  
n/4 чисел положительных ещё 1..250   
n/2 чисел отрицательных -1..-500

любая сумма двух положительных чисел найдёт отрицательное число, которое даёт в сумме 0.

n/4*п/4 - O(n^2) - меньше O(n^2) нельзя действий просто потому что такой размер ответа может быть.

свести задачу к меньшей. Например, перебираем одно число - и остаётся сумма двух.

leetcode 1 Two Sum - с хэш-таблицей. Массив не отсортирован.

leetcode 167 Two Sum II - input аггау is sorted - два указателя.

По времени предпочтительнее работать с отсортированным массивом.  
sort работает за O(nlogn) - мало по сравнению с O(n^2) ожидаемое сложностью.

- сортируем
- перебираем одно из чисел
- методом leetcode 167 находим пару/несколько соответствующих чисел.

Уникальность ответа:
1. Каждая тройка ответа должна быть отсортирована.
2. Обеспечить отсутствие повторов:  
2.1. set для ответа/unordered_set/sort  
2.2. правильный порядок перебора - тройки могут  
поступать в отсортированном порядке -единственное, с чем нужно сравнить тройку - с предыдущей.

При переборе первого числа от меньших к бОльшим - автоматом первое число тройки будет повозрастанию.
Второе и третье должны быть больше первого. Третье больше второго.

2 указателя нужно делать только на фрагменте массива "справа" от первого числа.

_______

Input nums = [-2,-2,-2,-2,2,0] Expected [[-2,0,2]]

Input nums = [-2,-2,-2,-2,2,2,0,0] Expected [[-2,0,2]]

Input nums = [-2,-2,-2,-2,2,2,2,0,0,0] Expected [[-2,0,2],[0,0,0]]


<p align="center">Example 1:</p>

Будем работать с отсортированным nums, таким образом, что проитерируемся по всем индексам по возрастанию $(i, j) : i != j$ AND $0 <= i <= nums.size() - 3$ AND $i + 1 <= j <= nums.size() - 2$ -- при этом третий индекс $k$ будем искать исходя из свойства отсортированности $nums$: 
- пока nums[i] + nums[j] < 0, будем рассматривать сумму $S = nums[i] + nums[j] + nums[k]$ до тех пор, пока $S > 0$, при этом $j + 1 <= k <= nums.size() - 1$ и по k будем итерировваться по убыванию. Это необходимо для того, чтобы найти первый $nums[k]$, такой, что $S <= 0$ -- далее проверяем, имеет ли место $S == 0$

| idx  	|   	| 0  	|  1 	|  2 	|  3	|  4	| 5 	|
|------	|---	|----	|----	|----	|---	|---	|---	|
| nums 	|   	| -4 	| -1 	| -1 	| 0 	| 1 	| 2 	|
| i    	|   	| ^  	|    	|    	|   	|   	|   	|
| j    	|   	|    	| ^  	|    	|   	|   	|   	|
| k    	|   	|    	|    	|    	|   	|   	| ^ 	|

Последний проход: 

| idx  	|   	| 0  	|  1 	|  2 	|  3	|  4	| 5 	|
|------	|---	|----	|----	|----	|---	|---	|---	|
| nums 	|   	| -4 	| -1 	| -1 	| 0 	| 1 	| 2 	|
| i    	|   	|    	|    	|    	| ^ 	|   	|   	|
| j    	|   	|    	|    	|    	|   	| ^ 	|   	|
| k    	|   	|    	|    	|    	|   	|   	| ^ 	|

__________
    /*
    [-100, -2, -2, 0, 1,1,2]
    Stdout
    push_back 1
    push_back 1
    2
    */
    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& a) {
            
            sort(a.begin(), a.end());
            vector<vector<int>> ans;
                   
            for (int i = 0; i + 2 < (int)a.size(); i++) { // move i [== first ptr] forward
               
                if (i > 0 && a[i] == a[i - 1]) {cout << i << '\n';continue;} // for nums = [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6] Expected[[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]
    
                int k = (int)a.size() - 1;
                for (int j = i + 1; j < k; j++) { // move j [ == second ptr] forward
    
                    while (j < k - 1 && a[i] + a[j] + a[k] > 0) { // move k [ == third ptr] backward
                        k--;
                    }
                    
                    if (a[i] + a[j] + a[k] == 0) {
                        if (ans.empty() || a[i] != ans.back()[0] || a[j] != ans.back()[1] || a[k] != ans.back()[2]) {
                            cout << "push_back " << i << '\n';
                            ans.push_back({ a[i], a[j], a[k] });
                        }
                    }
                }
            }
            return ans;
        }
    };
