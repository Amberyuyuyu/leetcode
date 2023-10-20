### 412.Fizz Buzz

给你一个整数 `n` ，找出从 `1` 到 `n` 各个整数的 Fizz Buzz 表示，并用字符串数组 `answer`（**下标从 1 开始**）返回结果，其中：

- `answer[i] == "FizzBuzz"` 如果 `i` 同时是 `3` 和 `5` 的倍数。
- `answer[i] == "Fizz"` 如果 `i` 是 `3` 的倍数。
- `answer[i] == "Buzz"` 如果 `i` 是 `5` 的倍数。
- `answer[i] == i` （以字符串形式）如果上述条件全不满足。



来源：力扣

https://leetcode.cn/problems/fizz-buzz/



思路：

​		定义数组`res`，用于存放转换后的结果。

​		定义`i=1`，遍历1～`n`之间的所有整数，如果满足`i%3==0&&i%5==0`，就在`res`中加入`"FizzBuzz"`，然后执行`continue`，如果只存在`i%3==0`，`i%5!=0`，就在`res`中加入`"Fizz"`，执行`continue`，如果`i`不是3的倍数，是5的倍数，就在`res`中加入`"Buzz"`，执行`continue`，如果上述几种情况都不满足，就在`res`中加入`to_string(i)`。