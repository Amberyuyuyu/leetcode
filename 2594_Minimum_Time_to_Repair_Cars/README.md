### 2594.修车的最少时间

给你一个整数数组 `ranks` ，表示一些机械工的 **能力值** 。`ranksi` 是第 `i` 位机械工的能力值。能力值为 `r` 的机械工可以在 `r * n2` 分钟内修好 `n` 辆车。

同时给你一个整数 `cars` ，表示总共需要修理的汽车数目。

请你返回修理所有汽车 **最少** 需要多少时间。

**注意：**所有机械工可以同时修理汽车。

来源：力扣

https://leetcode.cn/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2023-09-07



思路：

​		采用二分法解题。

​		`ranks`中数字越小的成员，说明他修车越快。而且修车数量与给的修车时间成正比，因此，定义变量`left`和`right`，分别初始化为`find_min(ranks,ranksSize)`和`find_min(ranks,ranksSize)*cars*cars`。这是一个闭区间，当满足条件`left<=right`时，定义变量`mid=left+(right-left)/2`，如果`t`为`mid`时总修车量`sum>=cars`，就将`right`左移：`right=mid-1`，否则将`left`右移：`left=mid+1`。

​		最终返回结果为`right+1`，因为`right`右边的`sum`一定是大于等于`cars`的。

