https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/description/

https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/solutions/637034/c-tackle-multiqueries-in-3-ways-explained-w-diagram-solution/ -- разобрать 2 последних решения!

У Федора Меньшикова разбор отсут-т!

____

На основе тестов:

[1,2,3]  
[5,5,5]  
queryTime = 5  
3

[1,2,5]  
[5,5,7]  
queryTime = 5  
3

[1,5,5]  
[5,5,7]  
queryTime = 5  
3

можно сделать вывод, что при подсчете "number of students doing their homework at time queryTime" в момент времени queryTime учитываются студенты, 
пркратившие делать ДЗ в момент времени queryTime

____

В my_code_three_type.cpp читабельность получше, в сравнении с my_code_two_type.cpp

____

<img src="https://github.com/SkosMartren/useful-materials/blob/main/for_1450_leetcode_1.png" width="800" height="500"/>
