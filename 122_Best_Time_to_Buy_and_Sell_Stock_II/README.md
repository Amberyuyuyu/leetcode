### 122.买卖股票的最佳时机II

给你一个整数数组 `prices` ，其中 `prices[i]` 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii



思路：

​		必须先买入才能卖出。

​		根据贪心的思路，相邻两天中，只要后一天的股价高于前一天，就可以盈利。只要可以盈利，就进行买卖。将所有盈利加起来，记作`ret`，返回`ret`即可。