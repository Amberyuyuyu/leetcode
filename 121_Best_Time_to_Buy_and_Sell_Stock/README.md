### 121.买卖股票的最佳时机

给定一个数组 `prices` ，它的第 `i` 个元素 `prices[i]` 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock



思路：

​	首先需要明确的是，必须先找一天买入，才能在后面某一天中卖出。

​	定义变量`min`和`max`，分别初始化为`prices[0]`、0。

​	遍历数组`prices`,如果`prices[i]`小于`min`，就将`min`替换为`prices[i]`。如果`prices[i]-min`大于`max`，就对`max`进行替换。

​	最终返回`max`即可。

