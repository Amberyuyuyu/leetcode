### 188.买卖股票的最佳时期

给你一个整数数组 `prices` 和一个整数 `k` ，其中 `prices[i]` 是某支给定的股票在第 `i` 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 `k` 笔交易。也就是说，你最多可以买 `k` 次，卖 `k` 次。

**注意：**你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

来源：力扣

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/



思路：

​		如果`prices.size()==0`，直接返回0即可。

​		定义`dp`数组，维度为`prices.size()*(2*k+1)`，将所有元素都初始化为0。

​		达到`dp[i][1]`状态，具体有两种操作方式：

​		(1) 第`i`天买入股票，`dp[i][1]=dp[i-1][0]-prices[i]`;

​		(2) 第`i`天没有操作，沿用了前一天买入的状态：`dp[i][1]=dp[i-1][1]`。

​		选最大的，为`dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][0])`。

​		同理，`dp[i][2]=max(dp[i - 1][i] + prices[i], dp[i][2])`.

​		因此，可以类比剩下的状态：

```c
for (int j = 0; j < 2 * k - 1; j += 2) { 
	dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
	dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
}
```
​		最终返回值为`dp[prices.size()-1][2*k]`。
