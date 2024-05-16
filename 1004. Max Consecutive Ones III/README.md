https://leetcode.com/problems/max-consecutive-ones-iii/description/

related: 
- https://leetcode.com/problems/longest-repeating-character-replacement/description/ -- более общая задача с последовательностью мощностью 26
- Замечание: из этой задачи следует задача https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
- /485. Max Consecutive Ones <-- 487. Max Consecutive Ones II AND 1493. Longest Subarray of 1's After Deleting One Element <-- 1004. Max Consecutive Ones III

https://walkccc.me/LeetCode/problems/1004/

У Федора Меньшикова разбор отсут-т!

__________________________________________


Перефраз условия: "Найдите самый длинный подмассив в бинарном векторе, содержащий не более K нулей."

Двигаем правую границу окна, если есть возможность изменить 0 на 1 -- делаем это, изменяя K [CountUpdZero] посредством вычитания 1

Если изменили 0 на 1 более K [CountUpdZero] раз, то двигаем левую границу и изменяем K до тех пор, пока K не станет равным 0. Изменение K осуществляется посредством прибавления 1, если левая граница при сдвиге оказалось в 0.

Проверяем, является ли новое окно, подходящее под условие задачи, длинее найденого предыдущего. Если да -- обновляем ответ и индексы начала и конца окна.

__________________________________________

<p align="center">My ex 1</p>

      [0,0,0,0,0,0]
      2
Expected 2


<p align="center">My ex 2</p>

|   nums   	|   	|   	|  1  	| 1 	| 1   	| 0  	| 0 	| 0 	| 1 	|
|:--------:	|:-:	|:-:	|:---:	|---	|-----	|----	|---	|---	|---	|
| RightPtr 	| 0 	|   	|     	|   	| ^^^ 	|    	|   	|   	|   	|
|  LeftPtr 	| 0 	|   	| ^^^ 	|   	|     	|    	|   	|   	|   	|
|     k    	| 2 	|   	|     	|   	|     	|    	|   	|   	|   	|

|   nums   	|   	|   	|  1  	| 1 	| 1 	| 0 (1)  	| 0  	| 0  	| 1 	|
|:--------:	|:-:	|:-:	|:---:	|---	|---	|--------	|----	|----	|---	|
| RightPtr 	| 0 	|   	|     	|   	|   	| ^^^    	|    	|    	|   	|
|  LeftPtr 	| 0 	|   	| ^^^ 	|   	|   	|        	|    	|    	|   	|
|     k    	| 1 	|   	|          	|   	|   	|        	|   	|  	|  	|

|   nums   	|   	|   	|  1  	| 1 	| 1 	| 0 (1)  	| 0 (1) 	| 0  	| 1 	|
|:--------:	|:-:	|:-:	|:---:	|---	|---	|--------	|-------	|----	|---	|
| RightPtr 	| 0 	|   	|     	|   	|   	|        	| ^^^   	|    	|   	|
|  LeftPtr 	| 0 	|   	| ^^^ 	|   	|   	|        	|       	|    	|   	|
|     k    	| 0 	|   	|     	|   	|   	|        	|       	|  	|  	|

|   nums   	|   	|   	| 1 	| 1 	| 1   	| 0 (1)  	| 0 (1)  	| 0   	| 1 	|
|:--------:	|:-:	|:-:	|:-:	|---	|-----	|--------	|--------	|-----	|---	|
| RightPtr 	| 0 	|   	|   	|   	|     	|        	|        	| ^^^ 	|   	|
|  LeftPtr 	| 0 	|   	|   	|   	| ^^^ 	|        	|        	|     	|   	|
|     k    	| -1 	|   	|  	|  	|          	|       	|       	|         	|   	|

|   nums   	|   	|   	| 1 	| 1 	| 1 	| 0 (1)  	| 0 (1)  	| 0   	| 1 	|
|:--------:	|:-:	|:-:	|:-:	|---	|---	|--------	|--------	|-----	|---	|
| RightPtr 	| 0 	|   	|   	|   	|   	|        	|        	| ^^^ 	|   	|
|  LeftPtr 	| 0 	|   	|   	|   	|   	| ^^^    	|        	|     	|   	|
|     k    	| 0 	|   	|   	|   	|   	|       	|       	|          	|   	|

|   nums   	|   	|   	| 1 	| 1 	| 1 	| 0   	| 0 (1)  	| 0 (1) 	| 1 	|
|:--------:	|:-:	|:-:	|:-:	|---	|---	|-----	|--------	|-------	|---	|
| RightPtr 	| 0 	|   	|   	|   	|   	|     	|        	| ^^^   	|   	|
|  LeftPtr 	| 0 	|   	|   	|   	|   	|     	| ^^^    	|       	|   	|
|     k    	| 0 	|   	|   	|   	|   	|     	|       	|      	|   	|

__________________________________________


F L, [7/1/2023 1:00 AM]
Друзья, почему если в коде

```objectivec
   int longestOnes(vector<int>& A, int K) {

        int i = 0; int j = 0;
        for (; j < A.size(); ++j) {

            if (A[j] == 0) {K--;}
            if (K < 0 && A[i++] == 0) {K++;}
            
        }
        
        return j - i;

    }
```

заменить строку 
if (K < 0 && A[i++] == 0) {K++;} 
на 
if (K < 0 && A[i] == 0) {K++;++i;}

то будет ошибка?

Dmitriy, [7/1/2023 1:03 AM]
Я в код не вникал, но сороки не эквивалетны
В первой счетчик увеличивается в большем числе случаев, чем во второй

ГАД, [7/1/2023 1:03 AM]
ну это же не одно и тоже
в первом ты всегда увеличиваешь i, если только K<0, во втором только если K<0 и A[i] == 0

__________________________________________


For everyone who is confused about how this method works like I used to be, here is my explanation of the solution:

Take A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3 for example.
We know the answer is 10 with subarray from A[2] to A[11].
Through the iteration of j, this subarray would be found while j = 11 and i = 2.
What happens then?
Well as we keep iterate j we will find out that j and i keep adding 1 in every iteration, which makes the distance between j and i the same(and is the currently best).
The distance between j and i would change again if there is a longer subarray exist.
Try appending more 1s in A you'll see.

In short:
We are looking for bigger window size, when we find one, we use this window to iterate till we find a larger one(if any).

__________________________________________


I spent 20 minutes trying to understand this and I turned from "wtf is this code it can't be working" to "holy it's genius". It's so intuitive, though I do think more explanation need to be added here for better understanding.

Long story short: i, j is like a moving "memory" sliding frame. (Note: i, j definity NOT the exact index for the largest range!) Whenever there's a better choice, the span of the frame will fit for the larger range. So you can directly return the final span/length of the frame as the final output.

More detailed version: as you can see from the code, j is constantly moving right. K here can be considered as the remaining feasible amount of flips, and reflects the current range (i.e., from i to j). When K<0, it's not a feasible solution and when K>=0, it'll be a feasible solution. If currently range is not yet a feasible solution or better than current "memory" frame (i.e., K<0 judgement) , i will try follow up the j and j-i (the frame size) remains unchanged, keeping the current maximum size intact. Whenever the flip count K of current range (i.e., still i to j) is greater or equals to 0, it means we can possibly expand our frame, and that's exactly what the code does. (i remains unchanged since it will not goes into K<0 clauses, and j keeps moving when K>=0). Eventually, when j comes to the end, the "memory" frame will automatically (by design of course) give us the maximum range throughout the array.


__________________________________________


Excellent! For anyone that was struggling to understand this like I was, try walking through an input like [1, 1, 1, 0, 0, 0, 0, 0], K=2 and you will see that the maximum window will get carried through until the for loop terminates with j == 7 and i == 3.


__________________________________________


do not like this solution. Not easy to read. Also, the i and j value are not for the maximum range. If the interviewer asks to print out the start and end index for the maximum range, then you need to change the code a lot.


__________________________________________

```objectivec
int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right;
        for (right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {k--;}

            if (k < 0){
                if(nums[left] == 0){k++;}
                left++;
            }
        }
        return right - left;
    }
```
