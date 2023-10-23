### 400.第N位数字

给你一个整数 `n` ，请你在无限的整数序列 `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...]` 中找出并返回第 `n` 位上的数字。

来源：力扣

https://leetcode.cn/problems/nth-digit/



思路：

​		将每一位称为数位，记为`n`，将10, 11, 12, ...称为数字，记为`num`，数字10是一个两位数，这个数字的位数位2，记为`digit`，每`digit`位数的起始数字，记为`start`。各`digit`下的数位数量`count`的计算公式为：`count = 9 * start * digit`。初始化：`digit=1`, `start = 1`, `count = 9`。当满足`n>count`时，每一次都执行：`n -= count`，`start *= 10`，`digit += 1`，`count = digit*start*9`。

​		最终数字为`num = start+(n-1)/digit`，将其转换为字符串`s`，最终位数为`res = s[(n-1)%digit]-'0'`。		