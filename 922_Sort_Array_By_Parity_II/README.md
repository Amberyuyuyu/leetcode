### 922.按奇偶排序数组II

给定一个非负整数数组 `nums`， `nums` 中一半整数是 **奇数** ，一半整数是 **偶数** 。

对数组进行排序，以便当 `nums[i]` 为奇数时，`i` 也是 **奇数** ；当 `nums[i]` 为偶数时， `i` 也是 **偶数** 。

你可以返回 *任何满足上述条件的数组作为答案* 。

来源：力扣

https://leetcode.cn/problems/sort-array-by-parity-ii/



思路：

​		定义变量`i`和`j`，分别初始化为0和1，分别用于标记偶数下标和奇数下标。定义n为数组nums的长度。

​		当满足`i<n && j<n`时，满足`i<n && 0==(nums[i]&1`时，`i`后移：`i+=2`，满足`j<n && 0!=(nums[j]&1`时，`j`后移：`j+=2`，当`i`和`j`不满足上述条件时，交换`nums[i]`和`nums[j]`。