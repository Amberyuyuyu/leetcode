### 2342.数位和相等数对的最大和

给你一个下标从 **0** 开始的数组 `nums` ，数组中的元素都是 **正** 整数。请你选出两个下标 `i` 和 `j`（`i != j`），且 `nums[i]` 的数位和 与 `nums[j]` 的数位和相等。

请你找出所有满足条件的下标 `i` 和 `j` ，找出并返回 `nums[i] + nums[j]` 可以得到的 **最大值** *。*

来源：力扣

https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/



思路：

​		定义变量`ans`，初始化为-1，定义数组`mx`，长度为82（因为最大就是9*9=81）。遍历整个数组`nums`，定义`s=0`，用于表示数位和，如果`s`在`mx`中出现过，`ans = max(ans, mx[s]+num)`。 `mx[s]=max(mx[s],num)`。