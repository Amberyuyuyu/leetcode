### 931.下降路径最小和

给你一个 `n x n` 的 方形 整数数组 `matrix` ，请你找出并返回通过 `matrix` 的下降路径 的 最小和 。

下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 `(row, col)` 的下一个元素应当是 `(row + 1, col - 1)`、`(row + 1, col)` 或者 `(row + 1, col + 1)` 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-falling-path-sum



思路：

​	（1）`dp`数组及下标`i,j`的含义：`dp[i][j]`表示从起始位置到达下标为`i,j`位置处的下降路径和；

​	（2）递推公式：分为三种情况，`j==0`、`0<j<*matrixColSize-1`、`j==*matrixColSize-1`。

​			`j=0`时，计算方式为`dp[i][j] = matrix[i][j] + fmin(dp[i-1][j],dp[i-1][j+1])`

​			`0<j<*matrixColSize-1`时，计算方式为：

				int tmp = fmin(dp[i-1][j],dp[i-1][j-1]);
	      dp[i][j] = matrix[i][j]+fmin(tmp,dp[i-1][j+1]);

​		`j==*matrixColSize-1`时，计算方式为`dp[i][j] = matrix[i][j] + fmin(dp[i-1][j],dp[i-1][j-1])`

​	（3）初始化：首先将`dp[matrixSize][*matrixColSize]`所有元素全部初始化为0，然后根据题意，每一次都是从第一行选择一个数开始走，因此`dp[0][i]`全部初始化为`matrix[0][i]`。

​	（4）根据题意，遍历顺序是从前向后，`i`取值从1开始，到`matrixSize`结束，`j`取值范围是`[0,*matrixColSize-1]`。

​	（5）下降路径最小和应该在`dp[matrixSize-1][j]`中诞生，`j`取值范围是`[0,*matrixColSize-1]`。