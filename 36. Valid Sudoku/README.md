https://leetcode.com/problems/valid-sudoku/description/

https://walkccc.me/LeetCode/problems/36/

За каждым боксом можно закрепить индекс в виде: {(r / 3), (c / 3)} -- где r,c - индексы значений, леащих в боксе. После чего заметим, что
* {0,0} --> 0*3+0 = 0
* {0,1} --> 0*3+1 = 1
* ...
* {2,2} --> 2*3+2 = 8
