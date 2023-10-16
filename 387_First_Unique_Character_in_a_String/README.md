### 387.字符串中的第一个唯一字符

给定一个字符串 `s` ，找到 *它的第一个不重复的字符，并返回它的索引* 。如果不存在，则返回 `-1` 。

来源：力扣

https://leetcode.cn/problems/first-unique-character-in-a-string/



思路：

​		定义`unordered_map`类型的变量`dic`，用于存放`s`中的字符以及是否重复出现。

​		遍历字符串`s`，`dic[c]=dic.find(c)==dic.end()`，表示如果字符`c`从未出现过，就标记为真。

​		再次遍历字符串，如果`dic[s[i]]`，就返回`i`。

​		如果`dic[s[i]]`全部为假，就返回-1。