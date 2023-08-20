### 1444.切披萨的方案数

给你一个 `rows x cols` 大小的矩形披萨和一个整数 `k` ，矩形包含两种字符： `'A'` （表示苹果）和 `'.'` （表示空白格子）。你需要切披萨 `k-1` 次，得到 `k` 块披萨并送给别人。

切披萨的每一刀，先要选择是向垂直还是水平方向切，再在矩形的边界上选一个切的位置，将披萨一分为二。如果垂直地切披萨，那么需要把左边的部分送给一个人，如果水平地切，那么需要把上面的部分送给一个人。在切完最后一刀后，需要把剩下来的一块送给最后一个人。

请你返回确保每一块披萨包含 **至少** 一个苹果的切披萨方案数。由于答案可能是个很大的数字，请你返回它对 10^9 + 7 取余的结果。

来源：力扣

https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza/



思路：

​		定义变量`m`和`n`，分别为`pizzaSize`和`strlen(pizza[0])`,代表披萨维度是`m✖️n`。定义两个矩阵`apples[m+1][n+1]`和`dp[k+1][m+1][n+1]`，分别代表了每个坐标右下方矩形中苹果数量、将坐标右下方披萨切成指定块数的方案数量。

​		`apples[i][j]`计算方式为`apples[i][j]=(pizza[i][j]==A)+apples[i+1][j]+apples[i][j+1]-apples[i+1][j+1]`。

​		`dp[1][i][j]`计算方式：`dp[1][i][j] = apples[i][j]>0 ? 1 : 0`。

​		动态规划方程为：

​				![img]([https://github.com/Amberyuyuyu/leetcode/blob/master/1444_Number_of_Ways_of_Cutting_a_Pizza/formula.png])

​		`i'`和`j'`满足`apples[i][j]>apples[i'][j]`，`apples[i][j]>apples[i][j']`。

​		最终返回`dp[k][0][0]`即可。
