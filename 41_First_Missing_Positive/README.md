### 41.缺失的第一个正数

给你一个未排序的整数数组 `nums` ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 `O(n)` 并且只使用常数级别额外空间的解决方案。

来源：力扣

https://leetcode.cn/problems/first-missing-positive/



思路：

​		定义变量`i`，初始化为0，用于遍历整个`nums`数组。如果遇到`nums[i]>=1&&nums[i]<=numsSize&&nums[i]!=nums[nums[i]-1]`的时候，交换此时`nums[i]`和`nums[nums[i]-1]`两个数字。这样，在遍历完整个数组后，如果存在`i+1`这个数字，它一定位于`nums[i-1]的`位置上。

​		定义`ans=numsSize+1`，如果此时`nums`数组中元素恰好为`0,1,...,numsSize`，那么未出现的最小正数刚好就是`numsSize+1`。再次遍历数组`nums`，如果`nums[i]!=i+1`，此时这个数就是最终的`ans`，直接`break`。最终返回结果为`ans`。