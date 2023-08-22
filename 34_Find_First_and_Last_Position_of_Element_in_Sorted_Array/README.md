### 34.在排序数组中查找元素的第一个和最后一个位置

给你一个按照非递减顺序排列的整数数组 `nums`，和一个目标值 `target`。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 `target`，返回 `[-1, -1]`。

你必须设计并实现时间复杂度为 `O(log n)` 的算法解决此问题。

来源：力扣

https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/



思路：

​		采用二分法的思路解题。

​		定义函数`lower_bound`，起初左右端点`left`、`right`分别初始化为0和`len(nums)-1`，是一个闭区间。因此，在满足`left<=right`时，定义变量`mid`，计算方式为`left+(right-left)//2`。如果`nums[mid]<target`，那么此时将`mid+1`作为新的`left`：`left=mid+1`。如果`nums[mid]>=target`，设置新的`right=mid-1`，由于是找到第一个值为`target`的位置，因此当中间值等于`target`时仍旧需要缩小区间范围（将`right`减小至`mid-1`）,直到最后`right<left`时，`left`指向的就是第一次出现`target`的位置。