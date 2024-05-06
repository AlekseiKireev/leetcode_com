https://leetcode.com/problems/merge-k-sorted-lists/

related: https://github.com/SkosMartren/leetcode_com/tree/main/21.%20Merge%20Two%20Sorted%20Lists

______

у Федора Меньшикова разбор отсут-т!

______

https://leetcode.com/problems/merge-k-sorted-lists/solutions/10531/sharing-my-straightforward-c-solution-without-data-structure-other-than-vector/

I agree with @cqnkxy.

During 1st iteration, we merge two lists(every list is N) into one, this will make K down to K / 2.

During 2nd iteration, we merge two lists(every list is 2N) into one, this will make K / 2 down to k /4.

During 3rd iteration, we merge two lists(every list is 4N) into one, this will make K / 4 down to k /8.

And so forth...

I think when we merge two lists, the complexity is O(list1.length) + O(list2.length).

So the total complexity is:

(2N) * (K / 2) + 
(4N) * (K / 4) + 
(8N) * (K / 8) + 
.............. + 
(2^logK*N) * (K / (2 ^logK)) 

= logK*KN

ChatGPT
Да, это верный анализ.

Каждая итерация цикла while объединяет два списка, каждый из которых имеет размер O(N), и добавляет новый список в конец вектора. Таким образом, после i-ой итерации у нас будет K/2^i списков, каждый из которых будет иметь размер O(2^iN), а суммарное количество элементов в этих списках будет равно KN.

Асимптотика объединения двух списков в функции mergeTwoLists зависит от их размеров. Если размеры списков равны N и M, то асимптотика будет O(N+M), что можно записать как O(max(N, M)). В нашем случае, мы каждый раз объединяем два списка, каждый из которых удваивается по размеру, поэтому асимптотика объединения в худшем случае будет O(N), где N - размер одного списка.

Таким образом, общая асимптотика будет суммой асимптотик всех итераций цикла while, что будет равно:

O(2N * K / 2 + 4N * K / 4 + 8N * K / 8 + ... + (2^logK * N) * K / (2^logK))

Это арифметическая прогрессия, и если сложить все элементы этой прогрессии, то получится O(logK * KN), что соответствует вашему анализу.
