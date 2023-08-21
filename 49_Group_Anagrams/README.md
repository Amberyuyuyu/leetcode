### 49.字母异位词分组

给你一个字符串数组，请你将 **字母异位词** 组合在一起。可以按任意顺序返回结果列表。

**字母异位词** 是由重新排列源单词的所有字母得到的一个新单词。

来源：力扣

https://leetcode.cn/problems/group-anagrams/



思路：

​		定义一个字典`table`，键为数组`strs`中出现的字符串正序结果`s`，`value`为`strs`中出现过的`s`的所有排序情况。

​	对于`strs`中的每一个`str`，`s="".join(sorted(str))`，如果`s`在`table.keys()`中，就在对应的`value`中加入`s`：`table[s].append(str)`，如果不存在于`table`中，就在`table`中加入这个键值对：`table[s]=str`。

​		最终的结果是所有字母异位词组合在一起的返回值列表，因此最后返回的是`list(table.values())`。