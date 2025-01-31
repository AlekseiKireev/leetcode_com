https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/ -- подзадача

https://leetcode.com/problems/longest-increasing-subsequence/description/  
https://contest.yandex.ru/contest/45469/problems/22/  
https://www.geeksforgeeks.org/longest-increasing-subarray/  
https://t.me/lordsStash/411  

Вывести длину максимальной непрерывно возрастающей/убывающей последовательности

нет смысла искать правую границу: обновляем только левую и длину, тогда возврат будет: {LeftPtr, LeftPtr + MaxSize - 1} — это если я правильно понял задачу, что надо найти левую и правую границу

дан массив. надо вернуть `pair<int, int> где максимальная длина монотонно возрастающего или убывающего под массива. требования: O(1) O(n)

    Input: nums = [2,2,2,2,2]
    Output: 1
