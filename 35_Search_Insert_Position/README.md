### 35.搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 `O(log n)` 的算法。

来源：力扣

https://leetcode.cn/problems/search-insert-position/



思路：

​		二分查找。

​		定义`left=0`，`right=numsSize-1`。当满足`left<=right`时，定义变量`mid=left+(right-left)/2`，如果`nums[mid]>target`，就将`right`左移：`right=mid-1`。如果`nums[i]==target`，直接返回`mid`，如果`nums[i]<target`，就将`left`右移：`left = mid+1`。

​		最终不满足`left<=right`时，说明整个数组中不存在`target`，直接返回`left`，是`target`应该被插入的位置。