### 381.O(1)时间插入、删除和获取随机元素-允许重复

`RandomizedCollection` 是一种包含数字集合(可能是重复的)的数据结构。它应该支持插入和删除特定元素，以及删除随机元素。

实现 `RandomizedCollection` 类:

- `RandomizedCollection()`初始化空的 `RandomizedCollection` 对象。
- `bool insert(int val)` 将一个 `val` 项插入到集合中，即使该项已经存在。如果该项不存在，则返回 `true` ，否则返回 `false` 。
- `bool remove(int val)` 如果存在，从集合中移除一个 `val` 项。如果该项存在，则返回 `true` ，否则返回 `false` 。注意，如果 `val` 在集合中出现多次，我们只删除其中一个。
- `int getRandom()` 从当前的多个元素集合中返回一个随机元素。每个元素被返回的概率与集合中包含的相同值的数量 **线性相关** 。

您必须实现类的函数，使每个函数的 **平均** 时间复杂度为 `O(1)` 。

**注意：**生成测试用例时，只有在 `RandomizedCollection` 中 **至少有一项** 时，才会调用 `getRandom` 。



来源：力扣

https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/



思路：

​		本题与上一题的区别在于可能存在重复元素，因此本题中unordered_map中存储的元素类型为`<int,unordered_set<int>>`。

​		在删除操作中，不同之处在于，定义`i = *(idx[val].begin())`，`nums[i] = nums.back()`，`idx[val].erase(i)`，`idx[nums[i]].erase(nums.size()-1)`，然后需要判断i如果不是最后一个元素，需要执行`idx[nums[i]].insert(i)`，如果删除该元素后，`idx[val].size()==0`，说明数组中现在不存在这个元素，直接在map中去除：`idx.erase(val)`。

