### 2824.统计和小于目标的下标对数目

给你一个下标从 **0** 开始长度为 `n` 的整数数组 `nums` 和一个整数 `target` ，请你返回满足 `0 <= i < j < n` 且 `nums[i] + nums[j] < target` 的下标对 `(i, j)` 的数目。

来源：力扣

https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/



思路：

​		定义`n`为`nums`的长度，定义`count=0`，用于表示最后结果。

​		将`nums`升序排列，定义变量`j=0`，最大不超过`n`，变量`i`为0~`j`之间的对应值大于等于`target-nums[j]`的最小的数的下标。找到`i`后，说明在0~`j`之间有`i`个符合条件的数，可以和`nums[j]`组成和小于`target`的组合。