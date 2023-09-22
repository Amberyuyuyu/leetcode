### 435.无重叠区间

给定一个区间的集合 `intervals` ，其中 `intervals[i] = [starti, endi]` 。返回 *需要移除区间的最小数量，使剩余区间互不重叠* 。

来源：力扣

https://leetcode.cn/problems/non-overlapping-intervals/



思路：

​		如果`intervalsSize==1`，直接返回0即可。

​		定义变量`ret`，用于表示需要移除的最少区间数量。借助快排，将`intervals`数组按照左边界升序排列。借助变量i遍历整个数组，如果`intervals[i][0]<intervals[i-1][1]`，说明两个区间有交集，执行`ret++`，`intervals[i][1] = fmin(intervals[i-1][1],intervals[i][1])`。

