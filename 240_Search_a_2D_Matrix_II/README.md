### 240.搜索二维矩阵II



编写一个高效的算法来搜索 `*m* x *n*` 矩阵 `matrix` 中的一个目标值 `target` 。该矩阵具有以下特性：

- 每行的元素从左到右升序排列。
- 每列的元素从上到下升序排列。



来源：力扣

https://leetcode.cn/problems/search-a-2d-matrix-ii/



思路：

​		定义`m`和`n`，分别为矩阵的行数、列数。如果`m`和`n`中有一个为0，直接返回`false`即可。

​		定义变量`i=0`，`j=n-1`，从矩阵左上角开始寻找`target`，在满足`i<m && j>=0`的条件下，如果`matrix[i][j]==target`，直接`return true`。如果`matrix[i][j]>target`，需要将`j`减小，否则，需要增大`i`。

​		如果可以遍历结束，就返回`false`。