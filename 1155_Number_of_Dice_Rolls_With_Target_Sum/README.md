### 1155.掷骰子等于目标和的方法数

这里有 `n` 个一样的骰子，每个骰子上都有 `k` 个面，分别标号为 `1` 到 `k` 。

给定三个整数 `n` , `k` 和 `target` ，返回可能的方式(从总共 `kn` 种方式中)滚动骰子的数量，使正面朝上的数字之和等于 `target` 。

答案可能很大，你需要对 `109 + 7` **取模** 。

来源：力扣

https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/



思路：

​		如果`target<n||target>n*k`，直接返回0即可。

​		定义变量`MOD=1e9+7`，定义`n+1`行`target-n+1`列的数组`memo`，将所有值都初始化为-1。定义`dfs(i,j)`，表示的是用`i`个骰子掷出数字之和恰好等于`j`的方案数。`dfs(i,j)=dfs(i-1,j-1)+dfs(i-1,j-2)+...+dfs(i-1,j-k)`。递归边界：`dfs(0,0)=1`，表示数字之和恰好等于0有1种方案。最终答案为`dfs(n, target)`。