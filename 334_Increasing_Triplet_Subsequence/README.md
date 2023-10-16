### 334.递增的三元子序列

给你一个整数数组 `nums` ，判断这个数组中是否存在长度为 `3` 的递增子序列。

如果存在这样的三元组下标 `(i, j, k)` 且满足 `i < j < k` ，使得 `nums[i] < nums[j] < nums[k]` ，返回 `true` ；否则，返回 `false` 。

来源：力扣

https://leetcode.cn/problems/increasing-triplet-subsequence/



思路：

​		如果`nums.size()<3`，直接返回`false`即可。

​		定义变量`small=INT_MAX`，`mid=INT_MAX`，遍历整个数组，如果`num<=small`，就将`small`重新赋值为`num`，如果`small<num<=mid`，就将`num`赋值给`mid`，如果满足`num>small&&num>mid`，直接返回`true`即可。

​		如果可以遍历到数组结束，说明没有符合条件的三元组，返回`false`。