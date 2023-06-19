### 26 删除有序数组中的重复项

给你一个 升序排列 的数组 `nums` ，请你 **原地** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。元素的 **相对顺序** 应该保持 一致 。然后返回 `nums` 中唯一元素的个数。

考虑 `nums` 的唯一元素的数量为 `k` ，你需要做以下事情确保你的题解可以被通过：

更改数组 `nums` ，使 `nums` 的前 `k` 个元素包含唯一元素，并按照它们最初在 `nums` 中出现的顺序排列。`nums` 的其余元素与 `nums` 的大小不重要。
返回 `k` 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array

思路：

​	设置两个起始位置均为0的指针`slow`和`fast`，通过`fast`指针遍历整个数组，遇到等于`nums[slow]`的地方跳过，遇到不为`nums[slow]`的地方，对数组`nums`作出如下转换：`nums[++slow] = nums[fast]`，`fast`遍历完整个数组后，`slow+1`的值即为`k`。

