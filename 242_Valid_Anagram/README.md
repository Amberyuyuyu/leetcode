### 242.有效的字母异位词

给定两个字符串 `*s*` 和 `*t*` ，编写一个函数来判断 `*t*` 是否是 `*s*` 的字母异位词。

**注意：**若 `*s*` 和 `*t*` 中每个字符出现的次数都相同，则称 `*s*` 和 `*t*` 互为字母异位词。

来源：力扣

https://leetcode.cn/problems/valid-anagram/



来源：力扣

https://leetcode.cn/problems/valid-anagram/



思路：

​		如果两个字符串的长度不一致，直接返回`false`即可。定义一个unordered_map类型的变量`dic`，遍历s中所有字符，执行`dic[c]+=1`，再遍历一次`t`中所有字符，每次都执行`dit[c]-=1`。

​		最后遍历一次`dic`，如果`kv.second!=0`，说明出现了字母，`s`和`t`中数量不一致直接返回`false`即可。

​		