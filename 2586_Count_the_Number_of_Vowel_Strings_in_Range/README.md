### 2586.统计范围内的元音字符串数

给你一个下标从 **0** 开始的字符串数组 `words` 和两个整数：`left` 和 `right` 。

如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 **元音字符串** ，其中元音字母是 `'a'`、`'e'`、`'i'`、`'o'`、`'u'` 。

返回 `words[i]` 是元音字符串的数目，其中 `i` 在闭区间 `[left, right]` 内。

来源：力扣

https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range/



思路：

​		定义一个如下的匿名函数：

```c
		auto check = [](char c) ->bool{
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    };
```

​		定义变量`ans`，用于统计元音字符串数目，初始化为0。

​		设置变量`i=left`，当i满足`i<=right`时，定义`w=words[i]`，每次都执行`ans += check(w[0]) && check(w[w.size()-1])`。