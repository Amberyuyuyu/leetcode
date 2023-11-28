### 1312.让字符串成为回文串的最少插入次数

给你一个字符串 `s` ，每一次操作你都可以在字符串的任意位置插入任意字符。

请你返回让 `s` 成为回文串的 **最少操作次数** 。

「回文串」是正读和反读都相同的字符串。

来源：力扣

https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/



思路：

​		动态规划。

​		定义`n = s.size()`，定义`dp`数组`dp[n][n]`，将`dp`数组中所有元素都初始化为0。定义`i=n-1`，当满足`i>=0`时，`dp[i][i]=1`，定义`j=i+1`，当满足`j<n`时，如果`s[i]==s[j]`，`dp[i][j]=dp[i+1][j-1]+2`，否则的话，`dp[i][j]=max(dp[i+1][j],dp[i][j+1])`。

​		最终返回值为`n-dp[0][n-1]`。