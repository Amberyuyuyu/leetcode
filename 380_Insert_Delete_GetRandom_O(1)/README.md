### 380.O(1)事件插入、删除和获取随机元素

实现`RandomizedSet` 类：

- `RandomizedSet()` 初始化 `RandomizedSet` 对象
- `bool insert(int val)` 当元素 `val` 不存在时，向集合中插入该项，并返回 `true` ；否则，返回 `false` 。
- `bool remove(int val)` 当元素 `val` 存在时，从集合中移除该项，并返回 `true` ；否则，返回 `false` 。
- `int getRandom()` 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 **相同的概率** 被返回。

你必须实现类的所有函数，并满足每个函数的 **平均** 时间复杂度为 `O(1)` 。

来源：力扣

https://leetcode.cn/problems/insert-delete-getrandom-o1/



思路：

​		定义数组`nums`，用于存放元素，定义unordered_map类型的变量`indices`，用于标记下标和元素对应关系。

​		插入元素：如果`indices.count(val)`，直接返回`false`即可。否则的话，在`nums`末尾插入`val`，定义`index=nums.size()`，将`index`和`val`的对应关系加入到`indices`中，返回`true`即可。

​		删除元素：如果`indices.count(val)`不为真，直接返回`false`即可。定义`index = indices[val]`，定义`last=nums.back()`，将`last`换到`nums[index]`的位置，执行`nums.pop_back()`，然后在`indices`中删除该元素：`indices.erase(val)`，返回`true`。

​		`getRandom`函数：定义`RandomizedSet`函数，用于生成随机数种子：`srand((unsigned)time(nullptr))`。定义随机下标：`randomIndex=rand()%nums.size()`，直接返回`nums[randomIndex]`即可。