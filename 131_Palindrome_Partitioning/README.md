### 131.分割回文串

给你一个字符串 `s`，请你将 `s` 分割成一些子串，使每个子串都是 **回文串** 。返回 `s` 所有可能的分割方案。

**回文串** 是正着读和反着读都一样的字符串。

来源：力扣

https://leetcode.cn/problems/palindrome-partitioning/



思路：

​		采用回溯的思路来解题。

​		定义全局变量`path`，表示分割后的回文子串的单一收集结果，全局变量`pathTop`，记录`path`中子串的个数，全局变量`ans`，存储最终返回结果，全局变量`ansTop`，记录`ans`中元素个数（回文串个数），全局变量`ansSize`，记录`ans`中存储的每个回文子串的长度。

​		定义函数`isPalindrome`，用于判断字符串`str`是否为回文串，返回0表示不是回文子串，是回文串的话返回1。

​		定义函数`copy`，用于拷贝`path`中所有的回文子串到`ans`中。

​		定义函数`backtracking`，用于完成回溯算法。如果此时的`startIndex`大于字符串`str`的长度，就执行`copy`操作，然后`return`。否则，就定义变量`i`，从`startIndex`开始遍历，如果从`startIndex`到i之间的字符串是回文串，就进行字符串切割，将该串拷贝到`path`中，然后通过回溯继续向后判断：`backtracking(str, strlen, i+1)`。在遍历执行`i++`语句之前，将现在的子串弹出。



​		