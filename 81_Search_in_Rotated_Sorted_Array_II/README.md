### 81.搜索旋转排序数组II

已知存在一个按非降序排列的整数数组 `nums` ，数组中的值不必互不相同。

在传递给函数之前，`nums` 在预先未知的某个下标 `k`（`0 <= k < nums.length`）上进行了 **旋转** ，使数组变为 `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`（下标 **从 0 开始** 计数）。例如， `[0,1,2,4,4,4,5,6,6,7]` 在下标 `5` 处经旋转后可能变为 `[4,5,6,6,7,0,1,2,4,4]` 。

给你 **旋转后** 的数组 `nums` 和一个整数 `target` ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 `nums` 中存在这个目标值 `target` ，则返回 `true` ，否则返回 `false` 。

你必须尽可能减少整个操作步骤。

来源：力扣

https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/



思路：

​		首先找到旋转的位置，然后利用二分法寻找数组中是否存在整数target。

​		定义完成二分法的函数`bool myFind(vector<int>& nums, int target, int left, int right)`。

​		定义`len`变量表示数组的长度。如果`len==1&&target==nums[0]`，直接返回`true`。如果`len==1&&target!=nums[0]`，直接返回`false`。定义`flag`变量，用于标记数组中元素是否全部为相同值，初始化为0。如果数组中元素全部相同且等于`target`，直接返回`true`，否则返回`false`。

如果数组中元素不是统一值，就判断是否进行了旋转：

- 如果`nums[len-1]>nums[0]`，说明未进行旋转，如果此时`target>nums[len-1]`或`target<nums[0]`，直接返回`false`即可。否则的话，定义二分的左右端点：`left = 0`，`right=len-1`，调用myFind函数完成查找；
- 如果`nums[len-1]<=nums[0]`，说明确实进行了旋转，定义变量`k`，用于标记旋转的位置。遍历数组`nums`，如果出现`nums[i]<nums[i-1]`的情况，就执行`k = i`，退出循环即可。此时判断`target`与`nums[0]`、`nums[len-1]`的关系：如果`target>nums[0]`，说明它一定存在前半段序列中，定义`left=0`，`right=k-1`；如果`target<nums[len-1]`，说明`target`位于后半段序列，定义`left=k`，`right=len-1`。如果不满足上述两种情况，如果`target`等于`nums[0]`或`nums[len-1]`，就返回`true`，否则返回`false`。