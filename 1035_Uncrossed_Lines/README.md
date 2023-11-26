### 1035.不相交的线

在两条独立的水平线上按给定的顺序写下 `nums1` 和 `nums2` 中的整数。

现在，可以绘制一些连接两个数字 `nums1[i]` 和 `nums2[j]` 的直线，这些直线需要同时满足满足：

-  `nums1[i] == nums2[j]`
- 且绘制的直线不与任何其他连线（非水平线）相交。

请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。

以这种方法绘制线条，并返回可以绘制的最大连线数。

来源：力扣

https://leetcode.cn/problems/uncrossed-lines/



思路：

​		动态规划。

​		定义`dp`数组：`vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0)`。定义变量`i`和`j`，分别用于遍历`nums1`和`nums2`。如果`nums1[i-1]==nums2[j-1]`，就执行`dp[i][j]=dp[i-1][j-1]+1`。否则，执行`dp[i][j] = max(dp[i-1][j],dp[i][j-1])`。

​		最终返回值为`dp[nums1.size()][nums2.size()]`。