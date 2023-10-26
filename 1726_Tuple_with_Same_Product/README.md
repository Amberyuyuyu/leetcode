### 1726.同积元组

给你一个由 **不同** 正整数组成的数组 `nums` ，请你返回满足 `a * b = c * d` 的元组 `(a, b, c, d)` 的数量。其中 `a`、`b`、`c` 和 `d` 都是 `nums` 中的元素，且 `a != b != c != d` 。

来源：力扣

https://leetcode.cn/problems/tuple-with-same-product/



思路：

​		定义哈希表变量`mulCount`，定义`n = nums.size()`，定义`mul`用于存放暂时的乘积。遍历整个数组，每一次都执行`num = nums[i]*nums[j]`，`mulCount[mul]++`。

​		定义变量`ans`，用于存放最终结果，初始化为0。遍历`mulCount`，每一次都执行`ans += v*(v-1)/2`，因为没有重复元素，`v`表示有`v`组元素的乘积为`key`，从中任意选择两组，就为`v*(v-1)/2`。 

​		最终返回结果为`ans<<3`，因为a,b,c,d四个数可以构成8个满足题意的元组。