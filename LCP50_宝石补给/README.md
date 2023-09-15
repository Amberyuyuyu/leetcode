### LCP 50.宝石补给

欢迎各位勇者来到力扣新手村，在开始试炼之前，请各位勇者先进行「宝石补给」。

每位勇者初始都拥有一些能量宝石， `gem[i]` 表示第 `i` 位勇者的宝石数量。现在这些勇者们进行了一系列的赠送，`operations[j] = [x, y]` 表示在第 `j` 次的赠送中 第 `x` 位勇者将自己一半的宝石（需向下取整）赠送给第 `y` 位勇者。

在完成所有的赠送后，请找到拥有**最多**宝石的勇者和拥有**最少**宝石的勇者，并返回他们二者的宝石数量**之差**。

来源：力扣

https://leetcode.cn/problems/WHnhjV/



思路：

​		定义变量`i`，用于遍历整个`operations`，定义`index1`和`index2`，分别为`operations[i][0]`和`operations[i][1]`。定义变量`num=gem[index1]/2`，对`gem`中下标为`index1`和`index2`的元素分别做如下操作：`gem[index1] -= num`，`gem[index2] += num`。`operations`遍历结束后，定义变量`min`、`max`分别为`INT_MAX`和`INT_MIN`，遍历此时的`gem`数组，找到最大值和最小值，最终返回结果为`max-min`。