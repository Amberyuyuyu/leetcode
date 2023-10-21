### 436.寻找右区间

给你一个区间数组 `intervals` ，其中 `intervals[i] = [starti, endi]` ，且每个 `starti` 都 **不同** 。

区间 `i` 的 **右侧区间** 可以记作区间 `j` ，并满足 `startj`` >= endi` ，且 `startj` **最小化** 。注意 `i` 可能等于 `j` 。

返回一个由每个区间 `i` 的 **右侧区间** 在 `intervals` 中对应下标组成的数组。如果某个区间 `i` 不存在对应的 **右侧区间** ，则下标 `i` 处的值设为 `-1` 。

来源：力扣

https://leetcode.cn/problems/find-right-interval/



思路：

​		定义`result`数组，用于存放最终结果。定义哈希表`map`，用于存放每个区间的左端点出现的下标。

​		遍历`intervals`，定义迭代器对象`it=map.lower_bound(v[1])`，寻找`map`数组中大于`v[1]`的最小的`v[0](key)`。如果未找到，就在`result`中加入-1，如果成功找到，就将`(*it).second`加入`result`中。