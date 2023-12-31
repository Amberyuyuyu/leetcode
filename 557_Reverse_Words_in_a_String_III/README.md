### 557.反转字符串中的单词

给定一个字符串 `s` ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

来源：力扣

https://leetcode.cn/problems/reverse-words-in-a-string-iii/



思路：

​			定义两个变量`start`和`pos`，分别表示单词的起始位置和结束位置后的空格。都初始化为0。当满足`start<s.length()`时，`pos=s.find(' ', start)`，如果`pos==-1`，说明此时已经是最后一个单词了，设置`pos=s.size()`，对这个单词进行反转：`std::reverse(s.begin()+start, s.begin()+pos)`。然后将`start`设置为`pos+1`，表示下一个单词的开头。