### 4.寻找两个正序数组的中位数

给定两个大小分别为 `m` 和 `n` 的正序（从小到大）数组 `nums1` 和 `nums2`。请你找出并返回这两个正序数组的 **中位数** 。

算法的时间复杂度应该为 `O(log (m+n))` 。

来源：力扣

https://leetcode.cn/problems/median-of-two-sorted-arrays/



思路：

​		首先，定义函数`mergeTwo`，按照升序合并两个数组。

​		定义变量`index=(nums1Size+nums2Size)/2`，如果`nums1Size+nums2Size`为偶数，最终返回结果为`(double)(arr[index]+arr[index-1])/2`，否则，返回`(double)arr[index]`。