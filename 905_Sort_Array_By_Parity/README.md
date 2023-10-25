### 905.按奇偶排序数组

给你一个整数数组 `nums`，将 `nums` 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。

返回满足此条件的 **任一数组** 作为答案。

来源：力扣

https://leetcode.cn/problems/sort-array-by-parity/



思路：

​		定义变量`i`和`j`，分别为0和`nums.size()-1`，当满足`i<j`时，如果`nums[i]`为偶数，执行`i++`，如果`nums[j]`为奇数，执行`j--`。如果此时仍旧满足`i<j`，就交换`nums[i]`和`nums[j]`。