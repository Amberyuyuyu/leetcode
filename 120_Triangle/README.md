### 120.三角形最小路径和

给定一个三角形 `triangle` ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。**相邻的结点** 在这里指的是 **下标** 与 **上一层结点下标** 相同或者等于 **上一层结点下标 + 1** 的两个结点。也就是说，如果正位于当前行的下标 `i` ，那么下一步可以移动到下一行的下标 `i` 或 `i + 1` 。

来源：力扣

https://leetcode.cn/problems/triangle/



思路：

​		动态规划。

​		定义变量`n=triangle.size()`，定义`dp`数组，长度为`n`。`dp[0][0] = triangle[0][0]`。在第i行，分为三种情况：

-  `dp[i][0] = dp[i-1][0]+triangle[i][0]`;
- 在1~`i-1`位置上， `dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]`；
- 在第`i`个位置上，`dp[i][i] = dp[i-1][i-1]+triangle[i][i]`。

最后返回第n行的最小值：`return *min_element(dp[n-1].begin(),dp[n-1].end())`。