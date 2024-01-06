### 1657.确定两个字符串是否接近

如果可以使用以下操作从一个字符串得到另一个字符串，则认为两个字符串 接近 ：

操作 1：交换任意两个 现有 字符。
例如，abcde -> aecdb
操作 2：将一个 现有 字符的每次出现转换为另一个 现有 字符，并对另一个字符执行相同的操作。
例如，aacabb -> bbcbaa（所有 a 转化为 b ，而所有的 b 转换为 a ）
你可以根据需要对任意一个字符串多次使用这两种操作。

给你两个字符串，word1 和 word2 。如果 word1 和 word2 接近 ，就返回 true ；否则，返回 false 。

来源：力扣

https://leetcode.cn/problems/determine-if-two-strings-are-close/



思路：

​		定义`len1`和`len2`分别为两个单词的长度，如果`len1!=len2`，直接返回`false`即可。

​		定义`s_mask`和`t_mask`，都初始化为0，通过比特位来标记是否出现过`c`元素（`c-'a'`位上是1表示出现过元素`c`）。同时定义数组`s_cnt(26)`和数组`t_cnt(26)`，用于统计两个单词中每个字符出现的次数。对`s_cnt`和`t_cnt`进行升序排列，如果`s_mask==t_mask&&s_cnt==t_cnt`，说明两个字符串接近。