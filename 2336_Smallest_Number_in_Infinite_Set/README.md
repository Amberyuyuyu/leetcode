### 2336.无限集中的最小数字

现有一个包含所有正整数的集合 `[1, 2, 3, 4, 5, ...]` 。

实现 `SmallestInfiniteSet` 类：

- `SmallestInfiniteSet()` 初始化 **SmallestInfiniteSet** 对象以包含 **所有** 正整数。
- `int popSmallest()` **移除** 并返回该无限集中的最小整数。
- `void addBack(int num)` 如果正整数 `num` **不** 存在于无限集中，则将一个 `num` **添加** 到该无限集最后。

来源：力扣

https://leetcode.cn/problems/smallest-number-in-infinite-set/



思路：

​		定义一个变量`thres`，用于标记最小的元素，初始化为1，定义集合`s`，用于存放后添加的元素中小于`thres`的元素。

​		在添加元素时，如果`num<thres`，就在`s`中插入`num`即可。

​		在删除元素时，如果此时`s`为空，说明最小的元素就是`thres`，定义`ans=thres`，然后将`thres`自增，返回`ans`即可。如果此时`s`不为空，`ans=*s.begin()`，因为set的特点是，元素会自动排序，因此最小的元素一定为`s.begin()`，然后在`s`中移除该元素即可。