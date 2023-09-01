### 2240.买钢笔和铅笔的方案数

给你一个整数 `total` ，表示你拥有的总钱数。同时给你两个整数 `cost1` 和 `cost2` ，分别表示一支钢笔和一支铅笔的价格。你可以花费你部分或者全部的钱，去买任意数目的两种笔。

请你返回购买钢笔和铅笔的 **不同方案数目** 。

来源：力扣

https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/?envType=daily-question&envId=2023-09-01



思路：

​		定义变量`ret`用于存放最终结果。

​		定义变量`i`，初始化为0，用于表示购买钢笔的个数，`i`应该小于等于`total/cost1`。

​		`ret`每次都加上`(total-cost1*i)/cost2+1`，最终，遍历结束后返回`ret`。这里的1表示剩余的钱不买铅笔，`(total-cost1*i)/cost2`代表的是剩余的钱买铅笔的方法数。