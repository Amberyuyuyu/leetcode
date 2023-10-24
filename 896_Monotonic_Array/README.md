### 896.单调数列

如果数组是单调递增或单调递减的，那么它是 **单调** *的*。

如果对于所有 `i <= j`，`nums[i] <= nums[j]`，那么数组 `nums` 是单调递增的。 如果对于所有 `i <= j`，`nums[i]> = nums[j]`，那么数组 `nums` 是单调递减的。

当给定的数组 `nums` 是单调数组时返回 `true`，否则返回 `false`。

来源：力扣

https://leetcode.cn/problems/monotonic-array/



思路：

​		定义两个布尔类型的变量`inc`和`dec`，分别标志着升序和降序，都初始化为`true`，遍历数组，如果满足`nums[i]<nums[i-1]`，就将`inc`设置为`false`，如果满足`nums[i]>nums[i-1]`，就将`dec`设置为`false`。如果满足`!inc&&!dec`，就直接返回`false`，如果遍历结束，返回`true`。		