### 162.寻找峰值

峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 `nums`，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 **任何一个峰值** 所在位置即可。

你可以假设 `nums[-1] = nums[n] = -∞` 。

你必须实现时间复杂度为 `O(log n)` 的算法来解决此问题。

来源：力扣

https://leetcode.cn/problems/find-peak-element/



思路：

​		二分法思路来解题。

​		采用左开右闭的区间，`left=0`，`right=len(nums)-1`。

​		当满足条件`left+1<right`时，定义变量`mid=(left+right)//2`。如果`nums[mid]`比`nums[mid+1]`大，说明`mid`是峰顶或者位于峰顶右侧，将`right`设置为`mid+1`。如果`nums[mid]`如果小于`nums[mid+1]`，说明`mid`在峰顶左侧，将`left`设置为`mid`。遍历结束后返回`right`即可。