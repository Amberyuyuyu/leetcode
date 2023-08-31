### 238.除自身以外数组的乘积

给你一个整数数组 `nums`，返回 *数组 `answer` ，其中 `answer[i]` 等于 `nums` 中除 `nums[i]` 之外其余各元素的乘积* 。

题目数据 **保证** 数组 `nums`之中任意元素的全部前缀元素和后缀的乘积都在 **32 位** 整数范围内。

请**不要使用除法，**且在 `O(*n*)` 时间复杂度内完成此题。

来源：力扣

https://leetcode.cn/problems/product-of-array-except-self/



思路：

​		定义`ret`，将`ret`中每个元素都置为1。定义变量`left`和`right`，都初始化为1。

​		定义变量`i`，初始化为1，用于遍历整个`nums`，每次都执行`left *= nums[i-1]`以及r`ight *= nums[numsSize-i]`，然后`ret[i] *= left`，`ret[numsSIze-i-1]*=right`。

​		最终，`ret`中所有元素都是数组`nums`中任意元素的全部前缀和后缀的乘积之和。

​		

​		