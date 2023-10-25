### 859.亲密字符串

给你两个字符串 `s` 和 `goal` ，只要我们可以通过交换 `s` 中的两个字母得到与 `goal` 相等的结果，就返回 `true` ；否则返回 `false` 。

交换字母的定义是：取两个下标 `i` 和 `j` （下标从 `0` 开始）且满足 `i != j` ，接着交换 `s[i]` 和 `s[j]` 处的字符。

- 例如，在 `"abcd"` 中交换下标 `0` 和下标 `2` 的元素可以生成 `"cbad"` 。

来源：力扣

https://leetcode.cn/problems/buddy-strings/



思路：

​		定义变量`cnt`，初始化为0，用于统计两个字符串中不同的数字。如果两字符串长度不相等，直接返回`false`即可。定义`diff1 = -1`，`diff2 = -1`，用于标记要交换的两个字符的位置。定义数组`chars`，长度为26，用于标记`s`中每个字符出现的次数，如果两个字符完全相同，但是`s`中相同数字超过2，也可以完成两次交换，设置变量`valid_no_diff`用于标记这个值。遍历字符串`s`，如果`s[i]!=goal[i]`，执行`cnt++`，如果`cnt`>2，就返回`false`。如果`cnt==1`，就将`diff1`设置为`i`，如果`cnt==2`，就将`diff2`设置为`i`，执行`chars[s[i]-'a']++`，如果`chars[s[i]-'a']>=2`，就设置`valid_no_diff=true`。

​		遍历完字符串以后，如果满足`cnt==0&&valid_no_diff`，就返回`true`。

​		如果`cnt==2&&s[diff1]==goal[diff2]&&s[diff2]==goal[diff1]`，就返回`true`。

​		不满足以上两种情况，就返回`false`。