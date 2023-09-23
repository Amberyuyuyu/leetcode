### 118.杨辉三角

给定一个非负整数 *`numRows`，*生成「杨辉三角」的前 *`numRows`* 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

来源：力扣

https://leetcode.cn/problems/pascals-triangle/



思路：

​		动态规划的思路来解题。

​		定义`ret`，用于存放最终结果， `*returnSize = numRows`，`*returnColumnSizes = (int*)malloc(sizeof(int)*numRows)`。

​		定义变量`i`，取值范围是0～`numRows`。`ret[i]=malloc(sizeof(int)*(i+1))`,`(*returnColumnSizes)[i]=i+1`。第`i`行第一个元素和最后一个元素都为1，其余元素与上一行的元素值有关：

```c
	for(int j=1; j<i; j++){
        ret[i][j] = ret[i-1][j]+ret[i-1][j-1];
  }
```

​	最终返回`ret`即可。		