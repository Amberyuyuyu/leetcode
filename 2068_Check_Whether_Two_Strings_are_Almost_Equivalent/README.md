### 2068.检查两个字符串是否几乎相等

如果两个字符串 `word1` 和 `word2` 中从 `'a'` 到 `'z'` 每一个字母出现频率之差都 **不超过** `3` ，那么我们称这两个字符串 `word1` 和 `word2` **几乎相等** 。

给你两个长度都为 `n` 的字符串 `word1` 和 `word2` ，如果 `word1` 和 `word2` **几乎相等** ，请你返回 `true` ，否则返回 `false` 。

一个字母 `x` 的出现 **频率** 指的是它在字符串中出现的次数。

来源：力扣

https://leetcode.cn/problems/check-whether-two-strings-are-almost-equivalent/



思路：

​		定义数组`hash`，长度为26，分别对应26个英文字母。遍历两个字符串，每次都执行`hash[word1[i]-'a']++`和`hash[word2[i]-'a']--`。

​		遍历整个`hash`数组，如果`abs(hash[i])>3`，直接返回`false`。