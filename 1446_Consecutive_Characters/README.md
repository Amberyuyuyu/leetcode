### 1446.连续字符

给你一个字符串 `s` ，字符串的**「能量」**定义为：只包含一种字符的最长非空子字符串的长度。

请你返回字符串 `s` 的 **能量**。

来源：力扣

https://leetcode.cn/problems/consecutive-characters/



思路：

​		定义变量`chCount`和`maxCount`，分别表示当前字符的连续出现次数以及到目前为止，只包含一种字符的最长非空字符串的长度，都初始化为1。

​		定义变量`i=1`，用于遍历字符串，如果`s[i]==s[i-1]`，执行`++chCount`，否则的话，设置`chCount=1`，比较`chCount`和`maxCount`的大小关系，大的重新赋值给`maxCount`。