### 5.最长回子串

给你一个字符串 `s`，找到 `s` 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

来源：力扣

https://leetcode.cn/problems/longest-palindromic-substring/



思路：

​		动态规划的思路解题。

​		定义`len=s.size()`，如果`len`<2，直接返回`s`即可。

​		定义`dp`数组，维度为`len*len`，所有元素都初始化为`false`。所有对角线上的元素都设置为`true`。

​		定义变量`maxLen`，`begin`，都初始化为0，分别表示回文串的最大长度，以及开始位置。

​		定义变量`i`，初始化为`len-1`，定义变量`j`，初始化为`i`，如果`s[i]==s[j]`，作如下判断：如果`j-i<=1`，将`dp[i][j]`设置为`true`，不满足上述条件但`dp[i+1][j-1]`为`true`（内侧为`true`），就将`dp[i][j]`设置为`true`。如果`dp[i][j]`为真并且`j-i+1>maxLen`，就替换现有的`maxLen`，并将`begin`设置为`i`。

​		最后定义字符串`ret=s.substr(begin,maxLen)`，返回`ret`即可。