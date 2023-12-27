### 349.两个数组的交集

给定两个数组 `nums1` 和 `nums2` ，返回 *它们的交集* 。输出结果中的每个元素一定是 **唯一** 的。我们可以 **不考虑输出结果的顺序** 。

来源：力扣

https://leetcode.cn/problems/intersection-of-two-arrays/



思路：

​		定义两个unordered_set类型的变量`s1`和`s2`，分别将`nums1`和`nums2`存入，定义数组`vRet`，遍历`s1`，如果`s2.find(e)!=s2.end()`，就执行`vRet.push_back(e)`。

​		