### 1218.最长定差子序列

给你一个整数数组 `arr` 和一个整数 `difference`，请你找出并返回 `arr` 中最长等差子序列的长度，该子序列中相邻元素之间的差等于 `difference` 。

**子序列** 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 `arr` 派生出来的序列。

来源：力扣

https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/



思路：

​		动态规划。

​		定义`unordered_map`类型的`dp`，遍历整个`arr`，`dp[v] = dp[v-diffeience]+1`，`ans=max(ans,dp[v])`。

​		

