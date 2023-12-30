### 1704.判断字符串的两半是否相似

给你一个偶数长度的字符串 `s` 。将其拆分成长度相同的两半，前一半为 `a` ，后一半为 `b` 。

两个字符串 **相似** 的前提是它们都含有相同数目的元音（`'a'`，`'e'`，`'i'`，`'o'`，`'u'`，`'A'`，`'E'`，`'I'`，`'O'`，`'U'`）。注意，`s` 可能同时含有大写和小写字母。

如果 `a` 和 `b` 相似，返回 `true` ；否则，返回 `false` 。

来源：力扣

https://leetcode.cn/problems/determine-if-string-halves-are-alike/



思路：

​		定义函数`is_a_vowel`，判断某个字符是否为大写的或小写的元音字母。

​		定义`left_cnt`和`right_cnt`，都初始化为0，分别统计左右两边的元音字母个数。定义变量`i`和`j`，分别初始化为0和`s.length()-1`，用于遍历整个数组，`left_cnt+=is_a_vowel(s[i])`，`right_cnt += is_a_vowel(s[j])`。

​		最终返回值为`left_cnt==right_cnt`。