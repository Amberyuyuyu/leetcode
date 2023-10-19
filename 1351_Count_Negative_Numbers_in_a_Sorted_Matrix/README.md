### 1351.统计有序矩阵中的负数

给你一个 `m * n` 的矩阵 `grid`，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 请你统计并返回 `grid` 中 **负数** 的数目。

来源：力扣

https://leetcode.cn/problems/count-negative-numbers-in-a-sorted-matrix/



思路：

​		定义变量`ret`，初始化为0，用于表示最终结果。

​		遍历矩阵，每一行记为`x`，如果`x[t]<0`，说明这一行从该元素向后全部为负数，在`ret`上添加`x.size()-t`，并跳出本行的循环。

​		