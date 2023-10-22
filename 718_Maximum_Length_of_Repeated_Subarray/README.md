### 718.最长重复子数组

给两个整数数组 `nums1` 和 `nums2` ，返回 *两个数组中 **公共的** 、长度最长的子数组的长度* 。

来源：力扣

https://leetcode.cn/problems/maximum-length-of-repeated-subarray/



思路：

​		动态规划。

​		定义`dp`数组，是一个二维矩阵，具体为 `vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0))`。定义变量`result`，用于表示最终返回结果，初始化为0。定义变量`i`和`j`，分别用于遍历`nums1`和`nums2`。如果`nums1[i-1]==nums2[j-1]`，就将`dp[i][j]`设置为`dp[i-1][j-1]+1`。`dp[i][j]` ：以下标`i-1`为结尾的A，和以下标`j-1`为结尾的B，最长重复子数组长度为`dp[i][j]`。 此时`dp[i][j]>result`，就替换掉原来的`result`。