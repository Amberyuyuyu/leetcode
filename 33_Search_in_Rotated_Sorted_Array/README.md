### 33.搜索旋转排序数组

整数数组 `nums` 按升序排列，数组中的值 **互不相同** 。

在传递给函数之前，`nums` 在预先未知的某个下标 `k`（`0 <= k < nums.length`）上进行了 **旋转**，使数组变为 `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`（下标 **从 0 开始** 计数）。例如， `[0,1,2,4,5,6,7]` 在下标 `3` 处经旋转后可能变为 `[4,5,6,7,0,1,2]` 。

给你 **旋转后** 的数组 `nums` 和一个整数 `target` ，如果 `nums` 中存在这个目标值 `target` ，则返回它的下标，否则返回 `-1` 。

你必须设计一个时间复杂度为 `O(log n)` 的算法解决此问题。

来源：力扣

https://leetcode.cn/problems/search-in-rotated-sorted-array/



思路：

​		仍旧采用二分法思路解题。

​		需要寻找`target`，就要在153题解题思路上加入对`target`位于哪个升序数组的判断。定义`is_blue`函数，用于判断`nums[mid]`以及`target`与`nums[numsSize-1]`之间的关系：

- 当`nums[mid]`比`nums[numsSize-1]`大时，说明`mid`在第一个上升序列中，如果`target`同样位于第一个序列(`target>nums[numsSize-1]`)，同时满足`nums[mid]`大于等于`target`，这时缩小范围的操作为`right=mid`。

- 当`nums[mid]`比`nums[numsSize-1]`大时，如果此时`target`位于第二个序列（`target<nums[numsSize-1]`）或者在第一个序列中位于`mid`之后，这时直接通过`left=mid`来缩小范围。

- 当`nums[mid]`比`nums[numsSize-1]`小时，说明`mid`位于第二个序列，如果此时`target`位于第一个序列（`target>end`）或者`target`位于第二个序列同时比`nums[mid]`还要小时，这时通过`right=mid`来缩小范围。

- 当`nums[mid]`比`nums[numsSize-1]`小时，说明`mid`位于第二个序列，此时`target`比`nums[mid]`大同时`target`比`nums[numsSize-1]`小时，直接将`mid`赋值给`left`，可以缩小遍历范围。

  在正式遍历时，`left`赋值为-1，`right`赋值为`len(nums)`，为开区间。定义`mid = (right+left)//2`，采用`is_blue`函数判断缩小区间的端点。在不满足`left+1<right`时，判断`right`以及`nums[right]`的值，如果`right=len(nums)`或者`target!=nums[right]`，说明数组中未找到`target`，直接返回-1，否则返回`right`。

  

  

​		