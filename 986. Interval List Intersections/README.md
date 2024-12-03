https://leetcode.com/problems/interval-list-intersections/

- https://leetcode.com/problems/interval-list-intersections/solutions/646988/c-easy-6-lines-two-pointer-100/ == two ptr

related 
- https://github.com/SkosMartren/leetcode_com/tree/main/56.%20Merge%20Intervals

https://walkccc.me/LeetCode/problems/0986/

У Федора Меньшикова разбор отсут-т!


     /*
       У двух отрезков нет пересечения в двух случиях: 
       
               /1/
       a1|----------|a2
                        b1|-------|b2  
                    
               /2/
                                      a1|----------|a2
                        b1|-------|b2   
       
       Что зквивалентно в логическом виде:  
       a2 < b1 || b2 < a1 -- заметим, что a1, b1 по одну сторону знака неравенства, тогда, имеет место запись: 
       max(a1, b1) > max(a2, b2) > min(a2, b2) -- это более сильное условие, нежели просто max(a1, b1) > max(a2, b2)
       Если инвертировать: 
       a2 >= b1 && b2 >= a1 
       max(a1, b1) <= min(a2, b2)
       получим условие пересечения
       */
