### 80.删除有序数组中的重复项II



给你一个有序数组 `nums` ，请你**[ 原地](http://baike.baidu.com/item/原地算法)** 删除重复出现的元素，使得出现次数超过两次的元素**只出现两次** ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 **[原地 ](https://baike.baidu.com/item/原地算法)修改输入数组** 并在使用 O(1) 额外空间的条件下完成。

来源：力扣

https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/



思路：

​		定义函数`work`，用于返回删除后数组的新长度，输入值为原数组`nums`以及重复元素出现次数的上限值，本题为2。

​		在`work`函数中，定义`len`变量，初始化为0。遍历整个`nums`数组，如果此时`len<k||nums[len-k]!=num`，就执行`nums[len++]=num`，目的是将下标小于k的元素加入`nums`数组，将未在排好序的数组`nums`中出现`k`次的元素加入`nums`数组中。最终返回`len`即可。