### 53.最大子数组和

给你一个整数数组 `nums` ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

**子数组** 是数组中的一个连续部分。

来源：力扣

https://leetcode.cn/problems/maximum-subarray/



思路：

​		采用动态规划的思路来解题。

​		定义`prev`，初始化为0，定义`maxSum`，初始化为`nums[0]`。

​		定义变量`i`，用于遍历数组`nums`。

​		`prev = max(prev+nums[i]，nums[i]);`

​		`maxSum = fmax(maxSum, prev);`

​		

​		最终返回值为`maxSum` 。

​				