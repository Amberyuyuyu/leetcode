### 2529.正整数和负整数的最大计数

给你一个按 **非递减顺序** 排列的数组 `nums` ，返回正整数数目和负整数数目中的最大值。

- 换句话讲，如果 `nums` 中正整数的数目是 `pos` ，而负整数的数目是 `neg` ，返回 `pos` 和 `neg`二者中的最大值。

**注意：**`0` 既不是正整数也不是负整数。

来源：力扣

https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/



思路：

​		定义`n=nums.size()`，定义变量`cnt`用于统计负数个数。遍历整个数组，如果`num`为负数，就执行`cnt++`，如果`num`为0，就执行`n--`。

​		最终返回值为`max(cnt,n-cnt)`。