### 1749.任意子数组和的绝对值的最大值

给你一个整数数组 `nums` 。一个子数组 `[numsl, numsl+1, ..., numsr-1, numsr]` 的 和的绝对值 为 `abs(numsl + numsl+1 + ... + numsr-1 + numsr)` 。

请你找出 `nums` 中 和的绝对值 最大的任意子数组（可能为空），并返回该 最大值 。

`abs(x)` 定义如下：

如果 `x` 是负整数，那么 `abs(x) = -x` 。
如果 `x` 是非负整数，那么 `abs(x) = x` 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray



思路：

​	一个数的绝对值的最大值，可能是这个数本身，也可能是本身最小值的绝对值。

​	分别求出最大值和最小值，比较最大值和最小值的绝对值，较大的那一个就是结果。

​	采用动态规划的方式，求最大值和最小值：

		max += nums[i];
	  maxSum = fmax(maxSum,max);
	  max = fmax(0,max);
	  min += nums[i];
	  minSum = fmin(minSum,min);
	  min = fmin(0,min);

