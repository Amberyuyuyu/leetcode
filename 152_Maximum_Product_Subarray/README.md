### 152.乘积最大子数组

给你一个整数数组 `nums` ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 **32-位** 整数。

**子数组** 是数组的连续子序列。

来源：力扣

https://leetcode.cn/problems/maximum-product-subarray/



思路：

​		由于存在负数，因此上一个元素所在的乘积最大子数组，在加入当前元素后可能由最小值变为最大值，也可能由最大值变为最小值，因此这里需要两个变量来记录最值：`maxNum`和`minNum`。将它们都初始化为`nums[0]`，定义`n=nums.size()`，如果`n`为0，直接返回0即可。如果`n`为1，直接返回`nums[0]`，定义变量`p`，初始化为`nums[0]`，用于标识最终结果。`i`从1开始向后遍历整个数组，定义`m=maxNum`，用于暂时存放最大乘积。`maxNum`和`minNum`的更新如下：

```c
	maxNum = max(max(maxNum*nums[i],nums[i]),minNum*nums[i]);
  minNum = min(min(m*nums[i],nums[i]),minNum*nums[i]);
```

​	`p=max(maxNum，p)`。