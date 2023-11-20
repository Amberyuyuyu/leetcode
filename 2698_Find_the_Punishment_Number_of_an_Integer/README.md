### 2698.求一个整数的惩罚数

给你一个正整数 `n` ，请你返回 `n` 的 **惩罚数** 。

`n` 的 **惩罚数** 定义为所有满足以下条件 `i` 的数的平方和：

- `1 <= i <= n`
- `i * i` 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 `i` 。

来源：力扣

https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/



思路：

​		定义函数`check`，用于判断当前数字是否合法，有四个输入参数：`num`是要检查的数字，`s`是`num`的平方的字符串表示，`stringIndex`是当前考虑的`s`中的字符串的位置，`sum`表示到目前为止从`s`中提取的数字的和。首先判断`stringIndex`是否等于`s.lengh()`，如果此时已经遍历结束，就返回`sum==num`的结果即可。定义`currentNum`，初始化为0，用于表示当前数字的数位和。遍历从`stringIndex`开始，最大不超过`s.length()`，`currentNum=currentNum*10+(s[i]-'0')`，如果此时`currentNum+sum>num`，直接返回`false`，如果`check(num,s,i+1,currentNum+sum)`的结果为`true`，就返回`true`。

​	在原函数中定义`result=0`，用于存放最后结果。`i`从1到n进行取值，定义`square=i*i`，如果满足`check(i,squareStr,0,0)`为`true`，就执行`result+=square`。

​	最终返回`result`即可。

​		