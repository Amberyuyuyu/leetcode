### 503.下一个更大的元素 II

给定一个循环数组 `nums` （ `nums[nums.length - 1]` 的下一个元素是 `nums[0]` ），返回 *`nums` 中每个元素的 **下一个更大元素*** 。

数字 `x` 的 **下一个更大的元素** 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 `-1` 。

来源：力扣

https://leetcode.cn/problems/next-greater-element-ii/



思路：

​		拼接一个新的`nums`数组，是由两个原数组拼接而来的，定义数组`ret`，用于存放最终结果，长度为原数组长度，所有元素都初始化为-1。定义栈`st`，用于存放未找到下一个更大元素的所有元素值。`i`用于遍历新数组，`i<2*n-1`。当满足`!stk.empty() && nums[stk.top()]<nums[i%n]`时，`ret[stk.top()] = nums[i%n]`，`stk.pop()`。将`i%n`压栈。

​		

​		

​		