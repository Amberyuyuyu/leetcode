### 2216.美化数组的最少删除数

给你一个下标从 **0** 开始的整数数组 `nums` ，如果满足下述条件，则认为数组 `nums` 是一个 **美丽数组** ：

- `nums.length` 为偶数
- 对所有满足 `i % 2 == 0` 的下标 `i` ，`nums[i] != nums[i + 1]` 均成立

注意，空数组同样认为是美丽数组。

你可以从 `nums` 中删除任意数量的元素。当你删除一个元素时，被删除元素右侧的所有元素将会向左移动一个单位以填补空缺，而左侧的元素将会保持 **不变** 。

返回使 `nums` 变为美丽数组所需删除的 **最少** 元素数目*。*

来源：力扣

https://leetcode.cn/problems/minimum-deletions-to-make-array-beautiful/



思路：

​		定义`n`为数组长度。定义`ans`变量，初始化为0，用于表示最终结果。在遍历过程中将相邻两个元素看作一组，如果`nums[i]==nums[i+1]`，需要删除其中一个，此时需要`ans++`，如果不相等，就执行i++，表示向后移。美丽数组需要数组长度为偶数，如果不是偶数，还需要删除一个：`ans += (nums.size()-ans)%2`。