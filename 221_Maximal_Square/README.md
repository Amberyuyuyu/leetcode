### 221.最大正方形

在一个由 `'0'` 和 `'1'` 组成的二维矩阵内，找到只包含 `'1'` 的最大正方形，并返回其面积。

来源：力扣

https://leetcode.cn/problems/maximal-square/

思路：

​		如果`matrix.size()==0||matrix[0].size()==0`，直接返回0即可。

​		定义`maxSide=0`，用于表示最大边长。定义变量`row`和`col`，分别代表矩阵的行数和列数。定义`dp`数组，与矩阵维度完全相同。在遍历过程中，如果`matrix[i][j]==1`，此时位于矩阵的边界（`i==0 || j==0`），直接设置`dp[i][j]=1`，如果不是边界情况，`dp[i][j] = min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])`。根据`dp[i][j]`更新`maxSide`的值。

​		最终返回结果为`maxSqure = maxSide*maxSide`。