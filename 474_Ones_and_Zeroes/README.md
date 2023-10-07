### 474.一和零

给你一个二进制字符串数组 `strs` 和两个整数 `m` 和 `n` 。

请你找出并返回 `strs` 的最大子集的长度，该子集中 **最多** 有 `m` 个 `0` 和 `n` 个 `1` 。

如果 `x` 的所有元素也是 `y` 的元素，集合 `x` 是集合 `y` 的 **子集** 。

来源：力扣

https://leetcode.cn/problems/ones-and-zeroes/



思路：

​		动态规划，0-1背包问题。

​		`str`数组中的元素就是物品，每个物品都只有一个。而`m`和`n`相当于背包，两个维度的背包。`dp[i][j]`：最多有`i`个0和`j`个1的`strs`的最大子集的大小。递推公式为`dp[i][j] = max(dp[i][j],dp[i-zeroNum][j-oneNum]+1)`。

​		最终返回值为`dp[m][n]`。