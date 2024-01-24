### 2276.统计区间中的整数数目

给你区间的 **空** 集，请你设计并实现满足要求的数据结构：

- **新增：**添加一个区间到这个区间集合中。
- **统计：**计算出现在 **至少一个** 区间中的整数个数。

实现 `CountIntervals` 类：

- `CountIntervals()` 使用区间的空集初始化对象
- `void add(int left, int right)` 添加区间 `[left, right]` 到区间集合之中。
- `int count()` 返回出现在 **至少一个** 区间中的整数个数。

**注意：**区间 `[left, right]` 表示满足 `left <= x <= right` 的所有整数 `x` 。

来源：力扣

https://leetcode.cn/problems/count-integers-in-intervals/



思路：

​		定义map类型的变量`m`，以及用于统计整数个数的变量`cnt`，初始化为0。map类型的key值会自动按照升序

​		`add`函数中，思路为删除被要添加的区间覆盖的区间（包括部分覆盖），然后将删除的区间与新增区间进行合并。为了方便找到第一个被[left,right]覆盖到的区间，可以用`key`存区间的右端点，`value`存区间的左端点。

​		定义`it=m.lower_bound(left)`，当满足`it!=m.end()&&it->second<=right`时，定义`l=it->second`，`r=it->right`，`left=min(left,l)`，`right=min(right,r)`，`int -= r-l+1`，`left`和`right`分别为合并后的新区间的左端点和右端点，合并后需要在`m`中移除原来的区间。因为区间发生了合并，在这里直接将这个区间内的所有数据移除，在覆盖区间全部合并结束跳出循环后，再重新加入新区间的元素个数：`cnt += right-left+1`。然后将新区间加入到`m`中：`m[right]=left`。

