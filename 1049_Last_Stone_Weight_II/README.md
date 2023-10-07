### 1049.最后一块石头 II

有一堆石头，用整数数组 `stones` 表示。其中 `stones[i]` 表示第 `i` 块石头的重量。

每一回合，从中选出**任意两块石头**，然后将它们一起粉碎。假设石头的重量分别为 `x` 和 `y`，且 `x <= y`。那么粉碎的可能结果如下：

- 如果 `x == y`，那么两块石头都会被完全粉碎；
- 如果 `x != y`，那么重量为 `x` 的石头将会完全粉碎，而重量为 `y` 的石头新重量为 `y-x`。

最后，**最多只会剩下一块** 石头。返回此石头 **最小的可能重量** 。如果没有石头剩下，就返回 `0`。

来源：力扣

https://leetcode.cn/problems/last-stone-weight-ii/



思路：

​		0-1背包问题。

​		尽可能让重量接近的石头一起粉碎，最后如果剩下石头的话，会是最小的。

​		因此将数组中所有石头分为两组，尽量让两组重量接近。定义变量`target=sum/2`，`dp[target+1]`数组，将所有元素初始化为0。

​		动态规划方程：`dp[j]=fmax(dp[j]`, `dp[j-stones[i]]+stones[i])`。

​		由于是向下取整，因此`sum-dp[target]>=dp[target]`。最终返回结果为`sum-dp[target]-dp[target]`。