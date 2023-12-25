### 2760.最长奇偶子数组

给你一个下标从 **0** 开始的整数数组 `nums` 和一个整数 `threshold` 。

请你从 `nums` 的子数组中找出以下标 `l` 开头、下标 `r` 结尾 `(0 <= l <= r < nums.length)` 且满足以下条件的 **最长子数组** ：

- `nums[l] % 2 == 0`
- 对于范围 `[l, r - 1]` 内的所有下标 `i` ，`nums[i] % 2 != nums[i + 1] % 2`
- 对于范围 `[l, r]` 内的所有下标 `i` ，`nums[i] <= threshold`

以整数形式返回满足题目要求的最长子数组的长度。

**注意：子数组** 是数组中的一个连续非空元素序列。

来源：力扣

https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/



思路：

​		定义`n=nums.size()`，定义`ans=0`，`i=0`，分别用于存放最终结果、遍历数组。

​		当满足`i<n`时，如果`nums[i]>0||nums[i]%2`，执行`i++`，`continue`。定义`start=i`，`i++`，当满足`i<n && nums[i]<=threshold && nums[i]%2!=nums[i-1]%2`时执行`i++`。`ans`应该为`max(ans, i-start)`。