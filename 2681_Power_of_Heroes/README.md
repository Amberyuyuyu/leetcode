### 2681.英雄的力量

给你一个下标从 0 开始的整数数组 `nums` ，它表示英雄的能力值。如果我们选出一部分英雄，这组英雄的 力量 定义为：

`i0 ，i1 ，... ik` 表示这组英雄在数组中的下标。那么这组英雄的力量为 `max(nums[i0],nums[i1] ... nums[ik])2 * min(nums[i0],nums[i1] ... nums[ik])` 。
请你返回所有可能的 非空 英雄组的 力量 之和。由于答案可能非常大，请你将结果对 109 + 7 取余。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/power-of-heroes



思路：

​		首先将数组`nums`进行升序排序。如果以`nums[i]`结尾，这个子序列的最大值为`nums[i]`。

​		`dp[i]`表示以`nums[i]`结尾的子序列的最小值之和，计算方式为`nums[i]`加上`nums[0]`到`nums[i-1]`对应的所有`dp`值。

​		那么以`nums[i]`结尾的英雄的力量之和为`nums[i]*nums[i]*dp[i]`，记为`res`，将所有的`res`相加得到最终结果。

​		

​		