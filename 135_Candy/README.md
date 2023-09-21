### 135.分发糖果

`n` 个孩子站成一排。给你一个整数数组 `ratings` 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

- 每个孩子至少分配到 `1` 个糖果。
- 相邻两个孩子评分更高的孩子会获得更多的糖果。

请你给每个孩子分发糖果，计算并返回需要准备的 **最少糖果数目** 。

来源：力扣

https://leetcode.cn/problems/candy/



思路：

​		按照题目中发糖果的规则，每个`i`都需要同时考虑左右两边的孩子所发的糖果数量。因此需要从前往后、从后往前，遍历修改两次`candyArr`。

​		每个孩子至少被分到一块糖果，因此将`candyArr`中每个元素都初始化为1。

​		第一次遍历时，从前向后遍历，如果`ratings[i]>ratings[i-1]`，`candyArr[i]=candyArr[i-1]+1`。

​		第二次遍历时，从后向前遍历，如果满足`ratings[i]<ratings[i-1]`，需要更新`candyArr[i-1]`：`candyArr[i-1] = max(candyArr[i]+1,candyArr[i-1])`。

​		定义变量`ret`，初始化为0。遍历数组`candyArr`，在`ret`中加上`candyArr[i]`。最终返回`ret`即可。