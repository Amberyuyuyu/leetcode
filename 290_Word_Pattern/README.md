### 290.单词规律

给定一种规律 `pattern` 和一个字符串 `s` ，判断 `s` 是否遵循相同的规律。

这里的 **遵循** 指完全匹配，例如， `pattern` 里的每个字母和字符串 `s` 中的每个非空单词之间存在着双向连接的对应规律。

来源：力扣

https://leetcode.cn/problems/word-pattern/



思路：

​		定义两个unordered_map类型的变量`p2s`和`s2p`，分别用于存放两者的对应关系。定义`n`和`m`分别为`pattern`和`s`的长度。定义字符`ch`和字符串`word`，分别表示遍历过程中当前`pattern`中的字符、`s`中的单词。定义`wordStart`和`wordEnd`，都初始化为0，用于在`s`中寻找单词。

​		定义变量i用于遍历`pattern`，如果`wordStart>=m`，直接返回`false`。当满足`wordEnd<m && s[wordEnd]!=' '`时，执行`wordEnd++`。然后根据`wordStart`和`wordEnd`来确定出`word`，`ch=pattern[i]`，如果`p2s.count(ch)&&p2s[ch]!=word`，直接返回`false`，如果满足`s2p.count(word)&&s2p[word]!=ch`，直接返回`false`。如果在map中不存在这对对应关系，就加入：

```c
	p2s[ch] = word;
  s2p[word] = ch;
	wordStart = wordEnd+1;
  wordEnd = wordStart;
```