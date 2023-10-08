### 674.最长连续递增子序列

给定一个未经排序的整数数组，找到最长且 **连续递增的子序列**，并返回该序列的长度。

**连续递增的子序列** 可以由两个下标 `l` 和 `r`（`l < r`）确定，如果对于每个 `l <= i < r`，都有 `nums[i] < nums[i + 1]` ，那么子序列 `[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]]` 就是连续递增子序列。

来源：力扣

https://leetcode.cn/problems/longest-continuous-increasing-subsequence/



思路：

​		如果`nums.size()==0`，直接返回0即可。定义`result`变量，用于存放最终结果，初始化为1。

​		定义`dp`数组，长度与原数组相同，将所有元素都初始化为1。如果存在`nums[i]>nums[i-1]`，`dp[i]`就应该是`dp[i-1]+1`。如果遇到`dp[i]>result`，就将`result`重新赋值。