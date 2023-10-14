### 275.H指数II

给你一个整数数组 `citations` ，其中 `citations[i]` 表示研究者的第 `i` 篇论文被引用的次数，`citations` 已经按照 **升序排列** 。计算并返回该研究者的 h 指数。

[h 指数的定义](https://baike.baidu.com/item/h-index/3991452?fr=aladdin)：h 代表“高引用次数”（high citations），一名科研人员的 `h` 指数是指他（她）的 （`n` 篇论文中）**总共**有 `h` 篇论文分别被引用了**至少** `h` 次。

请你设计并实现对数时间复杂度的算法解决此问题。

来源：力扣

https://leetcode.cn/problems/h-index-ii/



思路：

​		定义`n`为`citations`数组的长度，遍历整个数组，如果`citations[i]>=n-i`，说明第i篇论文被引用次数大于等于`i`，后面的论文的引用次数一定至少为`i`次，直接返回`n-i`即可。如果遍历结束后没有找到满足条件的结果，就返回0。