### 977.有序数组的平方

给你一个按 **非递减顺序** 排序的整数数组 `nums`，返回 **每个数字的平方** 组成的新数组，要求也按 **非递减顺序** 排序。

来源：力扣

https://leetcode.cn/problems/squares-of-a-sorted-array/description/



思路：

​		定义用于存放排序结果的`ret`数组。

​		定义两个指针`i`，`j`，分别初始化为0，`numsSize-1`。

​		定义`pos`，初始化为`numsSize-1`，用于标识在`ret`中存放的位置。

​		如果`nums[i]*nums[i]>nums[j]*nums[j]`，就将`nums[i]*nums[i]`的结果存入`ret[pos]`中，反之，在`ret[pos]`中存入`nums[j]*nums[j]`。

​		