https://leetcode.com/problems/simplify-path/description/

https://walkccc.me/LeetCode/problems/0071/

https://leetcode.com/problems/simplify-path/solutions/1847526/best-explanation-ever-possible-not-a-clickbait/

<p align="center">Ex</p>

Input: path = "/a/./b/../../c/"  
Output: "/c"

okay, so the first command /a/ means get into the folder /a/

The next command is /./ means stay over there

The next command is /b/ means get into the folder /b/

The next command is /../ means come out from the folder /b/

The next command is /../ means come out from the folder /a/

Now we are kind of in home directory

The next command is /c/ means get into the folder /c/

And in the output we return what command we left with.

