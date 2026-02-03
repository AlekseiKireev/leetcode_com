https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

https://walkccc.me/LeetCode/problems/448/

```
по сути, ксли отсортировать данные, в конечном итоге ожидается:

0 ...   i    ...  len(nums) - 1
| ...   |    ...       |
1 ... i + 1  ...   len(nums) 
```


# Mark as seen by Negation 


Time Complexity : O(n), we only iterate nums twice each taking O(n) time atmost.

Space Complexity : O(1), only constant extra space is being used except for the output ans.

```
nums = [4,3,2,7,8,2,3,1]
1. '4' is present in nums. Mark as present by negating nums[4-1] = nums[3].  Thus, nums[3] = -7
   => nums = [4,3,2,-7,8,2,3,1]
	
2. '3' is present in nums. Mark as present by negating nums[3-1] = nums[2].  Thus, nums[2] = -2
   => nums = [4,3,-2,-7,8,2,3,1]

3. '2' is present in nums. Thus, nums[1] = -3
   => nums = [4,-3,-2,-7,8,2,3,1]
   
4. '7' is present in nums. Thus, nums[6] = -3
   => nums = [4,-3,-2,-7,8,2,-3,1]

5. '8' is present in nums. Thus, nums[7] = -1
   => nums = [4,-3,-2,-7,8,2,-3,-1]
   
6. '2' is present in nums. Thus, nums[1] = -3
   => nums = [4,-3,-2,-7,8,2,-3,-1]   
  
7. '3' is present in nums. Thus, nums[2] = -2
   => nums = [4,-3,-2,-7,8,2,-3,-1]   

7. '1' is present in nums. Thus, nums[0] = -4
   => nums = [-4,-3,-2,-7,8,2,-3,-1]   

Now, the only elements nums[i] which are positive are those where 'i+1' is not found in nums
These are => nums[4] and nums[5].
That means 5 and 6 an not present in the initial nums array
```


