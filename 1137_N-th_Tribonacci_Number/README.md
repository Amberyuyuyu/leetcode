### 1137.第N个泰波那契数

泰波那契序列 Tn 定义如下： 

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 `n`，请返回第 n 个泰波那契数 Tn 的值。

来源：力扣

https://leetcode.cn/problems/n-th-tribonacci-number/



思路：

​		如果`n`<2，直接返回`n`即可。如果`n==2`，返回1。定义`dp[n+1]`，`dp[0] = 0`，`dp[i]=dp[2]=1`，当`n>2`时，`dp[i] = dp[i-1]+dp[i-2]+dp[i-3]`，最终返回值为`dp[n]`。		