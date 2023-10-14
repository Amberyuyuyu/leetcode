### 229.多数元素II

给定一个大小为 *n* 的整数数组，找出其中所有出现超过 `⌊ n/3 ⌋` 次的元素。

来源：力扣

https://leetcode.cn/problems/majority-element-ii/



思路：

​		定义`map`类型的变量`count`，用于存放`nums`中出现的数字以及它们出现的次数。

​		定义`vector<int>`类型的变量`ans`，遍历count，如果`it.second>nums.size()/3`，就将其加入`ans`中，最后返回`ans`即可。