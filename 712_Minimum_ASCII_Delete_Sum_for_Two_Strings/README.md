### 712.两个字符串的最小ASCII删除和

给定两个字符串`s1` 和 `s2`，返回 *使两个字符串相等所需删除字符的 **ASCII** 值的最小和* 。

来源：力扣

https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/



思路：

​		动态规划。

​		首先定义`count`变量，是将所有`s1`和`s2`的值进行相加得到的。如果`s1`和`s2`中有一个为空，直接返回`count`即可。

​		定义`dp`数组，维度是`s1.length()*s2.length()`，如果`s1[0]==s2[0]`，就将`dp[0][0]`初始化为`s1[0]`，否则，将`dp[0][0]`初始化为0。

​		当`i`取值范围在[1,`s1.length()`)中时，`j`取值范围是[1,`s2.length()`)，`dp[i][j]=max(dp[i-1][j],dp[i][j-1])`，如果`s1[i]==s2[j]`，此时`dp[i][j]`的值为`max(dp[i][j],dp[i-1][j-1]+s1[i])`。

​		最终返回值为`count-2*dp[s1.length()-1][s2.length()-1]`。