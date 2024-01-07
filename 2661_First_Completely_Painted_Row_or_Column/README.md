### 2661.找出叠涂元素

给你一个下标从 **0** 开始的整数数组 `arr` 和一个 `m x n` 的整数 **矩阵** `mat` 。`arr` 和 `mat` 都包含范围 `[1，m * n]` 内的 **所有** 整数。

从下标 `0` 开始遍历 `arr` 中的每个下标 `i` ，并将包含整数 `arr[i]` 的 `mat` 单元格涂色。

请你找出 `arr` 中第一个使得 `mat` 的某一行或某一列都被涂色的元素，并返回其下标 `i` 。

来源：力扣

https://leetcode.cn/problems/first-completely-painted-row-or-column/



来源：力扣

https://leetcode.cn/problems/first-completely-painted-row-or-column/



思路：

​		定义`m`和`n`分别为`mat`数组的行和列，定义unordered_map类型的变量`idx`，用于存放`mat[i][j]`以及对应下标`{i,j}`。定义数组`row(n)`和`col(n)`，遍历`arr`数组，定义`[i, j] = idx[arr[k]]`，然后执行`++row[i]`和`++col[j]`，如果`row[i]==n || col[j]==m`，直接返回`k`。