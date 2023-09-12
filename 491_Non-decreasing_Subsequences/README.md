### 491.递增子序列

给你一个整数数组 `nums` ，找出并返回所有该数组中不同的递增子序列，递增子序列中 **至少有两个元素** 。你可以按 **任意顺序** 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

来源：力扣

https://leetcode.cn/problems/non-decreasing-subsequences/



思路：

​		回溯问题。

​		定义全局变量`path`，表示某个子集，`pathTop`代表`path`存放元素个数。定义全局变量`ans`，用于存放最终结果，`ansTop`表示`ans`中子集个数，`ansSize`表示`ans`中每个子集的大小。

​		由于题目中在构造递增子序列时，也需要考虑元素本身在数组中所处的位置，因此本题不可以对数组进行预排序，这样会破坏原本的顺序。

​		定义函数`backtracking`，用于完成回溯算法的实现。如果`path`中元素个数大于等于2时(`pathTop>1`)，就将`path`存入`ans`中。否则的话，定义数组`uset`，用于存放使用过的数字。定义变量`usetTop`，初始化为0，用于表示`used`中存放的元素个数。定义变量`i=startIndex`，如果`path`中有元素存在并且`nums[i]`小于`path`中存放的最后一个元素，就直接执行`continue`，如果通过`find`函数发现在同一层中（`path`中同一下标）找到相同元素，也执行`continue`操作。如果不满足上述两个条件，就将`nums[i]`加入`uset`数组，也加入`path`中，然后`backtracking(nums, numsSize, i + 1)`寻找下一层节点，然后回溯：`pathtop--`。