### 73.矩阵置零

给定一个 `m x n` 的矩阵，如果一个元素为 **0** ，则将其所在行和列的所有元素都设为 **0** 。请使用 **[原地](http://baike.baidu.com/item/原地算法)** 算法**。**

来源：力扣

https://leetcode.cn/problems/set-matrix-zeroes/



思路：

​		定义两个数组`row[matrixSize]`和`col[*matrixColSize]`，并且将它们都初始化为0。

​		定义变量`i`和`j`，都初始化为0，用于遍历矩阵`matrix`时分别指代矩阵的横纵下标。在遍历时，遇到`matrix[i][j]=0`时，就将`row[i]`和`col[j]`都置为0。

​		再次遍历整个数组，遇到`col[j]=0`或者`row[i]=0`的情况，就将所有出现`i`和`j`的矩阵元素都置为0。

​		