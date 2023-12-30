### 316.去除重复字母

给你一个字符串 `s` ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 **返回结果的字典序最小**（要求不能打乱其他字符的相对位置）。

来源：力扣

https://leetcode.cn/problems/remove-duplicate-letters/



思路：

​		定义数组`left(26)`，表示`s`中所有字母出现次数，`'a'`对应0，以此类推。定义`in_ans(26)`数组，元素为布尔类型，用于表示在最终结果的字符串`ans`中，对应元素是否出现过，'a'对应0，以此类推。定义字符串`ans`，用于存放最终结果。

​		第一次遍历`s`，完成`left`数组的初始化。

​		第二次遍历`s`，遇到`c`时，执行`left[c-'a']--`，如果c在`in_ans`中出现过，直接`continue`即可。如果`c`不在`ans`中，需要判断`ans`是否为空，在`ans`不为空且`c`小于`ans.back()`且`left[ans.back()-'a']`存在时，将`ans`的最后一个元素删除，并在`in_ans`中进行修改：`in_ans[ans.back()-'a'] = false`。将`c`加入到`ans`末尾，并将`in_ans[c-'a']`改为`true`。