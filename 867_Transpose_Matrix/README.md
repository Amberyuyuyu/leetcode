### 867.转置矩阵

给你一个二维整数数组 `matrix`， 返回 `matrix` 的 **转置矩阵** 。

矩阵的 **转置** 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

来源：力扣

https://leetcode.cn/problems/transpose-matrix/



思路：

​		定义变量`m`和`n`分别表示原矩阵的行数和列数，定义与原矩阵维度完全相同的矩阵`res`，遍历原矩阵，`res[i][j]=matrix[j][i]`。