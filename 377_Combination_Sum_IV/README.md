### 377 组合总和 IV

给你一个由 **不同** 整数组成的数组 `nums` ，和一个目标整数 `target` 。请你从 `nums` 中找出并返回总和为 `target` 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

来源：力扣

https://leetcode.cn/problems/combination-sum-iv/



思路：

​		动态规划，完全背包问题。

​		`dp[0] = 1`。`dp[i]`：凑成目标正整数的排列个数为`dp[i]`。递推公式：`dp[j] += dp[j-nums[i]]`。

​		要保证`j-nums[i]>=0`，`dp[j]<INT_MAX-dp[j-nums[i]]`。

​		最终返回值为`dp[target]`。

​		

