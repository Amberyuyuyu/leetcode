### 389.找不同

给定两个字符串 `s` 和 `t` ，它们只包含小写字母。

字符串 `t` 由字符串 `s` 随机重排，然后在随机位置添加一个字母。

请找出在 `t` 中被添加的字母。

来源：力扣

https://leetcode.cn/problems/find-the-difference/



思路：

​		将字符串s和t都进行升序排列，遍历字符串`s`，如果遇到`s[i]!=t[i]`，直接返回`t[i]`即可。如果可以遍历到`s`结束，说明多出来的字符为`t[t.size()-1]`。