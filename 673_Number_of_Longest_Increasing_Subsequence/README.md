### 673.最长递增子序列的个数

给定一个未排序的整数数组 `nums` ， *返回最长递增子序列的个数* 。

**注意** 这个数列必须是 **严格** 递增的。

来源：力扣

https://leetcode.cn/problems/number-of-longest-increasing-subsequence/



思路：

​		动态规划。

​		定义`n=nums.size()`，如果`n<2`，直接返回`n`即可。定义`dp(n,1)`和`count(n,1)`，`count`数组代表长度为`i`的递增子数组的个数，`dp[i]`代表以`i`为结尾的最长递增子序列的长度。定义变量`i`和`j`，取值范围分别为[0,n)、[0,i)，如果满足`nums[i]>nums[j]`，如果还满足`dp[j]+1>dp[i]`，就设置`dp[i]=dp[j]+1`，`count[i]=count[j]`，如果`dp[j]+1==dp[i]`，就在`count[i]`基础上加`count[j]`。

​	定义`max`为`dp`中最大值。定义`res`，存放最终返回结果。遍历整个`dp`数组，如果`dp[i]==max`，就在`res`中加入`count[i]`。