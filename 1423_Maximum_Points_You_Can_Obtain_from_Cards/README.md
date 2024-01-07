### 1423.可获得的最大点数

几张卡牌 **排成一行**，每张卡牌都有一个对应的点数。点数由整数数组 `cardPoints` 给出。

每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 `k` 张卡牌。

你的点数就是你拿到手中的所有卡牌的点数之和。

给你一个整数数组 `cardPoints` 和整数 `k`，请你返回可以获得的最大点数。

来源：力扣

https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/



思路：

​		定义`n`为`cardPoints`的大小，定义`m=n-k`，求`k`张牌的最大点数，等同于求`m`张牌的最小点数和。

​		首先算出从`cardPoints`的开头到`cardPoints[m-1]`的所有牌的点数和，采用滑动窗口的思想，定义`i=m`，`i<n`，每次`s+=cardPoints[i]-cardPoints[i-m]`，然后比较原有的`min_s`和`s`的大小关系，将较小值变为新的`min_s`。

​		最终返回值为`accumulate(cardPoints.begin(),cardPoints.end(),0)-min_s`。