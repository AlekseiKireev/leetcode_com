<details>  
<summary>  Topics </summary>

<details>  
<summary>backtracking</summary>

- [17. Letter Combinations of a Phone Number](https://github.com/AlKiAl/leetcode_com/tree/main/17.%20Letter%20Combinations%20of%20a%20Phone%20Number) -- 3 nested loops: digits / ans / digitToLetters. Ex: "23" --> ["ad","ae","af","bd","be","bf","cd","ce","cf"]
- [93. Restore IP Addresses](https://github.com/SkosMartren/leetcode_com/tree/main/93.%20Restore%20IP%20Addresses) -- 3 nested loops to generate a num + check 0 <= num <= 255. Ex: "101023" --> ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
  
</details>


<details>
<summary>Binary search</summary>

- [4. Median of Two Sorted Arrays](https://github.com/SkosMartren/leetcode_com/tree/main/4.%20Median%20of%20Two%20Sorted%20Arrays)
- [74. Search a 2D Matrix](https://github.com/SkosMartren/leetcode_com/tree/main/74.%20Search%20a%202D%20Matrix) -- (i,j) <--> j * CountColumn + i : j == line, i == column
- [658. Find K Closest Elements](https://github.com/SkosMartren/leetcode_com/tree/main/658.%20Find%20K%20Closest%20Elements)
- [704. Binary Search](https://github.com/SkosMartren/leetcode_com/tree/main/704.%20Binary%20Search)

  <details>
  <summary>Bitonic sequence</summary>

  - [Bitonic sort](https://www.geeksforgeeks.org/bitonic-sort/)
  - [Wikipedia: Bitonic sorter](https://en.wikipedia.org/wiki/Bitonic_sorter)
  - [Сеть Бетчера](https://neerc.ifmo.ru/wiki/index.php?title=%D0%A1%D0%B5%D1%82%D1%8C_%D0%91%D0%B5%D1%82%D1%87%D0%B5%D1%80%D0%B0)
  - [1752. Check if Array is Sorted and Rotated](https://github.com/AlKiAl/leetcode_com/tree/main/1752.%20Check%20if%20Array%20Is%20Sorted%20and%20Rotated) -- one passes + if (nums[i] > nums[(i + 1) % n] && ++rotates > 1) {return false;}    
  - if(nums[Left] <= nums[Mid]){ nums[Left..Mid] are sorted }else{nums[Mid..Right] are sorted}
   - [153. Find Minimum in Rotated Sorted Array](https://github.com/SkosMartren/leetcode_com/tree/main/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array)
   - [33. Search in Rotated Sorted Array](https://github.com/SkosMartren/leetcode_com/tree/main/33.%20Search%20in%20Rotated%20Sorted%20Array) - distinct val. --> [81. Search in Rotated Sorted Array II](https://github.com/AlKiAl/leetcode_com/tree/main/81.%20Search%20in%20Rotated%20Sorted%20Array%20II) - not necessarily distinct val.

  </details>
</details>

<details>  
<summary>Binary sequence</summary>
  
- One passes + 2 ptr + check on cnt zeros in [nums[L], ..., nums[R]]
  
- [485. Max Consecutive Ones](https://github.com/AlKiAl/leetcode_com/tree/main/485.%20Max%20Consecutive%20Ones)
- [487. Max Consecutive Ones II](https://github.com/AlKiAl/leetcode_com/tree/main/487.%20Max%20Consecutive%20Ones%20II) -- T.P. Flip at most 2 zeros
- [1004. Max Consecutive Ones III](https://github.com/SkosMartren/leetcode_com/tree/main/1004.%20Max%20Consecutive%20Ones%20III) -- T.P. Flip at most k zeros
- [1493. Longest Subarray of 1's After Deleting One Element](https://github.com/SkosMartren/leetcode_com/tree/main/1493.%20Longest%20Subarray%20of%201's%20After%20Deleting%20One%20Element) -- T.P. Upd 1 zero
--- 
- [849. Maximize Distance to Closest Person](https://github.com/SkosMartren/leetcode_com/tree/main/849.%20Maximize%20Distance%20to%20Closest%20Person) + counting 1 in Prefix / Suffix (see 485) / Postfix
- [605. Can Place Flowers](https://github.com/SkosMartren/leetcode_com/tree/main/605.%20Can%20Place%20Flowers) -- Can be planted in without violating the no-adjacent-flowers rule. One passes + check going abroad

</details>

<details>  
<summary>Bitwise operator</summary>

- [136. Single Number](https://github.com/SkosMartren/leetcode_com/tree/main/136.%20Single%20Number)
- [137. Single Number II](https://github.com/SkosMartren/leetcode_com/tree/main/137.%20Single%20Number%20II)
- [268. Missing Number](https://github.com/SkosMartren/leetcode_com/tree/main/268.%20Missing%20Number)

</details>


<details>  
<summary>Data compression (One passes + 2 ptr) </summary>

  <details>  
  <summary>Summary Ranges (SR). Ex: [0,1,2,4,5,7] --> ["0->2","4->5","7"] </summary> 
    
- [228. Summary Ranges](https://github.com/SkosMartren/leetcode_com/tree/main/228.%20Summary%20Ranges) -- external loop: ++RightPtr, internal loop: ++RightPtr AND nums[RightPtr] == nums[RightPtr+1] - 1
- [Summary Ranges Unsorted](https://github.com/AlKiAl/leetcode_com/tree/main/Summary%20Ranges%20Unsorted) --> [128. Longest Consecutive Sequence](https://github.com/AlKiAl/leetcode_com/tree/main/128.%20Longest%20Consecutive%20Sequence) -- Length of the longest SR. + NumUnSet(arr.begin(), arr.end())
  </details>  
  
  <details>  
  <summary>RLE. Ex: ["a","a","b","b","c","c","c"] --> ["a","2","b","2","c","3"] </summary>    

  - [Кодирование длин серий](https://ru.wikipedia.org/wiki/%D0%9A%D0%BE%D0%B4%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5_%D0%B4%D0%BB%D0%B8%D0%BD_%D1%81%D0%B5%D1%80%D0%B8%D0%B9)
  - [443. String Compression](https://github.com/AlKiAl/leetcode_com/tree/main/443.%20String%20Compression) -- external loop: ... , internal loop: CurChar == chars[IdxOnOldStr]; ++IdxOnOldStr, ++IdxOnCompressStr
  - [1868. Product of Two Run-Length Encoded Arrays](https://github.com/AlKiAl/leetcode_com/tree/main/1868.%20Product%20of%20Two%20Run-Length%20Encoded%20Arrays) [[1,2], [2,2]] * [[6,2], [3,1], [5,1]] = [1,1,2,2] * [6,6,3,5] = [6,6,6,10] = [[3,6], [1,10]]

  </details>       
</details>

<details>  
<summary>Design</summary>        

- [2241. Design an ATM Machine](https://github.com/SkosMartren/leetcode_com/tree/main/2241.%20Design%20an%20ATM%20Machine)  -- В начале копируем текущее состояние счета, на случай, если снять не удасться, внесем эти данные счета обратно. 
Итерируемся от большей валюты к меньшей, снимаем min(amount / denominations[i], BankAccount[i])

  <details>  
  <summary>Counter</summary>

  События, находящиеся в промежутке ]timestamp - n, timestamp[. Решение с использованием queue (FIFO):  
  - [362. Design Hit Counter](https://github.com/SkosMartren/leetcode_com/tree/main/362.%20Design%20Hit%20Counter) -- (timestamp - 300, timestamp]  
  - [933. Number of Recent Calls](https://github.com/SkosMartren/leetcode_com/tree/main/933.%20Number%20of%20Recent%20Calls) -- [timestamp - 3000, timestamp]  

  </details>        

  <details>  
  <summary>Data Structure</summary>    

  Разница между 155. Min Stack и Max Stack в том, что в 716. Max Stack необходимо реализовать удаление экстремума из очереди:  
  - [155. Min Stack](https://github.com/SkosMartren/leetcode_com/tree/main/155.%20Min%20Stack) -- stack + struct Pair { int Val; int Min;}  
  - [232. Implement Queue using Stacks](https://github.com/SkosMartren/leetcode_com/tree/main/232.%20Implement%20Queue%20using%20Stacks) -- stack + stack  

    <details>  
    <summary>List + mapping (такая связка используется для быстрого удаления из любой позиции по итератору)</summary>    

    - [716. Max Stack](https://github.com/SkosMartren/leetcode_com/tree/main/716.%20Max%20Stack) -- list<int> OrderVal; map< int, vector<list<int>::iterator>, greater<int> > ValToItsOnVal;
    - [146. LRU Cache](https://github.com/SkosMartren/leetcode_com/tree/main/146.%20LRU%20Cache) -- удаляются наименее использованные элементы. unordered_map<int, list<int>::iterator> KeyToItInOrderKey; list<int> OrderKey; unordered_map<int, int> KeyToValue;
    - [960. First Unique Number in Data Stream II](https://github.com/SkosMartren/leetcode_com/tree/main/960%20%C2%B7%20First%20Unique%20Number%20in%20Data%20Stream%20II) -- list<int> UniqieList; unordered_map<int, list<int>::iterator> NumToItr;                    

    </details>
  </details>
</details>  


<details>  
<summary>Dynamic programming</summary>    

- [53. Maximum Subarray](https://github.com/SkosMartren/leetcode_com/tree/main/53.%20Maximum%20Subarray) -- find the subarray with the largest sum
- [1143. Longest Common Subsequence](https://github.com/SkosMartren/leetcode_com/tree/main/1143.%20Longest%20Common%20Subsequence)

---

- [279. Perfect Squares](https://github.com/SkosMartren/leetcode_com/tree/main/279.%20Perfect%20Squares) -- return the least number of numbers degree k that sum to n  
- [322. Coin Change](https://github.com/AlKiAl/leetcode_com/tree/main/322.%20Coin%20Change)

  ---------------------------------------------------------------------------------------------------  

- [70. Climbing Stairs](https://github.com/SkosMartren/leetcode_com/tree/main/70.%20Climbing%20Stairs)  
- [509. Fibonacci Number](https://github.com/SkosMartren/leetcode_com/tree/main/509.%20Fibonacci%20Number)  

</details>

<details>  
<summary>Edit distance</summary>

- [Wikipedia: Edit distance](https://en.wikipedia.org/wiki/Edit_distance)  
- [72. Edit Distance](https://github.com/AlKiAl/leetcode_com/tree/main/72.%20Edit%20Distance) -- D.P.  
- [161. One Edit Distance](https://github.com/AlKiAl/leetcode_com/tree/main/161.%20One%20Edit%20Distance) -- T.P.  
- [392. Is Subsequence](https://github.com/SkosMartren/leetcode_com/tree/main/392.%20Is%20Subsequence) -- T.P. . no more than min(|s1|,|s2|) editorial distance  
- [680. Valid Palindrome II](https://github.com/AlKiAl/leetcode_com/tree/main/680.%20Valid%20Palindrome%20II) -- T.P. . no more than one editorial distance  
- [1143. Longest Common Subsequence](https://github.com/SkosMartren/leetcode_com/tree/main/1143.%20Longest%20Common%20Subsequence) -- D.P.  

</details>

<details>  
<summary>Graph traversal: DFS / BFS / DSU</summary>    

- [200. Number of Islands](https://github.com/SkosMartren/leetcode_com/tree/main/200.%20Number%20of%20Islands) -- + check going abroad 
- [332. Reconstruct Itinerary](https://github.com/SkosMartren/leetcode_com/tree/main/332.%20Reconstruct%20Itinerary) -- (DFS on UnorderedHash) реконструировать весь маршрут
- [1436. Destination City](https://github.com/SkosMartren/leetcode_com/tree/main/1436.%20Destination%20City) -- (DFS on UnorderedHash) найти конечную точку маршрута
- [721. Accounts Merge](https://github.com/AlKiAl/leetcode_com/tree/main/721.%20Accounts%20Merge) -- unordered_map<string, vector<string>> FirstEmailToChild
- [310. Minimum Height Trees](https://github.com/AlKiAl/leetcode_com/tree/main/310.%20Minimum%20Height%20Trees) -- find the center of the graph. DFS + control cnt leafs
  
</details>

<details>  
<summary>Greedy</summary>    

- [135. Candy](https://github.com/SkosMartren/leetcode_com/tree/main/135.%20Candy) -- обработка ratings[i−l]<...<ratings[i−1]<ratings[i]>...>ratings[i+r] 
- [763. Partition Labels](https://github.com/SkosMartren/leetcode_com/tree/main/763.%20Partition%20Labels) -- 2 passes: 1 - Char -> LastIdxChar, 2 - Two ptr: R = max(R, CharToLastIdx[Str[i]]), if(EndCurrentChunk == i) --> L = i + 1. каждая буква встречается не более чем в одном разделе

  ---------------------------------------------------------------------------------------------------  

- [121. Best Time to Buy and Sell Stock](https://github.com/SkosMartren/leetcode_com/tree/main/121.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock) -- one of the best deals. MaximumProfit = max(MaximumProfit, prices[i] - MinPrice);  
- [714. Best Time to Buy and Sell Stock with Transaction Fee](https://github.com/AlKiAl/leetcode_com/tree/main/714.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Transaction%20Fee) --> [122. Best Time to Buy and Sell Stock II](https://github.com/SkosMartren/leetcode_com/tree/main/122.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20II) -- maximum profit you can achieve. hold = max(hold, profit - price); profit = max(profit, hold + price - fee);  
- [123. Best Time to Buy and Sell Stock III](https://github.com/AlKiAl/leetcode_com/tree/main/123.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III) -- maximum profit you can achieve complete at most two transactions. max <-- TotalProfit = prices[n] - prices[m] + p1 == y - (x-p1) : (x-p1) == prices[i] - profit1 --> min
- [Maximize Stock Profit with Daily Prices](https://github.com/AlKiAl/leetcode_com/tree/main/Maximize%20Stock%20Profit%20with%20Daily%20Prices)

</details>

<details>  
<summary>NSum</summary>    

- fix `l`, then loop [l+1, nums.size() - 4], then j = i + 1; k = nums.size() - 1; --> (Sum3 < target) ? ++j : --k;
- [18. 4Sum](https://github.com/AlKiAl/leetcode_com/tree/main/18.%204Sum) -- return all unique the Quadruplets [nums[i], nums[j], nums[k], nums[l]] : nums[i] + nums[j] + nums[k] + nums[l] == target
--- 
- fix it `i` then j = i + 1; k = nums.size() - 1; --> (Sum3 < target) ? ++j : --k;
- [15. 3Sum](https://github.com/SkosMartren/leetcode_com/tree/main/15.%203Sum) --  return all unique the triplets [nums[i], nums[j], nums[k]] : nums[i] + nums[j] + nums[k] == target
- [16. 3Sum Closest](https://github.com/SkosMartren/leetcode_com/tree/main/16.%203Sum%20Closest) -- Return the sum of the three integers closest to target
--- 
- [count pairs with sum eqiv target](https://github.com/AlKiAl/leetcode_com/tree/main/count%20pairs%20with%20sum%20eqiv%20target) -- unordered_map<int, int> NumToCount. Найдите количество пар (i,j), что a[i] +  a[j]= k, при условии что (i,j) НЕ УДАЛЯЕТСЯ после учета их для ответа
- [1679. Max Number of K-Sum Pairs](https://github.com/SkosMartren/leetcode_com/tree/main/1679.%20Max%20Number%20of%20K-Sum%20Pairs) -- unordered_map<int, int> NumToCount. Найдите количество пар (i,j), что a[i] +  a[j]= k, при условии что (i,j) удаляется после учета их для ответа

---  

- вернуть {i,j} : num[i] + num[j] = target
  - [1. Two Sum](https://github.com/SkosMartren/leetcode_com/tree/main/1.%20Two%20Sum) -- unordered_map<int, int> NumToIdx + 1 passes
  - [167. Two Sum II - Input Array Is Sorted](https://github.com/SkosMartren/leetcode_com/tree/main/167.%20Two%20Sum%20II%20-%20Input%20Array%20Is%20Sorted) --  LeftPtr = 0; RightPtr = numbers.size() - 1; + 1 passes

</details>



<details>  
<summary>N number Maximum Product</summary>    

- Passes One + Greedy:  
  - [The Product of Two Extremes](https://github.com/SkosMartren/leetcode_com/tree/main/the%20product%20of%20two%20extremes)  
  - [628. Maximum Product of Three Numbers](https://github.com/SkosMartren/leetcode_com/tree/main/628.%20Maximum%20Product%20of%20Three%20Numbers)  
  - [1464. Maximum Product of Two Elements in an Array](https://github.com/SkosMartren/leetcode_com/tree/main/1464.%20Maximum%20Product%20of%20Two%20Elements%20in%20an%20Array)    

</details>

<details>  
<summary>Hash table</summary>    
  
если вы определяете пользовательскую хэш-функцию для структуры в C++, вы также должны переопределить operator==, 
чтобы обеспечить корректное поведение хэш-таблиц, таких как std::unordered_map или std::unordered_set.

Это связано с тем, что стандартные контейнеры, использующие хэширование, предполагают, что два объекта, 
имеющие одинаковые хэши, будут проверяться на равенство с помощью operator==. 
Если operator== не переопределен (или определен некорректно), поведение контейнера может стать неопределенным или неправильным.

- [Разрешение коллизий (neerc.ifmo.ru)](https://neerc.ifmo.ru/wiki/index.php?title=%D0%A0%D0%B0%D0%B7%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D0%B5_%D0%BA%D0%BE%D0%BB%D0%BB%D0%B8%D0%B7%D0%B8%D0%B9)    
- [356. Line Reflection](https://github.com/SkosMartren/leetcode_com/tree/main/356.%20Line%20Reflection) -- Перегрузка хеш-функции и operator==

</details>

<details>  
<summary>List</summary>

- [How to Solve Linked List Problems (Leetcode Discussion)](https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/)  
- Iterative:  
  - [2. Add Two Numbers](https://github.com/SkosMartren/leetcode_com/tree/main/2.%20Add%20Two%20Numbers)  
  - [19. Remove Nth Node From End of List](https://github.com/SkosMartren/leetcode_com/tree/main/19.%20Remove%20Nth%20Node%20From%20End%20of%20List)  
  - [206. Reverse Linked List](https://github.com/SkosMartren/leetcode_com/tree/main/206.%20Reverse%20Linked%20List)  

  ---------------------------------------------------------------------------------------------------  

- Recursive:  
  - [21. Merge Two Sorted Lists](https://github.com/SkosMartren/leetcode_com/tree/main/21.%20Merge%20Two%20Sorted%20Lists)  
  - [23. Merge k Sorted Lists](https://github.com/SkosMartren/leetcode_com/tree/main/23.%20Merge%20k%20Sorted%20Lists)  

  <details>  
  <summary>Cycle Detection (Floyd's Algorithm == Slow & Fast Pointer)</summary>    

  - [Floyd's Cycle-Finding Algorithm (GeeksforGeeks)](https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/)  
  - [234. Palindrome Linked List](https://github.com/SkosMartren/leetcode_com/tree/main/234.%20Palindrome%20Linked%20List) -- Reverse(FindRightMid(head))  
  - [141. Linked List Cycle](https://github.com/SkosMartren/leetcode_com/tree/main/141.%20Linked%20List%20Cycle)  

  </details>
</details>


<details>  
<summary>Math</summary>      

- [169. Majority Element](https://github.com/SkosMartren/leetcode_com/tree/main/169.%20Majority%20Element) -- The majority element is the element that appears more than ⌊n / 2⌋ times.  
- [204. Count Primes](https://github.com/SkosMartren/leetcode_com/tree/main/204.%20Count%20Primes)  
- [279. Perfect Squares](https://github.com/SkosMartren/leetcode_com/tree/main/279.%20Perfect%20Squares) -- or Dynamic programming  

---

- [150. Evaluate Reverse Polish Notation](https://github.com/SkosMartren/leetcode_com/tree/main/150.%20Evaluate%20Reverse%20Polish%20Notation) -- + Stack
- [227. Basic Calculator II](https://github.com/AlKiAl/leetcode_com/tree/main/227.%20Basic%20Calculator%20II)

---

- [7. Reverse Integer](https://github.com/SkosMartren/leetcode_com/tree/main/7.%20Reverse%20Integer)  
- [9. Palindrome Number](https://github.com/SkosMartren/leetcode_com/tree/main/9.%20Palindrome%20Number)  

---

- [12. Integer to Roman](https://github.com/SkosMartren/leetcode_com/tree/main/12.%20Integer%20to%20Roman)  
- [13. Roman to Integer](https://github.com/SkosMartren/leetcode_com/tree/main/13.%20Roman%20to%20Integer)  

</details>

<details>  
<summary>Operations on sets</summary>

  
  <details>  
  <summary>Arrays</summary>    

   - [349. Intersection of Two Arrays](https://github.com/SkosMartren/leetcode_com/tree/main/349.%20Intersection%20of%20Two%20Arrays) -- return unique val intersection  
   - [350. Intersection of Two Arrays II](https://github.com/SkosMartren/leetcode_com/tree/main/350.%20Intersection%20of%20Two%20Arrays%20II) -- return all val intersection  
   - [2215. Find the Difference of Two Arrays](https://github.com/SkosMartren/leetcode_com/tree/main/2215.%20Find%20the%20Difference%20of%20Two%20Arrays) -- return unique difference  
   - [Find elements in first sequence not in second (two pointers)](https://github.com/AlKiAl/leetcode_com/blob/main/Find%20elements%20in%20first%20sequence%20not%20in%20second%20two%20pointers/code.cpp) -- return difference  

  Для всех задач характерно утверждение:  
  - `unique` можно реализовать своими руками: [26. Remove Duplicates from Sorted Array](https://github.com/SkosMartren/leetcode_com/tree/main/26.%20Remove%20Duplicates%20from%20Sorted%20Array)  
  - `sort + comparison ptr` on greater/less/equiv  
  - В случае нежелания сортировки можно решить через Hash table  

  </details>        

  <details>  
  <summary>Intervals</summary>    

   - [986. Interval List Intersections](https://github.com/SkosMartren/leetcode_com/tree/main/986.%20Interval%20List%20Intersections)  
   - [56. Merge Intervals](https://github.com/SkosMartren/leetcode_com/tree/main/56.%20Merge%20Intervals)  
   - [57. Insert Interval](https://github.com/AlKiAl/leetcode_com/tree/main/57.%20Insert%20Interval)  
  - [435. Non-overlapping Intervals](https://github.com/SkosMartren/leetcode_com/tree/main/435.%20Non-overlapping%20Intervals) -- return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.  

    <details>  
    <summary>Сканирующая прямая</summary>    

    Не забывай при работе с интервалами про обработку случаев вида: `[[a,b], [b,c]]`.  
    - [252. Meeting Rooms](https://github.com/SkosMartren/leetcode_com/tree/main/252.%20Meeting%20Rooms) -- прямая проходит через все интервалы  
    - [253. Meeting Rooms II](https://github.com/SkosMartren/leetcode_com/tree/main/253.%20Meeting%20Rooms%20II) -- прямая проходит через минимальное количество интервалов  
    - [1450. Number of Students Doing Homework at a Given Time](https://github.com/AlKiAl/leetcode_com/tree/main/1450.%20Number%20of%20Students%20Doing%20Homework%20at%20a%20Given%20Time)  

    </details>                        

  </details>  
  
</details>


<details>  
<summary>Palindrome</summary>

- [5. Longest Palindromic Substring](https://github.com/SkosMartren/leetcode_com/tree/main/5.%20Longest%20Palindromic%20Substring)  
- [9. Palindrome Number](https://github.com/SkosMartren/leetcode_com/tree/main/9.%20Palindrome%20Number)  
- [125. Valid Palindrome](https://github.com/SkosMartren/leetcode_com/tree/main/125.%20Valid%20Palindrome) -- + isalnum + tolower  
- [234. Palindrome Linked List](https://github.com/SkosMartren/leetcode_com/tree/main/234.%20Palindrome%20Linked%20List)  
- [680. Valid Palindrome II](https://github.com/SkosMartren/leetcode_com/tree/main/680.%20Valid%20Palindrome%20II) -- "can be palindrome after deleting at most one character from it."  

</details>

<details>  
<summary>Parentheses</summary>

- [20. Valid Parentheses](https://github.com/SkosMartren/leetcode_com/tree/main/20.%20Valid%20Parentheses) -- stack + unordered_map : Open -> Closed  
- [22. Generate Parentheses](https://github.com/SkosMartren/leetcode_com/tree/main/22.%20Generate%20Parentheses) -- + string_stack + recursive. Open + Closed = 2N AND Open >= Closed AND Open <= N  
- [301. Remove Invalid Parentheses](https://github.com/SkosMartren/leetcode_com/tree/main/301.%20Remove%20Invalid%20Parentheses) -- + recursive  

</details>

<details>  
<summary>Passes one / two / ...</summary>

- [71. Simplify Path](https://github.com/SkosMartren/leetcode_com/tree/main/71.%20Simplify%20Path) -- stringstream. Transform this absolute path into its simplified canonical path Unix-style  
- [135. Candy](https://github.com/AlKiAl/leetcode_com/tree/main/135.%20Candy) -- обработка ratings[i−l]<...<ratings[i−1]<ratings[i]>...>ratings[i+r]  
- [238. Product of Array Except Self](https://github.com/SkosMartren/leetcode_com/tree/main/238.%20Product%20of%20Array%20Except%20Self) -- product_nums / nums[i]  

  <details>  
  <summary>Check Contains Duplicate with a condition ...</summary>      

  - [217. Contains Duplicate](https://github.com/SkosMartren/leetcode_com/tree/main/217.%20Contains%20Duplicate)  
  - [219. Contains Duplicate II](https://github.com/SkosMartren/leetcode_com/tree/main/219.%20Contains%20Duplicate%20II) -- nums[i] == nums[j] and abs(i - j) <= k  
  - [220. Contains Duplicate III](https://github.com/AlKiAl/leetcode_com/tree/main/220.%20Contains%20Duplicate%20III) -- abs(i - j) <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff  

  </details>

  <details>  
  <summary>(Increasing) Decreasing (Continuous) Sequence</summary>     
    
  - [300. Longest Increasing Subsequence](https://github.com/AlKiAl/leetcode_com/tree/main/300.%20Longest%20Increasing%20Subsequence) -- + b.s.
  
   <details>  
    <summary>Continuous</summary>      
     
  - [Increasing and decreasing sequence](https://github.com/SkosMartren/leetcode_com/tree/main/increasing%20and%20decreasing%20sequence)       
  - [674. Longest Continuous Increasing Subsequence](https://github.com/AlKiAl/leetcode_com/tree/main/674.%20Longest%20Continuous%20Increasing%20Subsequence)     
    - [896. Monotonic Array](https://github.com/SkosMartren/leetcode_com/tree/main/896.%20Monotonic%20Array)  
    ---------------------------------------------------------------------------------------------------  
    - [978. Longest Turbulent Subarray](https://github.com/AlKiAl/leetcode_com/tree/main/978.%20Longest%20Turbulent%20Subarray) -- subarray is turbulent if ... > arr[k - 1] < arr[k] > arr[k + 1] < ... 
    - [3105. Longest Strictly Increasing or Strictly Decreasing Subarray](https://github.com/AlKiAl/leetcode_com/blob/main/3105.%20Longest%20Strictly%20Increasing%20or%20Strictly%20Decreasing%20Subarray)  
  
    </details>
  
  
</details>

<details>  
<summary>Prefix</summary>      

- [14. Longest Common Prefix](https://github.com/AlKiAl/leetcode_com/tree/main/14.%20Longest%20Common%20Prefix) -- L.C.P. strings : sort + if(first[i]!=last[i]){break;} OR 2 passes: 1 - итерируемся по первой строке, 2 - итерируемся по остальным строкам массива помимо 1 строки + check (i == strs[j].size() || strs[j][i] != CurCh)
- [2657. Find the Prefix Common Array of Two Arrays](https://github.com/SkosMartren/leetcode_com/tree/main/2657.%20Find%20the%20Prefix%20Common%20Array%20of%20Two%20Arrays) -- vector<int> PrefixCommonArray(SIZE), CountValInPrefix(SIZE + 1); 

</details>



<details>  
<summary>Prefix sum (+ Subarray)</summary>    

- [Check subarrays on sort](https://github.com/AlKiAl/leetcode_com/tree/main/Check%20subarrays%20on%20sort)
- [53. Maximum Subarray](https://github.com/AlKiAl/leetcode_com/tree/main/53.%20Maximum%20Subarray) -- find the subarray with the largest sum 
- [238. Product of Array Except Self](https://github.com/SkosMartren/leetcode_com/tree/main/238.%20Product%20of%20Array%20Except%20Self)  -- product_nums / nums[i]
- [560. Subarray Sum Equals K](https://github.com/SkosMartren/leetcode_com/tree/main/560.%20Subarray%20Sum%20Equals%20K) -- + u_m : Prefix -> Count. Total number of subarrays whose sum = k  
- [325. Maximum Size Subarray Sum Equals k](https://github.com/AlKiAl/leetcode_com/tree/main/325.%20Maximum%20Size%20Subarray%20Sum%20Equals%20)
  
  ---------------------------------------------------------------------------------------------------  

  CurrentPrefixSumModK = (CurrentPrefixSumModK + num%k + k)%k where % --> divisible  

- [523. Continuous Subarray Sum](https://github.com/SkosMartren/leetcode_com/tree/main/523.%20Continuous%20Subarray%20Sum) -- $\exists$ subarray that has a sum divisible by k and length >= 2  
- [974. Subarray Sums Divisible by K](https://github.com/SkosMartren/leetcode_com/tree/main/974.%20Subarray%20Sums%20Divisible%20by%20K) -- Number of subarrays that have a sum divisible by k

</details>

<details>  
<summary>Random</summary>

  - [380. Insert Delete GetRandom O(1)](https://github.com/SkosMartren/leetcode_com/tree/main/380.%20Insert%20Delete%20GetRandom%20O(1)) -- next(values.begin(),  rand() % values.size()) + un_set values  
  - [470. Implement Rand10() Using Rand7()](https://github.com/SkosMartren/leetcode_com/tree/main/470.%20Implement%20Rand10()%20Using%20Rand7())
    
</details>

<details>  
<summary>Recursive</summary>      

- [341. Flatten Nested List Iterator](https://github.com/SkosMartren/leetcode_com/tree/main/341.%20Flatten%20Nested%20List%20Iterator) + queue    

</details>

<details>  
<summary>Sorted</summary>        

- [274. H-Index](https://github.com/SkosMartren/leetcode_com/tree/main/274.%20H-Index) -- Индекс хирша определяется как максимальное значение h, при котором данный исследователь опубликовал не менее h статей, каждая из которых цитировалась не менее h раз  
- [128. Longest Consecutive Sequence](https://github.com/AlKiAl/leetcode_com/tree/main/128.%20Longest%20Consecutive%20Sequence) -- Length of the longest consecutive elements seq. if seq. it will be sorted
- [215. Kth Largest Element in an Array](https://github.com/AlKiAl/leetcode_com/tree/main/215.%20Kth%20Largest%20Element%20in%20an%20Array) -- == nth_element  
- [977. Squares of a Sorted Array](https://github.com/SkosMartren/leetcode_com/tree/main/977.%20Squares%20of%20a%20Sorted%20Array) -- 3 ptr: LeftBorder = 0, RightBorder = nums.size() - 1, i = nums.size() - 1; ans[i] = nums[Border] * nums[Border]   
- [581. Shortest Unsorted Continuous Subarray](https://github.com/SkosMartren/leetcode_com/tree/main/581.%20Shortest%20Unsorted%20Continuous%20Subarray) -- Two pointer + passes two 
- [Check subarrays on sort](https://github.com/AlKiAl/leetcode_com/tree/main/Check%20subarrays%20on%20sort)
  
  <details>                
  <summary>Merge</summary>

  - [617. Merge Two Binary Trees](https://github.com/SkosMartren/leetcode_com/tree/main/617.%20Merge%20Two%20Binary%20Trees) -- PreOrder  
  - [56. Merge Intervals](https://github.com/SkosMartren/leetcode_com/tree/main/56.%20Merge%20Intervals) -- iter  
  - [88. Merge Sorted Array](https://github.com/SkosMartren/leetcode_com/tree/main/88.%20Merge%20Sorted%20Array) -- iter  

    ---------------------------------------------------------------------------------------------------          

  - [21. Merge Two Sorted Lists](https://github.com/SkosMartren/leetcode_com/tree/main/21.%20Merge%20Two%20Sorted%20Lists) -- rec  
  - [23. Merge k Sorted Lists](https://github.com/SkosMartren/leetcode_com/tree/main/23.%20Merge%20k%20Sorted%20Lists) -- rec                

  </details>
  <br>

  <details>  
  <summary>Counting</summary>   

  - [49. Group Anagrams](https://github.com/SkosMartren/leetcode_com/tree/main/49.%20Group%20Anagrams)  -- 2 passes: 1 - un_map : SortStrToAnagrams, 2 - make ans
  - [242. Valid Anagram](https://github.com/SkosMartren/leetcode_com/tree/main/242.%20Valid%20Anagram) + passes two    
  - [347. Top K Frequent Elements](https://github.com/SkosMartren/leetcode_com/tree/main/347.%20Top%20K%20Frequent%20Elements) + nth_element + Hash table              
  - [692. Top K Frequent Words](https://github.com/SkosMartren/leetcode_com/tree/main/692.%20Top%20K%20Frequent%20Words) + partial_sort + Hash table  

  </details>
</details>

<details>  
<summary>Sliding Window (Максимальная сумма подмассива длины k с по крайней мере m различных элементов) </summary>

- [2841. Maximum Sum of Almost Unique Subarray](https://github.com/AlKiAl/leetcode_com/tree/main/2841.%20Maximum%20Sum%20of%20Almost%20Unique%20Subarray) -- Максимальная сумма подмассива длины k с по крайней мере m различных элементов. un_map : num -> cnt


</details>


<details>  
<summary>Stack (deque) Monotonic</summary>      

- https://liuzhenglaichn.gitbook.io/algorithm/monotonic-stack
- [316. Remove Duplicate Letters](https://github.com/AlKiAl/leetcode_com/tree/main/316.%20Remove%20Duplicate%20Letters)
- https://leetcode.com/problems/remove-k-digits/description/
--- 
- [239. Sliding Window Maximum](https://github.com/SkosMartren/leetcode_com/tree/main/239.%20Sliding%20Window%20Maximum) -- Max val from s.w size = k. .  + S.W.Min + S.W.Max on random length subarray  
- [Longest Subarray s = {a[i], ..., a[j]} with max(s) - min(s) <= k](https://github.com/AlKiAl/leetcode_com/tree/main/Longest%20Subarray%20s%20%3D%20%7Ba%5Bi%5D%2C%20...%2C%20a%5Bj%5D%7D%20with%20max(s)%20-%20min(s)%20%3C%3D%20k)
  
</details>


<details>  
<summary>(Sub)string</summary>                

Если не известна кодировка, то вместо vector придеnся использовать unordered_map

- [157. Read N Characters Given Read4](https://github.com/SkosMartren/leetcode_com/tree/main/157.%20Read%20N%20Characters%20Given%20Read4)  
- [205. Isomorphic Strings](https://github.com/AlKiAl/leetcode_com/tree/main/205.%20Isomorphic%20Strings)  
- [459. Repeated Substring Pattern](https://github.com/SkosMartren/leetcode_com/tree/main/459.%20Repeated%20Substring%20Pattern) -- check S == pattern + ... + pattern : {s.substr(1, size-1) + s.substr(0, size-1)}.find(s) != string::npos; 
- [387. First Unique Character in a String](https://github.com/SkosMartren/leetcode_com/tree/main/387.%20First%20Unique%20Character%20in%20a%20String)  -- 2 passes: 1 - sort count, 2 - passes to str and check char_to_count[s[i] - 'a'] == 1
- [392. Is Subsequence](https://github.com/SkosMartren/leetcode_com/tree/main/392.%20Is%20Subsequence) -- T.P. . no more than min(|s1|, |s2|) editorial distance  
- [771. Jewels and Stones](https://github.com/AlKiAl/leetcode_com/tree/main/771.%20Jewels%20and%20Stones) -- подсчитать количество символов в `stones`, которые встречаются в `jewels`

  <details>  
  <summary>Reverse</summary>    

  - [344. Reverse String](https://github.com/SkosMartren/leetcode_com/tree/main/344.%20Reverse%20String) -- T.P.  
  - [151. Reverse Words in a String](https://github.com/AlKiAl/leetcode_com/tree/main/151.%20Reverse%20Words%20in%20a%20String) -- cleanSpaces: separator must be one space. The separator can be more than one space by condition  
  - [186. Reverse Words in a String II](https://github.com/AlKiAl/leetcode_com/tree/main/186.%20Reverse%20Words%20in%20a%20String%20II) -- without cleanSpaces. The separator can be more than one space by condition  
  - [557. Reverse Words in a String III](https://github.com/SkosMartren/leetcode_com/tree/main/557.%20Reverse%20Words%20in%20a%20String%20III) -- T.P. . the separator is by condition one space  

  </details>           

  <details>  
  <summary>Math</summary>    

  - [43. Multiply Strings](https://github.com/SkosMartren/leetcode_com/tree/main/43.%20Multiply%20Strings)  
  - [415. Add Strings](https://github.com/SkosMartren/leetcode_com/tree/main/415.%20Add%20Strings)  

  </details>        

  <details>  
  <summary>Anagram</summary>    

  - [49. Group Anagrams](https://github.com/SkosMartren/leetcode_com/tree/main/49.%20Group%20Anagrams)  -- 2 passes: 1 - un_map : SortStrToAnagrams, 2 - make ans
  - [76. Minimum Window Substring](https://github.com/SkosMartren/leetcode_com/tree/main/76.%20Minimum%20Window%20Substring) -- Check exist |Anagram| <= |Substring|. S.W.  
  - [242. Valid Anagram](https://github.com/SkosMartren/leetcode_com/tree/main/242.%20Valid%20Anagram) + passes two  
  - [438. Find All Anagrams in a String](https://github.com/SkosMartren/leetcode_com/tree/main/438.%20Find%20All%20Anagrams%20in%20a%20String) -- Find all |Anagram| == |Substring|. S.W.  
  - [567. Permutation in String](https://github.com/SkosMartren/leetcode_com/tree/main/567.%20Permutation%20in%20String) -- Check exist |Anagram| == |Substring|. S.W.  
  - [Anagram Pair Count](https://github.com/AlKiAl/leetcode_com/tree/main/Anagram%20Pair%20Count) -- unordered_map<vector<int>, int, VectorHash> freqToCount + sort counting для freq
  
  </details>        

  <details>  
  <summary>Substring</summary>    
    
  - [28. Find the Index of the First Occurrence in a String](https://github.com/SkosMartren/leetcode_com/tree/main/28.%20Find%20the%20Index%20of%20the%20First%20Occurrence%20in%20a%20String) -- Find index of start substring in string
  - [Longest Subarray With no more K Char Pairs](https://github.com/AlKiAl/leetcode_com/tree/main/Longest%20Subarray%20With%20no%20more%20K%20Char%20Pairs) -- 2 ptr
    
    ---
    
  - [395. Longest Substring with At Least K Repeating Characters](https://github.com/AlKiAl/leetcode_com/tree/main/395.%20Longest%20Substring%20with%20At%20Least%20K%20Repeating%20Characters) -- Самая длинная подстрока, содержащая не менее K повторяющихся символов. external loop: int targetUniq = 1; targetUniq <= maxUniqueCharacters; ++targetUniq; internal loop: int left = 0, right = 0; right < str.size();
  - vector<bool> CharToExistingInSlidingWindow + 2 ptr + analysis RightPtr - LeftPtr + 1
  - [3. Longest Substring Without Repeating Characters](https://github.com/SkosMartren/leetcode_com/tree/main/3.%20Longest%20Substring%20Without%20Repeating%20Characters) -- S.W. . Longest substring with unique characters  
  - [2743. Count Substrings Without Repeating Character](https://github.com/AlKiAl/leetcode_com/tree/main/2743.%20Count%20Substrings%20Without%20Repeating%20Character) -- S.W. . Вернуть количество возможных подстрок, состоящих из уникальных элементов  

    ---  

  - [424. Longest Repeating Character Replacement](https://github.com/AlKiAl/leetcode_com/tree/main/424.%20Longest%20Repeating%20Character%20Replacement) -- Самая длинная подстрока с одинаковыми символами не более чем после k flip. S.W. + CharToCountInWindow + MaxCountRepeatSymb.  
  - [1446. Consecutive Characters](https://github.com/SkosMartren/leetcode_com/tree/main/1446.%20Consecutive%20Characters) -- T.P. . Find max substring with same symbols  

    ---  

  - [Remove All Occurrences of a Substring by pattern](https://github.com/AlKiAl/leetcode_com/tree/main/Remove%20All%20Occurrences%20of%20a%20Substring%20by%20pattern) -- Удаляются все, помимо образовавшихся после удаления  
  - [1910. Remove All Occurrences of a Substring](https://github.com/AlKiAl/leetcode_com/tree/main/1910.%20Remove%20All%20Occurrences%20of%20a%20Substring) -- Удаляются все, в том числе образовавшиеся после удаления  

    ---  

  Return the length of the longest substring of `s` that contains at most `k` distinct characters:  
  - [159. Longest Substring with At Most Two Distinct Characters](https://github.com/SkosMartren/leetcode_com/tree/main/159.%20Longest%20Substring%20with%20At%20Most%20Two%20Distinct%20Characters) <-- [340. Longest Substring with At Most K Distinct Characters](https://github.com/SkosMartren/leetcode_com/tree/main/340.%20Longest%20Substring%20with%20At%20Most%20K%20Distinct%20Characters) -- S.W.  

  </details>                            
</details>


<details>  
<summary>Tree</summary>
 
  <details>  
  <summary>LCA</summary>  

  - [235. Lowest Common Ancestor of a Binary Search Tree](https://github.com/SkosMartren/leetcode_com/tree/main/235.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Search%20Tree) -- Iter  
  - [236. Lowest Common Ancestor of a Binary Tree](https://github.com/SkosMartren/leetcode_com/tree/main/236.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree) -- PreOrder + PostOrder. Find LCA  
  - [1644. Lowest Common Ancestor of a Binary Tree II](https://github.com/AlKiAl/leetcode_com/blob/main/1644.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20II) -- Find LCA + Check exist node  
  ---------------------------------------------------------------------------------------------------  
  - [160. Intersection of Two Linked Lists](https://github.com/SkosMartren/leetcode_com/tree/main/160.%20Intersection%20of%20Two%20Linked%20Lists) ==  [1650. Lowest Common Ancestor of a Binary Tree III](https://github.com/SkosMartren/leetcode_com/tree/main/1650.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20III) -- Iter. Find LCA if exist Parent  

  </details>  
  <br>  

  <details>  
  <summary>BST</summary>  

  - [98. Validate Binary Search Tree](https://github.com/SkosMartren/leetcode_com/tree/main/98.%20Validate%20Binary%20Search%20Tree) -- InOrder  
  - [449. Serialize and Deserialize BST](https://github.com/SkosMartren/leetcode_com/tree/main/449.%20Serialize%20and%20Deserialize%20BST)  
  - [700. Search in a Binary Search Tree](https://github.com/SkosMartren/leetcode_com/tree/main/700.%20Search%20in%20a%20Binary%20Search%20Tree) -- Iter  
  - [938. Range Sum of BST](https://github.com/AlKiAl/leetcode_com/tree/main/938.%20Range%20Sum%20of%20BST) -- Sum of values of all nodes in range [low, high]  
  - [1008. Construct Binary Search Tree from Preorder Traversal](https://github.com/SkosMartren/leetcode_com/tree/main/1008.%20Construct%20Binary%20Search%20Tree%20from%20Preorder%20Traversal)  

  </details>  
  <br>  

  <details>  
  <summary>BT</summary>  

  - [105. Construct Binary Tree from Preorder and Inorder Traversal](https://github.com/SkosMartren/leetcode_com/tree/main/105.%20Construct%20Binary%20Tree%20from%20Preorder%20and%20Inorder%20Traversal) -- Includes a helpful diagram  
  - [124. Binary Tree Maximum Path Sum](https://github.com/SkosMartren/leetcode_com/tree/main/124.%20Binary%20Tree%20Maximum%20Path%20Sum) -- PostOrder  
  - [404. Sum of Left Leaves](https://github.com/SkosMartren/leetcode_com/tree/main/404.%20Sum%20of%20Left%20Leaves) -- AnyOrder  
  - [652. Find Duplicate Subtrees](https://github.com/AlKiAl/leetcode_com/tree/main/652.%20Find%20Duplicate%20Subtrees) -- PostOrder + u_m: str(Subtree) -> Count  
  ---------------------------------------------------------------------------------------------------  
  - [100. Same Tree](https://github.com/SkosMartren/leetcode_com/tree/main/100.%20Same%20Tree) -- PreOrder  
  - [101. Symmetric Tree](https://github.com/SkosMartren/leetcode_com/tree/main/101.%20Symmetric%20Tree) -- PreOrder  
  ---------------------------------------------------------------------------------------------------  
  - [104. Maximum Depth of Binary Tree](https://github.com/SkosMartren/leetcode_com/tree/main/104.%20Maximum%20Depth%20of%20Binary%20Tree) -- AnyOrder  
  - [102. Binary Tree Level Order Traversal](https://github.com/AlKiAl/leetcode_com/tree/main/102.%20Binary%20Tree%20Level%20Order%20Traversal)  --> [103. Binary Tree Zigzag Level Order Traversal](https://github.com/SkosMartren/leetcode_com/tree/main/103.%20Binary%20Tree%20Zigzag%20Level%20Order%20Traversal) -- PreOrder  
  - [199. Binary Tree Right Side View](https://github.com/SkosMartren/leetcode_com/tree/main/199.%20Binary%20Tree%20Right%20Side%20View) -- PreOrder  
  - [110. Balanced Binary Tree](https://github.com/SkosMartren/leetcode_com/tree/main/110.%20Balanced%20Binary%20Tree) -- PostOrder
  --- 
  - [222. Count Complete Tree Nodes](https://github.com/AlKiAl/leetcode_com/tree/main/222.%20Count%20Complete%20Tree%20Nodes) -- PostOrder. Cnt child for each node
  - [The maximum pair of matching subtrees consisting of small Latin letters](https://github.com/AlKiAl/leetcode_com/tree/main/The%20maximum%20pair%20of%20matching%20subtrees%20consisting%20of%20small%20Latin%20letters)
  
  </details>
<br>   

<details>
<summary>Diameter and centre</summary>

- [543. Diameter of Binary Tree](https://github.com/SkosMartren/leetcode_com/tree/main/543.%20Diameter%20of%20Binary%20Tree) -- PostOrder
- [310. Minimum Height Trees](https://github.com/AlKiAl/leetcode_com/tree/main/310.%20Minimum%20Height%20Trees) -- find the center of the graph. DFS + control cnt leafs

Диаметр дерева (англ. diameter of a tree) — максимальная длина (в рёбрах) кратчайшего пути в дереве между любыми двумя вершинами.

Центр (или центр Жордана) графа — это множество всех вершин с минимальным эксцентриситетом. То есть множество всех вершин A, для которой максимальное расстояние d(A,B) до других вершин B минимально. Эквивалентно, это множество вершин с эксцентриситетом, равным радиусу графа.

Степень (валентность) вершины графа — количество рёбер графа G, инцидентных вершине x. При подсчёте степени ребро-петля учитывается дважды.

Вершина степени 1 называется концевой (англ. end vertex), висячей (англ. pendant vertex) или листом графа (англ. leaf vertex).

</details>
  
</details>


   
<details>  
  
<summary>Two pointer</summary>        

- [11. Container With Most Water](https://github.com/SkosMartren/leetcode_com/tree/main/11.%20Container%20With%20Most%20Water) + Greedy  
- [42. Trapping Rain Water](https://github.com/SkosMartren/leetcode_com/tree/main/42.%20Trapping%20Rain%20Water)  
- [209. Minimum Size Subarray Sum](https://github.com/AlKiAl/leetcode_com/tree/main/209.%20Minimum%20Size%20Subarray%20Sum) -- min(j-i+1) : sum {a[i], ..., a[j]} >= k.  external loop: Right < nums.size(); ++Right. internal loop: SumBuff >= target; ++Left
- [977. Squares of a Sorted Array](https://github.com/SkosMartren/leetcode_com/tree/main/977.%20Squares%20of%20a%20Sorted%20Array) -- 3 ptr: LeftBorder = 0, RightBorder = nums.size() - 1, i = nums.size() - 1; ans[i] = nums[Border] * nums[Border] 
- [Find K Closest Elements with exist arr\[i\]=x](https://github.com/AlKiAl/leetcode_com/tree/main/Find%20K%20Closest%20Elements%20with%20exist%20arr%5Bi%5D%3Dx%20) -- if (L < 0 || (R < a.size() && a[R]  - a[Idx] <= a[Idx] - a[L]) ) { R++; } else { L--; } 
  <details>  
  <summary>(Re)move</summary>    
    
  - [Maximize Pair k * a[i] <= a[j] Removals](https://github.com/AlKiAl/leetcode_com/tree/main/Maximize%20Pair%20k%20*%20a%5Bi%5D%20%3C=%20a%5Bj%5D%20Removals)    
  - [27. Remove Element](https://github.com/SkosMartren/leetcode_com/tree/main/27.%20Remove%20Element)  --> [283. Move Zeroes](https://github.com/SkosMartren/leetcode_com/tree/main/283.%20Move%20Zeroes) -- move any val to prefix/postfix. 1 passes + if(nums[i] != val){ swap(nums[Idx++], nums[i]);  }  
  - external loop: int l = 0; l < N.size() internal loop: ;r < N.size() && cur == N[r]; ++r    
    - [26. Remove Duplicates from Sorted Array](https://github.com/SkosMartren/leetcode_com/tree/main/26.%20Remove%20Duplicates%20from%20Sorted%20Array) -- each unique element appears only once  
    - [80. Remove Duplicates from Sorted Array II](https://github.com/SkosMartren/leetcode_com/tree/main/80.%20Remove%20Duplicates%20from%20Sorted%20Array%20II) -- each unique element appears at most twice  
    



  </details>         
</details>

<details>  
<summary>Wandering through the plane</summary>    

- [657. Robot Return to Origin](https://github.com/SkosMartren/leetcode_com/tree/main/657.%20Robot%20Return%20to%20Origin) -- passes one + check end == start (X == 0 && Y == 0)
- [1041. Robot Bounded In Circle](https://github.com/SkosMartren/leetcode_com/tree/main/1041.%20Robot%20Bounded%20In%20Circle) -- passes one + check end (X == 0 && Y == 0) || SideWorld != north  
- [1496. Path Crossing](https://github.com/SkosMartren/leetcode_com/tree/main/1496.%20Path%20Crossing) -- check path crosses itself at any point  + Перегрузка хеш-функции и operator== : un_set<Pair, PairHash> Visit

</details>

<details>  
<summary>Yandex</summary>    

- Дана доска размера N на N, на ней конь, некоторые клетки запрещены, на них конь не наступает, надо поменить все клетки, достижимые конем  

  <details>  
  <summary>(Sub)string</summary>    

  - [Remove All Occurrences of a Substring by pattern](https://github.com/SkosMartren/leetcode_com/tree/main/Remove%20All%20Occurrences%20of%20a%20Substring%20by%20pattern)  
  - [157. Read N Characters Given Read4](https://github.com/SkosMartren/leetcode_com/tree/main/157.%20Read%20N%20Characters%20Given%20Read4)  
  - [Replace char on string](https://github.com/SkosMartren/leetcode_com/tree/main/replace%20char%20on%20string)
  - [the distance between two characters](https://github.com/AlKiAl/leetcode_com/tree/main/the%20distance%20between%20two%20characters) -- экстремальное значение расстояний между двумя символами

  </details>

  <details>  
  <summary>Array</summary>    

  - [Find elements in first sequence not in second (two pointers)](https://github.com/SkosMartren/leetcode_com/tree/main/Find%20elements%20in%20first%20sequence%20not%20in%20second%20two%20pointers) -- return all val difference  
  - [960. First Unique Number in Data Stream II](https://github.com/SkosMartren/leetcode_com/tree/main/960%20%C2%B7%20First%20Unique%20Number%20in%20Data%20Stream%20II) -- List + mapping (такая связка используется для быстрого удаления из середины по итератору). Вернуть первый уникальный элемент из префикса чисел
  - [Count subarray equiv B in A](https://github.com/AlKiAl/leetcode_com/tree/main/Count%20subarray%20equiv%20B%20in%20A)
  - [Find K Closest Elements with exist x](https://github.com/AlKiAl/leetcode_com/tree/main/Find%20K%20Closest%20Elements%20with%20exist%20arr%5Bi%5D=x%20) -- 2 ptr: L = index - 1 R = index + 1
  - 
  </details>    
</details>

<details>  
<summary>2D Matrix</summary>    
  
- [463. Island Perimeter](https://github.com/SkosMartren/leetcode_com/tree/main/463.%20Island%20Perimeter) -- check the exit abroad + grid[y+dy][x+dx] == 0 
- [36. Valid Sudoku](https://github.com/AlKiAl/leetcode_com/tree/main/36.%20Valid%20Sudoku)  -- unordered_set<char> rows[9]; cols[9]; boxes[9]; boxIndex = (r / 3) * 3 + (c / 3);
- [48. Rotate Image](https://github.com/SkosMartren/leetcode_com/tree/main/48.%20Rotate%20Image) -- rotate the matrix by 90 degrees (clockwise) == сначала по горизонтали, затем по главной диагонали
- [74. Search a 2D Matrix](https://github.com/SkosMartren/leetcode_com/tree/main/74.%20Search%20a%202D%20Matrix) -- Binary search + (i,j) <--> j * CountColumn + i : j == line, i == column 
- [85. Maximal Rectangle](https://github.com/AlKiAl/leetcode_com/tree/main/85.%20Maximal%20Rectangle) -- макс. площ. прямоугольника из 1  
- [1329. Sort the Matrix Diagonally](https://github.com/AlKiAl/leetcode_com/tree/main/1329.%20Sort%20the%20Matrix%20Diagonally)  --  unordered_map<int, priority_queue<int, vector<int>, greater<int>>> IdxDiagMatrixToVal; : IdxDiag == i - j
- [1572. Matrix Diagonal Sum](https://github.com/SkosMartren/leetcode_com/tree/main/1572.%20Matrix%20Diagonal%20Sum)  

</details>

</details>


______

https://yandex.ru/jobs/pages/dev_interview

У Федора Меньшикова разбор отсут-т!

Архив видео Федора Меньшикова: https://docs.google.com/spreadsheets/d/1w5JqsXFfNTS7NUT7ujKrt8NvhJiw52S6jfvoo2X_fo8/edit?pli=1#gid=0

Yandex Interview Kit: https://docs.google.com/spreadsheets/d/1vgoyVzOqueURT7jNXuoEec5dQnIdtUCEqVPX1x0Vx6A/edit?pli=1#gid=0

https://leetcode-company-tagged.vercel.app/yandex

https://leetcode.com/problem-list/oy4y273c/

Архив условий и решений: https://github.com/doocs/leetcode/tree/main/solution

чтобы зарегестрироваться в https://www.lintcode.com/ -- можно использовать viber (при регистрации по номеру телефона туда приходит верифицированный код)! На этом сайте есть возможность сдать закрытые заадчи с leetcode

Leet Xt v0.3.6
_________




<details>  
<summary>  Topics </summary>

<details>  
<summary> Binary search </summary>
    https://github.com/SkosMartren/leetcode_com/tree/main/4.%20Median%20of%20Two%20Sorted%20Arrays       
    https://github.com/SkosMartren/leetcode_com/tree/main/658.%20Find%20K%20Closest%20Elements
    https://github.com/SkosMartren/leetcode_com/tree/main/704.%20Binary%20Search
  <br>
        <details> 
        <summary> Bitonic sequence </summary>
           https://www.geeksforgeeks.org/bitonic-sort/
           https://en.wikipedia.org/wiki/Bitonic_sorter
           https://neerc.ifmo.ru/wiki/index.php?title=%D0%A1%D0%B5%D1%82%D1%8C_%D0%91%D0%B5%D1%82%D1%87%D0%B5%D1%80%D0%B0
           https://github.com/SkosMartren/leetcode_com/tree/main/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array
           https://github.com/SkosMartren/leetcode_com/tree/main/33.%20Search%20in%20Rotated%20Sorted%20Array
           https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
           https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
        </details>
</details>

<details>  
<summary> Binary sequance </summary>
        https://github.com/AlKiAl/leetcode_com/tree/main/485.%20Max%20Consecutive%20Ones
        https://github.com/AlKiAl/leetcode_com/tree/main/487.%20Max%20Consecutive%20Ones%20II -- T.P. . Flip at most 2 zero
        https://github.com/SkosMartren/leetcode_com/tree/main/1004.%20Max%20Consecutive%20Ones%20III  -- T.P. . Flip at most k zero
        https://github.com/SkosMartren/leetcode_com/tree/main/1493.%20Longest%20Subarray%20of%201's%20After%20Deleting%20One%20Element -- T.P. . Upd 1 zero <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/849.%20Maximize%20Distance%20to%20Closest%20Person + Greedy <br>  
          https://github.com/SkosMartren/leetcode_com/tree/main/605.%20Can%20Place%20Flowers -- can be planted in without violating the no-adjacent-flowers rule  <br> 
</details>
        
<details>  
<summary> Bitwise operator </summary>
    https://github.com/SkosMartren/leetcode_com/tree/main/136.%20Single%20Number
    https://github.com/SkosMartren/leetcode_com/tree/main/137.%20Single%20Number%20II    
    https://github.com/SkosMartren/leetcode_com/tree/main/268.%20Missing%20Number
</details>

<details>  
<summary> data compression </summary>
  https://github.com/SkosMartren/leetcode_com/tree/main/228.%20Summary%20Ranges
          <details>  
        <summary> RLE </summary>    
            [Кодирование длин серий](https://ru.wikipedia.org/wiki/%D0%9A%D0%BE%D0%B4%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5_%D0%B4%D0%BB%D0%B8%D0%BD_%D1%81%D0%B5%D1%80%D0%B8%D0%B9)
            https://github.com/AlKiAl/leetcode_com/tree/main/443.%20String%20Compression
            https://github.com/AlKiAl/leetcode_com/tree/main/1868.%20Product%20of%20Two%20Run-Length%20Encoded%20Arrays
        </details>       
</details>

<details>  
<summary> Design </summary>        
    https://github.com/SkosMartren/leetcode_com/tree/main/2241.%20Design%20an%20ATM%20Machine  <br>
        <details>  
        <summary> Counter </summary>
            события, находящиеся в промежутке ]timestamp - n, timestamp[. Решение с использованием queue: <br>
            https://github.com/SkosMartren/leetcode_com/tree/main/362.%20Design%20Hit%20Counter -- (timestamp - 300, timestamp]      <br>
            https://github.com/SkosMartren/leetcode_com/tree/main/933.%20Number%20of%20Recent%20Calls -- [timestamp - 3000, timestamp]  
        </details>        
        <details>  
        <summary> Data Strucut </summary>    
            Разница между 155. Min Stack и Max Stack в том, что в 716. Max Stack необходимо реализовать удаление экстремума из очереди    <br>
            https://github.com/SkosMartren/leetcode_com/tree/main/155.%20Min%20Stack -- stack + struct Pair { int Val; int Min;}; <br>
            https://github.com/SkosMartren/leetcode_com/tree/main/232.%20Implement%20Queue%20using%20Stacks -- stack + stack <br>
            https://github.com/SkosMartren/leetcode_com/tree/main/380.%20Insert%20Delete%20GetRandom%20O(1) -- использование хеш-таблицы    
                <details>  
                <summary> List + mapping (такая связка используется для быстрого удаления из середины по итератору) </summary>    
                    https://github.com/SkosMartren/leetcode_com/tree/main/716.%20Max%20Stack -- order_mapping : key -> vector list::iterator <br>
                    https://github.com/SkosMartren/leetcode_com/tree/main/146.%20LRU%20Cache -- удаляются наименее использованные элементы. unorder_mapping : key -> list::iterator + unorder_mapping : key -> val <br>
                    https://github.com/SkosMartren/leetcode_com/tree/main/960%20%C2%B7%20First%20Unique%20Number%20in%20Data%20Stream%20II -- unorder_mapping                       
                </details>
        </details>
</details>


<details>  
<summary> Dynamic programming </summary>    
    https://github.com/SkosMartren/leetcode_com/tree/main/53.%20Maximum%20Subarray -- find the subarray with the largest sum   <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/279.%20Perfect%20Squares -- return the least number of numbers degree k that sum to n.    <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/1143.%20Longest%20Common%20Subsequence <br> 
    --------------------------------------------------------------------------------------------------- <br> 
        https://github.com/SkosMartren/leetcode_com/tree/main/70.%20Climbing%20Stairs <br> 
        https://github.com/SkosMartren/leetcode_com/tree/main/509.%20Fibonacci%20Number   <br>       
</details>

<details>  
<summary> Edit distance </summary>
        https://en.wikipedia.org/wiki/Edit_distance <br>
        https://github.com/AlKiAl/leetcode_com/tree/main/72.%20Edit%20Distance -- D.P.     
        https://github.com/AlKiAl/leetcode_com/tree/main/161.%20One%20Edit%20Distance -- T.P.   
        https://github.com/SkosMartren/leetcode_com/tree/main/392.%20Is%20Subsequence -- T.P.   . no more than min(|s1|,|s2|) editorial distance <br>
        https://github.com/AlKiAl/leetcode_com/tree/main/680.%20Valid%20Palindrome%20II -- T.P. . no more than one editorial distance      
        https://github.com/SkosMartren/leetcode_com/tree/main/1143.%20Longest%20Common%20Subsequence -- D.P.
</details>


<details>  
<summary> Graph traversal: DFS / BFS / DSU </summary>    
    https://github.com/SkosMartren/leetcode_com/tree/main/200.%20Number%20of%20Islands   <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/332.%20Reconstruct%20Itinerary -- (DFS on UnorderedHash) реконструировать весь маршрут  <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/1436.%20Destination%20City -- (DFS on UnorderedHash) найти конечную точку маршрута    
</details>


<details>  
<summary> Greedy </summary>    
    https://github.com/SkosMartren/leetcode_com/tree/main/135.%20Candy <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/763.%20Partition%20Labels -- + Two ptr + CharToLastIdx: each letter appears in at most one partition  <br>
    --------------------------------------------------------------------------------------------------- <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/121.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock -- one of the best deals <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/122.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20II  -- maximum profit you can achieve <br>
    https://github.com/AlKiAl/leetcode_com/tree/main/123.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III -- maximum profit you can achieve complete at most two transactions
</details>

<details>  
<summary> NSum </summary>    
    https://github.com/AlKiAl/leetcode_com/tree/main/18.%204Sum <br>
  ___
        https://github.com/SkosMartren/leetcode_com/tree/main/15.%203Sum  <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/16.%203Sum%20Closest  <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/1.%20Two%20Sum  <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/167.%20Two%20Sum%20II%20-%20Input%20Array%20Is%20Sorted <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/350.%20Intersection%20of%20Two%20Arrays%20II -- тут есть конспект об устройстве и ссылка на лекцию / Доказательство невыгодности использования unordered_map в некоторых задачах <br>
</details>

<details>  
<summary> N number Maximum Product </summary>    
    + passes one + Greedy :  <br> 
    https://github.com/SkosMartren/leetcode_com/tree/main/the%20product%20of%20two%20extremes    
    https://github.com/SkosMartren/leetcode_com/tree/main/628.%20Maximum%20Product%20of%20Three%20Numbers  
    https://github.com/SkosMartren/leetcode_com/tree/main/1464.%20Maximum%20Product%20of%20Two%20Elements%20in%20an%20Array    
</details>

<details>  
<summary> Hash table </summary>    
    https://neerc.ifmo.ru/wiki/index.php?title=%D0%A0%D0%B0%D0%B7%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D0%B5_%D0%BA%D0%BE%D0%BB%D0%BB%D0%B8%D0%B7%D0%B8%D0%B9 -- Разрешение коллизий  <br>
    ---------------------------------------------------------------------------------------------------  <br>
    использование хеш-таблицы  <br>  
    https://github.com/SkosMartren/leetcode_com/tree/main/1679.%20Max%20Number%20of%20K-Sum%20Pairs <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/380.%20Insert%20Delete%20GetRandom%20O(1) <br>
    ---------------------------------------------------------------------------------------------------     <br>
    перегрузка хеш-функции и operator==  <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/356.%20Line%20Reflection     
</details>


<details>  
<summary> List </summary>
    https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/ <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/2.%20Add%20Two%20Numbers  -- iter <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/19.%20Remove%20Nth%20Node%20From%20End%20of%20List -- iter <br> 
    https://github.com/SkosMartren/leetcode_com/tree/main/206.%20Reverse%20Linked%20List -- iter <br>
    ---------------------------------------------------------------------------------------------------          
    https://github.com/SkosMartren/leetcode_com/tree/main/21.%20Merge%20Two%20Sorted%20Lists -- rec
    https://github.com/SkosMartren/leetcode_com/tree/main/23.%20Merge%20k%20Sorted%20Lists -- rec    
        <br>
        <details>  
        <summary> cycle Floyd's == slow & fast ptr</summary>    
            https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/ <br>
            https://github.com/SkosMartren/leetcode_com/tree/main/234.%20Palindrome%20Linked%20List  -- Reverse(FindRightMid(head))  <br>
            https://github.com/SkosMartren/leetcode_com/tree/main/141.%20Linked%20List%20Cycle
        </details>
</details>



<details>  
<summary> math </summary>      
        https://github.com/SkosMartren/leetcode_com/tree/main/150.%20Evaluate%20Reverse%20Polish%20Notation -- + Stack      
        https://github.com/SkosMartren/leetcode_com/tree/main/169.%20Majority%20Element -- The majority element is the element that appears more than ⌊n / 2⌋ times.  <br> 
        https://github.com/SkosMartren/leetcode_com/tree/main/204.%20Count%20Primes  
        https://github.com/SkosMartren/leetcode_com/tree/main/205.%20Isomorphic%20Strings
        https://github.com/SkosMartren/leetcode_com/tree/main/279.%20Perfect%20Squares -- or Dynamic programming               
        https://github.com/SkosMartren/leetcode_com/tree/main/463.%20Island%20Perimeter
        https://github.com/SkosMartren/leetcode_com/tree/main/470.%20Implement%20Rand10()%20Using%20Rand7()  <br> 
    ---------------------------------------------------------------------------------------------------
        https://github.com/SkosMartren/leetcode_com/tree/main/70.%20Climbing%20Stairs
        https://github.com/SkosMartren/leetcode_com/tree/main/509.%20Fibonacci%20Number   <br> 
    --------------------------------------------------------------------------------------------------- <br> 
        https://github.com/SkosMartren/leetcode_com/tree/main/7.%20Reverse%20Integer <br> 
        https://github.com/SkosMartren/leetcode_com/tree/main/9.%20Palindrome%20Number  <br>
    ---------------------------------------------------------------------------------------------------    
        https://github.com/SkosMartren/leetcode_com/tree/main/12.%20Integer%20to%20Roman
        https://github.com/SkosMartren/leetcode_com/tree/main/13.%20Roman%20to%20Integer <br>        
</details>


<details>  
<summary> operations on sets </summary>
                <details>  
                <summary> Arrays </summary>
                        https://github.com/SkosMartren/leetcode_com/tree/main/349.%20Intersection%20of%20Two%20Arrays -- return unique val intersection 
                        https://github.com/SkosMartren/leetcode_com/tree/main/350.%20Intersection%20of%20Two%20Arrays%20II -- return all val intersection  
                        https://github.com/SkosMartren/leetcode_com/tree/main/2215.%20Find%20the%20Difference%20of%20Two%20Arrays -- return unique difference <br>
                        https://github.com/AlKiAl/leetcode_com/blob/main/Find%20elements%20in%20first%20sequence%20not%20in%20second%20two%20pointers/code.cpp  -- return difference <br>
                        Для всех задач характерно утверждение:  <br>
                        - unique можно реализовать своими руками: 26  Remove Duplicates from Sorted Array  <br>
                        - sort + comparison ptr on greater less equiv  <br>
                        - в случае нежелания сортировки можно решить через Hash table <br>              
                </details>        
                <details>  
                <summary> Intervals </summary>
                        https://github.com/SkosMartren/leetcode_com/tree/main/986.%20Interval%20List%20Intersections <br>
                        https://github.com/SkosMartren/leetcode_com/tree/main/56.%20Merge%20Intervals   <br>
                        https://github.com/AlKiAl/leetcode_com/tree/main/57.%20Insert%20Interval <br>
                        https://github.com/SkosMartren/leetcode_com/tree/main/435.%20Non-overlapping%20Intervals  -- return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
                        <details>  
                        <summary> Сканирующая прямая </summary>
                            не забывай при работе с интервалами про обработку случаев вида: [[a,b], [b,c]]
                            https://github.com/SkosMartren/leetcode_com/tree/main/252.%20Meeting%20Rooms -- прямая проходит через все интервалы <br>
                            https://github.com/SkosMartren/leetcode_com/tree/main/253.%20Meeting%20Rooms%20II -- прямая проходит через минимальное количество интервалов <br>
                            https://github.com/AlKiAl/leetcode_com/tree/main/1450.%20Number%20of%20Students%20Doing%20Homework%20at%20a%20Given%20Time
                        </details>                        
                </details>
</details>

<details>  
<summary> palindrome </summary>
        https://github.com/SkosMartren/leetcode_com/tree/main/5.%20Longest%20Palindromic%20Substring
        https://github.com/SkosMartren/leetcode_com/tree/main/9.%20Palindrome%20Number        
        https://github.com/SkosMartren/leetcode_com/tree/main/125.%20Valid%20Palindrome -- + isalnum + tolower   
        https://github.com/SkosMartren/leetcode_com/tree/main/234.%20Palindrome%20Linked%20List
        https://github.com/SkosMartren/leetcode_com/tree/main/680.%20Valid%20Palindrome%20II -- "can be palindrome after deleting at most one character from it."               
</details>

<details>  
<summary> Parentheses </summary>
    https://github.com/SkosMartren/leetcode_com/tree/main/20.%20Valid%20Parentheses -- stack + unordered_map : Open -> Closed  <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/22.%20Generate%20Parentheses -- + string_stack + recursive.  Open + Closed = 2N AND Open >= Closed AND Open <= N <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/301.%20Remove%20Invalid%20Parentheses -- + recursive                 
</details>

<details>  
<summary> passes one / two / ... </summary>
        https://github.com/SkosMartren/leetcode_com/tree/main/71.%20Simplify%20Path -- stringstream.  transform this absolute path into its simplified canonical path Unix-style <br>  
        https://github.com/SkosMartren/leetcode_com/tree/main/93.%20Restore%20IP%20Addresses  <br>  
        https://github.com/AlKiAl/leetcode_com/tree/main/135.%20Candy  <br>  
        https://github.com/SkosMartren/leetcode_com/tree/main/238.%20Product%20of%20Array%20Except%20Self  -- product_nums / nums[i] <br>  
  <details>  
<summary> Check Contains Duplicate with a condition ... </summary>      
        https://github.com/SkosMartren/leetcode_com/tree/main/217.%20Contains%20Duplicate  <br> 
        https://github.com/SkosMartren/leetcode_com/tree/main/219.%20Contains%20Duplicate%20II -- nums[i] == nums[j] and abs(i - j) <= k <br>  
        https://github.com/AlKiAl/leetcode_com/tree/main/220.%20Contains%20Duplicate%20III -- abs(i - j) <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff <br>       
</details>
        <details>  
      <summary> (Increasing) decreasing (Continuous) sequence </summary>      
              https://github.com/SkosMartren/leetcode_com/tree/main/896.%20Monotonic%20Array      
              https://github.com/AlKiAl/leetcode_com/tree/main/300.%20Longest%20Increasing%20Subsequence -- + b.s. <br> 
              https://github.com/SkosMartren/leetcode_com/tree/main/581.%20Shortest%20Unsorted%20Continuous%20Subarray -- Two pointer + passes two <br>
              https://github.com/AlKiAl/leetcode_com/tree/main/674.%20Longest%20Continuous%20Increasing%20Subsequence <br>
          ---------------------------------------------------------------------------------------------------   <br>
              https://github.com/AlKiAl/leetcode_com/tree/main/978.%20Longest%20Turbulent%20Subarray <br>
              https://github.com/AlKiAl/leetcode_com/blob/main/3105.%20Longest%20Strictly%20Increasing%20or%20Strictly%20Decreasing%20Subarray
      </details>
</details>


<details>  
<summary> prefix </summary>      
         https://github.com/AlKiAl/leetcode_com/tree/main/14.%20Longest%20Common%20Prefix -- L.C.P. strings  <br>  
         https://github.com/SkosMartren/leetcode_com/tree/main/2657.%20Find%20the%20Prefix%20Common%20Array%20of%20Two%20Arrays <br>            
</details>


<details>  
<summary> prefix sum (+ Subarray) </summary>    
        https://github.com/AlKiAl/leetcode_com/tree/main/53.%20Maximum%20Subarray <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/238.%20Product%20of%20Array%20Except%20Self <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/560.%20Subarray%20Sum%20Equals%20K -- + u_m : Prefix -> Count . total number of subarr whose sum = k <br>
        ---------------------------------------------------------------------------------------------------   <br>
        CurrentPrefixSumModK = (CurrentPrefixSumModK + num%k + k)%k where % --> divisible <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/523.%20Continuous%20Subarray%20Sum -- $\exists$ subarr that have a sum divisible by k and lenght >= 2.   <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/974.%20Subarray%20Sums%20Divisible%20by%20K -- number subarr that have a sum divisible by k.
</details>


<details>  
<summary> recursive </summary>      
    https://github.com/SkosMartren/leetcode_com/tree/main/341.%20Flatten%20Nested%20List%20Iterator + queue    
</details>


<details>  
<summary>  Sorted  </summary>        
        https://github.com/SkosMartren/leetcode_com/tree/main/274.%20H-Index -- Индекс хирша определяется как максимальное значение h, при котором данный исследователь опубликовал не менее h статей, каждая из которых цитировалась не менее h раз. <br>
        https://github.com/AlKiAl/leetcode_com/tree/main/128.%20Longest%20Consecutive%20Sequence -- length of the longest consecutive elements sequence <br>
        https://github.com/AlKiAl/leetcode_com/tree/main/215.%20Kth%20Largest%20Element%20in%20an%20Array -- == nth_element <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/977.%20Squares%20of%20a%20Sorted%20Array    
        <details>                
        <summary> Merge   </summary>
            https://github.com/SkosMartren/leetcode_com/tree/main/617.%20Merge%20Two%20Binary%20Trees -- PreOrder
            https://github.com/SkosMartren/leetcode_com/tree/main/56.%20Merge%20Intervals -- iter 
            https://github.com/SkosMartren/leetcode_com/tree/main/88.%20Merge%20Sorted%20Array -- iter   <br>
            ---------------------------------------------------------------------------------------------------          
            https://github.com/SkosMartren/leetcode_com/tree/main/21.%20Merge%20Two%20Sorted%20Lists -- rec
            https://github.com/SkosMartren/leetcode_com/tree/main/23.%20Merge%20k%20Sorted%20Lists -- rec                
        </details>
        <br>
        <details>  
        <summary> counting  </summary>   
                https://github.com/SkosMartren/leetcode_com/tree/main/49.%20Group%20Anagrams
                https://github.com/SkosMartren/leetcode_com/tree/main/242.%20Valid%20Anagram + passes two    
                https://github.com/SkosMartren/leetcode_com/tree/main/347.%20Top%20K%20Frequent%20Elements + nth_element + Hash table              
                https://github.com/SkosMartren/leetcode_com/tree/main/692.%20Top%20K%20Frequent%20Words + partial_sort + Hash table
        </details>
</details>


<details>  
<summary> Sliding Window </summary>
    https://github.com/SkosMartren/leetcode_com/tree/main/239.%20Sliding%20Window%20Maximum -- max val from size = k S.W. . Using deque  <br>
    https://github.com/AlKiAl/leetcode_com/tree/main/2841.%20Maximum%20Sum%20of%20Almost%20Unique%20Subarray -- max sum in S.W. size = k contains at least m distinct elements. Using UnHash NumToCount
</details>


<details>  
<summary> (Sub)string </summary>                
    https://github.com/SkosMartren/leetcode_com/tree/main/157.%20Read%20N%20Characters%20Given%20Read4  <br>    
    https://github.com/AlKiAl/leetcode_com/tree/main/205.%20Isomorphic%20Strings    <br>    
    https://github.com/SkosMartren/leetcode_com/tree/main/459.%20Repeated%20Substring%20Pattern -- check S == pattern + ... + pattern  <br> 
    https://github.com/SkosMartren/leetcode_com/tree/main/387.%20First%20Unique%20Character%20in%20a%20String   <br>
      https://github.com/SkosMartren/leetcode_com/tree/main/392.%20Is%20Subsequence -- T.P. . no more than min(|s1|,|s2|) editorial distance <br>   
  https://github.com/AlKiAl/leetcode_com/tree/main/771.%20Jewels%20and%20Stones -- подсчитать количетсво символов в stones, которые встречаются в jewels
        <details>  
        <summary> Reverse </summary>    
    https://github.com/SkosMartren/leetcode_com/tree/main/344.%20Reverse%20String  -- T.P.       <br> 
    https://github.com/AlKiAl/leetcode_com/tree/main/151.%20Reverse%20Words%20in%20a%20String -- cleanSpaces: separator must be one space. The separator can be more than one space by condition <br> 
    https://github.com/AlKiAl/leetcode_com/tree/main/186.%20Reverse%20Words%20in%20a%20String%20II  -- without cleanSpaces. The separator can be more than one space by condition <br> 
    https://github.com/SkosMartren/leetcode_com/tree/main/557.%20Reverse%20Words%20in%20a%20String%20III  -- T.P. . the separator is by condition one space  <br>   
        </details>           
        <details>  
        <summary> Math </summary>    
                https://github.com/SkosMartren/leetcode_com/tree/main/43.%20Multiply%20Strings     
                https://github.com/SkosMartren/leetcode_com/tree/main/415.%20Add%20Strings
        </details>        
        <details>  
        <summary> Anagram  </summary>
                https://github.com/SkosMartren/leetcode_com/tree/main/49.%20Group%20Anagrams
                https://github.com/SkosMartren/leetcode_com/tree/main/76.%20Minimum%20Window%20Substring -- Check exist |Anagram| <= |Substring|. S.W.  <br> 
                 https://github.com/SkosMartren/leetcode_com/tree/main/242.%20Valid%20Anagram + passes two        
                https://github.com/SkosMartren/leetcode_com/tree/main/438.%20Find%20All%20Anagrams%20in%20a%20String -- Find all |Anagram| == |Substring|. S.W.  <br> 
                https://github.com/SkosMartren/leetcode_com/tree/main/567.%20Permutation%20in%20String --  Check exist |Anagram| == |Substring|. S.W. <br> 
        </details>        
        <details>  
        <summary> Substring </summary>
                https://github.com/SkosMartren/leetcode_com/tree/main/3.%20Longest%20Substring%20Without%20Repeating%20Characters -- S.W. . Longest substring with unique characters <br> 
                https://github.com/AlKiAl/leetcode_com/tree/main/2743.%20Count%20Substrings%20Without%20Repeating%20Character -- S.W. .  дана строка. Вернуть количество всевоможных подстрок, состоящих из уникальных элементов <br>
                https://github.com/SkosMartren/leetcode_com/tree/main/28.%20Find%20the%20Index%20of%20the%20First%20Occurrence%20in%20a%20String -- find idx start substring in string <br>  
          --------------------------------------------------------------------------------------------------- <br> 
                https://github.com/AlKiAl/leetcode_com/tree/main/424.%20Longest%20Repeating%20Character%20Replacement -- S.W. . Longest substring with same characters after at most k flip <br> 
                https://github.com/SkosMartren/leetcode_com/tree/main/1446.%20Consecutive%20Characters  -- T.P. . find max substr with same symb  <br>   
          --------------------------------------------------------------------------------------------------- <br> 
          https://github.com/AlKiAl/leetcode_com/tree/main/Remove%20All%20Occurrences%20of%20a%20Substring%20by%20pattern -- удаляются все, помимо образовавшихся после удаления <br> 
          https://github.com/AlKiAl/leetcode_com/tree/main/1910.%20Remove%20All%20Occurrences%20of%20a%20Substring -- удаляются все, в том числе образовавшиеся после удаления <br> 
                    --------------------------------------------------------------------------------------------------- <br> 
                    return the length of the longest substring of s that contains at most k distinct characters. <br>    
                    https://github.com/SkosMartren/leetcode_com/tree/main/159.%20Longest%20Substring%20with%20At%20Most%20Two%20Distinct%20Characters  -- S.W.  <br> 
                    https://github.com/SkosMartren/leetcode_com/tree/main/340.%20Longest%20Substring%20with%20At%20Most%20K%20Distinct%20Characters   -- S.W.                   
        </details>                            
</details>

<details>  
<summary> tree </summary>
        <details>  
        <summary> LCA </summary>
        https://github.com/SkosMartren/leetcode_com/tree/main/235.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Search%20Tree -- Iter <br>
        https://github.com/SkosMartren/leetcode_com/tree/main/236.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree -- PreOrder + PostOrder. Find LCA <br>        
        https://github.com/AlKiAl/leetcode_com/blob/main/1644.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20II -- Find LCA + Check exist node   <br>   
        ---------------------------------------------------------------------------------------------------        
        https://github.com/SkosMartren/leetcode_com/tree/main/160.%20Intersection%20of%20Two%20Linked%20Lists ==                        
        https://github.com/SkosMartren/leetcode_com/tree/main/1650.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20III -- Iter. Find LCA if exist Parent                  
        </details>
        <br>
        <details>  
        <summary> BST </summary>
            https://github.com/SkosMartren/leetcode_com/tree/main/98.%20Validate%20Binary%20Search%20Tree -- InOrder
            https://github.com/SkosMartren/leetcode_com/tree/main/449.%20Serialize%20and%20Deserialize%20BST
            https://github.com/SkosMartren/leetcode_com/tree/main/700.%20Search%20in%20a%20Binary%20Search%20Tree -- Iter     
                https://github.com/AlKiAl/leetcode_com/tree/main/938.%20Range%20Sum%20of%20BST -- sum of values of all nodes inclusive range [low, high] <br>          
            https://github.com/SkosMartren/leetcode_com/tree/main/1008.%20Construct%20Binary%20Search%20Tree%20from%20Preorder%20Traversal            
        </details>
        <br>
        <details>  
        <summary> BT </summary>    
            https://github.com/SkosMartren/leetcode_com/tree/main/105.%20Construct%20Binary%20Tree%20from%20Preorder%20and%20Inorder%20Traversal -- тут есть хорошая картинка
                <br>
                https://github.com/SkosMartren/leetcode_com/tree/main/124.%20Binary%20Tree%20Maximum%20Path%20Sum -- PostOrder <br>
                https://github.com/SkosMartren/leetcode_com/tree/main/404.%20Sum%20of%20Left%20Leaves -- AnyOrder    <br>
                https://github.com/AlKiAl/leetcode_com/tree/main/652.%20Find%20Duplicate%20Subtrees -- PostOrder + u_m : str(Subtree) -> Count <br>
                ---------------------------------------------------------------------------------------------------                 
                https://github.com/SkosMartren/leetcode_com/tree/main/100.%20Same%20Tree -- PreOrder
                https://github.com/SkosMartren/leetcode_com/tree/main/101.%20Symmetric%20Tree -- PreOrder   <br>
                --------------------------------------------------------------------------------------------------- 
                https://github.com/SkosMartren/leetcode_com/tree/main/104.%20Maximum%20Depth%20of%20Binary%20Tree -- AnyOrder <br>   
                https://github.com/AlKiAl/leetcode_com/tree/main/102.%20Binary%20Tree%20Level%20Order%20Traversal   <br>  
                https://github.com/SkosMartren/leetcode_com/tree/main/103.%20Binary%20Tree%20Zigzag%20Level%20Order%20Traversal -- PreOrder  <br> 
                https://github.com/SkosMartren/leetcode_com/tree/main/199.%20Binary%20Tree%20Right%20Side%20View  -- PreOrder <br> 
                https://github.com/SkosMartren/leetcode_com/tree/main/110.%20Balanced%20Binary%20Tree -- PostOrder <br>
                https://github.com/SkosMartren/leetcode_com/tree/main/543.%20Diameter%20of%20Binary%20Tree -- PostOrder 
        </details>
</details>


<details>  
<summary> Two pointer </summary>        
    https://github.com/SkosMartren/leetcode_com/tree/main/11.%20Container%20With%20Most%20Water  + Greedy         <br> 
    https://github.com/SkosMartren/leetcode_com/tree/main/42.%20Trapping%20Rain%20Water                <br> 
    https://github.com/AlKiAl/leetcode_com/tree/main/209.%20Minimum%20Size%20Subarray%20Sum -- minimal length of a subarray whose sum is greater than or equal to target <br> 
        <details>  
        <summary> (Re)move </summary>    
            https://github.com/SkosMartren/leetcode_com/tree/main/26.%20Remove%20Duplicates%20from%20Sorted%20Array -- each unique element appears only once <br> 
            https://github.com/SkosMartren/leetcode_com/tree/main/80.%20Remove%20Duplicates%20from%20Sorted%20Array%20II -- each unique element appears at most twice  <br> 
            https://github.com/SkosMartren/leetcode_com/tree/main/27.%20Remove%20Element --> 
            https://github.com/SkosMartren/leetcode_com/tree/main/283.%20Move%20Zeroes  -- move any val to prefix / postfix     
        </details>         
</details>

<details>  
<summary> wandering through the plane </summary>    
  https://github.com/SkosMartren/leetcode_com/tree/main/657.%20Robot%20Return%20to%20Origin -- passes one + check end == start  <br> 
  https://github.com/SkosMartren/leetcode_com/tree/main/1041.%20Robot%20Bounded%20In%20Circle -- passes one + end check side != north  <br> 
  https://github.com/SkosMartren/leetcode_com/tree/main/1496.%20Path%20Crossing -- check path crosses itself at any point      
</details>

<details>  
<summary> Yandex </summary>    
        - дана доска размера N на N, на ней конь, некоторые клетки запрещены, на них конь не наступает, надо поменить все клетки, достижимые конем <br>
        <details>  
      <summary> (Sub)string </summary>    
          https://github.com/SkosMartren/leetcode_com/tree/main/Remove%20All%20Occurrences%20of%20a%20Substring%20by%20pattern    <br> 
          https://github.com/SkosMartren/leetcode_com/tree/main/157.%20Read%20N%20Characters%20Given%20Read4        <br>     
          https://github.com/SkosMartren/leetcode_com/tree/main/replace%20char%20on%20string    <br>         
      </details>
  <details> 
      <summary> Array </summary>    
          https://github.com/SkosMartren/leetcode_com/tree/main/Find%20elements%20in%20first%20sequence%20not%20in%20second%20two%20pointers -- return all val difference       <br>
            https://github.com/SkosMartren/leetcode_com/tree/main/960%20%C2%B7%20First%20Unique%20Number%20in%20Data%20Stream%20II List + mapping (такая связка используется для быстрого удаления из середины по итератору). вернуть первый уникальный элемент из префикса чисел    <br> 
          https://github.com/SkosMartren/leetcode_com/tree/main/increasing%20and%20decreasing%20sequence      
      </details>    
</details>


<details>  
<summary> 2D Matrix </summary>    
    https://github.com/AlKiAl/leetcode_com/tree/main/36.%20Valid%20Sudoku <br>
    https://github.com/SkosMartren/leetcode_com/tree/main/48.%20Rotate%20Image -- rotate the matrix by 90 degrees   
    https://github.com/SkosMartren/leetcode_com/tree/main/74.%20Search%20a%202D%20Matrix -- Binary search   
    https://github.com/AlKiAl/leetcode_com/tree/main/85.%20Maximal%20Rectangle -- макс. площ. прямоугольника из 1
    https://github.com/AlKiAl/leetcode_com/tree/main/1329.%20Sort%20the%20Matrix%20Diagonally         
    https://github.com/SkosMartren/leetcode_com/tree/main/1572.%20Matrix%20Diagonal%20Sum
</details>


</details>

<details>
<summary>Binary search</summary>

- [Median of Two Sorted Arrays](https://github.com/SkosMartren/leetcode_com/tree/main/4.%20Median%20of%20Two%20Sorted%20Arrays)
- [Search a 2D Matrix](https://github.com/SkosMartren/leetcode_com/tree/main/74.%20Search%20a%202D%20Matrix)
- [Find K Closest Elements](https://github.com/SkosMartren/leetcode_com/tree/main/658.%20Find%20K%20Closest%20Elements)
- [Binary Search](https://github.com/SkosMartren/leetcode_com/tree/main/704.%20Binary%20Search)

  <details>
  <summary>Bitonic sequence</summary>

  - [Bitonic sort](https://www.geeksforgeeks.org/bitonic-sort/)
  - [Wikipedia: Bitonic sorter](https://en.wikipedia.org/wiki/Bitonic_sorter)
  - [Сеть Бетчера](https://neerc.ifmo.ru/wiki/index.php?title=%D0%A1%D0%B5%D1%82%D1%8C_%D0%91%D0%B5%D1%82%D1%87%D0%B5%D1%80%D0%B0)
  - [Find Minimum in Rotated Sorted Array](https://github.com/SkosMartren/leetcode_com/tree/main/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array)
  - [Search in Rotated Sorted Array](https://github.com/SkosMartren/leetcode_com/tree/main/33.%20Search%20in%20Rotated%20Sorted%20Array)
  - [Leetcode Problem: Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)
  - [Leetcode Problem: Check if Array is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/)

  </details>
</details>

![ alt](https://github.com/SkosMartren/useful-materials/blob/main/asymptotics_containers.png)

