### 74.搜索二维矩阵

给你一个满足下述两条属性的 `m x n` 整数矩阵：

- 每行中的整数从左到右按非递减顺序排列。
- 每行的第一个整数大于前一行的最后一个整数。

给你一个整数 `target` ，如果 `target` 在矩阵中，返回 `true` ；否则，返回 `false` 。

来源：力扣

https://leetcode.cn/problems/search-a-2d-matrix/



思路：

​		二分查找。

​		定义变量`m= matrixSize`，`n=*matrixColSize`。定义`left=0`，`right=m*n-1`，`right`为将矩阵展开后最后一个元素的下标。当满足条件`left<=right`时，定义变量`mid=left+(right-left)/2`，定义`num`为`matrix[mid/n][mid%n]`，这个是矩阵中间位置的元素，如果`num>target`，就左移`right`：`right=mid-1`，如果`num<target`，就右移`left`：`left=mid+1`，如果`num==target`，直接返回`true`。当不满足条件`left<=right`时，说明矩阵中没有符合条件的元素，直接返回`false`。