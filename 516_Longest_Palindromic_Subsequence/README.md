### 516.最长回文子序列

给你一个字符串 `s` ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

来源：力扣

https://leetcode.cn/problems/longest-palindromic-subsequence/



思路：

​		定义变量`n`，表示字符串的长度。

​		定义函数`dfs(i, j)`，用于计算字符串在下标`i`到`j`之间最长的回文子序列。如果`i>j`，直接返回0，如果`i==j`，直接返回1。如果`s[i]==s[j]`，就返回`dfs(i+1,j-1)+2`，否则的话，返回`max(dfs(i,j-1),dfs(i+1,j))`。

​		整个数组的最长回文子串的长度为`dfs(0,n-1)`。