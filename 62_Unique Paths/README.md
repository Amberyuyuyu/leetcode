### 62.不同路径

一个机器人位于一个 `m x n` 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

![image](https://github.com/Amberyuyuyu/leetcode/blob/master/62_Unique%20Paths/exp.png)

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/unique-paths



思路：

​		（1）`dp`以及下标`i`,`j`：`dp[i][j]`表示从起始位置到第`[i+1][j+1]`位置上共有多少种路径；

​		（2）递推公式：`dp[i][i] = dp[i-1][j]+dp[i][j-1]`;

​		（3）初始化：由于智能向下或向右移动，因此需要初始化所有`i=0`以及`j=0`位置的`dp[i][j]`:

				for(int j=0; j<n; j++){
					dp[0][j] = 1;
				}
				for(int i=0; i<m; i++){
					dp[i][0] = 1;
				}

​		（4）遍历顺序：从前向后，初始化`i=j=0`，遍历条件为`i<m`，`j<n`。

​		最终返回结果为`dp[m-1][n-1]`。
